#include	"Player.h"

//一時的に
#define		MOVESPEED	10

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Load()
{
	Texture.Load("UI/ゲーム本編/飛行機.png");
	BulletTexture[Triangle].Load("UI/ゲーム本編/三角.png");
	BulletTexture[Square].Load("UI/ゲーム本編/四角.png");
}

void CPlayer::Initialize()
{
	position = CVector2((g_pGraphics->GetTargetWidth() - (Texture.GetWidth() * 0.25f)) * 0.5f,
		g_pGraphics->GetTargetHeight() - (Texture.GetHeight() * 0.25f));
	CollisionRadius = Texture.GetWidth() * 0.1;
	CollisionPosCorrection = CVector2(Texture.GetWidth() * 0.125f, Texture.GetHeight() * 0.125f);
	Collision = CCircle(position + CollisionPosCorrection, CollisionRadius);
	BulletBuffer = Empty;
	BulletRotate = Up;
}

void CPlayer::Update()
{
	if (g_pInput->IsKeyHold(MOFKEY_LEFT))
	{
		position.x -= MOVESPEED;
		if (position.x <= 0) 
		{ 
			position.x = 0; 
		}
	}
	else if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
	{
		position.x += MOVESPEED;
		if (position.x + (Texture.GetHeight() * 0.25f) >= g_pGraphics->GetTargetWidth())
		{
			position.x = g_pGraphics->GetTargetWidth() - (Texture.GetHeight() * 0.25f);
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_SPACE) && BulletBuffer != Empty)
	{
		
		ShotBullet(BulletBuffer);

	}
	if (BulletBuffer < Empty)
	{
		if (g_pInput->IsKeyPull(MOFKEY_W))
		{
			BulletRotate = Up;
		}
		else if (g_pInput->IsKeyPull(MOFKEY_D))
		{
			BulletRotate = Right;
		}
		else if (g_pInput->IsKeyPull(MOFKEY_S))
		{
			BulletRotate = Down;
		}
		else if (g_pInput->IsKeyPull(MOFKEY_A))
		{
			BulletRotate = Left;
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD7))
	{
		BulletBuffer = Triangle;
	}
	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD8))
	{
		BulletBuffer = Square;
	}

	if (Bullets.GetArrayCount() >= 1)
	{
		for (int i = 0; i < Bullets.GetArrayCount(); i++)
		{
			Bullets[i].Update();
		}

		for (int i = Bullets.GetArrayCount() - 1; i >= 0; i--)
		{
			if (Bullets[i].GetShow())
			{
				continue;
			}
			Bullets.Delete(i);
		}
	}

	Collision = CCircle(position + CollisionPosCorrection, CollisionRadius);
}

void CPlayer::ShotBullet(int bullettype)
{
	CBullet A;
	A.Create(&BulletTexture[bullettype],
		position.x + (Texture.GetWidth() * 0.125), 
		position.y - BulletTexture[bullettype].GetHeight() * 0.5, bullettype, BulletRotate);
	Bullets.Add(A);

	BulletBuffer = Empty;
	BulletRotate = Up;
}


void CPlayer::Render()
{
	Texture.RenderScale(position.x , position.y , 0.25f);

	for (int i = 0; i < Bullets.GetArrayCount(); i++)
	{
		if (!Bullets[i].GetShow()) { continue; }
		Bullets[i].Render();
	}
}

void CPlayer::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 100, MOF_COLOR_GREEN, "プレイヤ座標　　X %1f : Y %2f", position.x, position.y);
	CGraphicsUtilities::RenderString(0, 150, MOF_COLOR_GREEN, "保持弾種：%s",
		BulletBuffer == Triangle ? "三角" : BulletBuffer == Square ? "四角" : "空");
	CGraphicsUtilities::RenderString(0, 200, MOF_COLOR_GREEN,"回転情報：%s",
		BulletRotate == Up ? "上" : BulletRotate == Right ? "右" : BulletRotate == Down ? "下" : "左");
	CGraphicsUtilities::RenderString(0, 250, MOF_COLOR_GREEN,"現在存在する弾数：%d", Bullets.GetArrayCount());

	for (int i = 0; i < Bullets.GetArrayCount(); i++)
	{
		Bullets[i].RenderDebug(i);
	}
	
	CGraphicsUtilities::RenderCircle(Collision , MOF_COLOR_GREEN);
}

void CPlayer::Release()
{
	Texture.Release();
}