#include	"Player.h"

//一時的に
constexpr auto MOVESPEED = 10;

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
	BulletUITexture[Triangle].Load("UI/ゲーム本編/ミニ三角ブロック.png");
	BulletUITexture[Square].Load("UI/ゲーム本編/ミニ四角ブロック.png");
	UIFrameTexture.Load("UI/ゲーム本編/アイテム枠_空白.png");
}

void CPlayer::Initialize()
{
	Panel.Initialize(0);
	position = CVector2((g_pGraphics->GetTargetWidth() - (Texture.GetWidth() * 0.25f)) * 0.5f,
		g_pGraphics->GetTargetHeight() - (Texture.GetHeight() * 0.25f));
	CollisionRadius = Texture.GetWidth() * 0.1;
	CollisionPosCorrection = CVector2(Texture.GetWidth() * 0.125f, Texture.GetHeight() * 0.125f);
	Collision = CCircle(position + CollisionPosCorrection, CollisionRadius);
	BulletBuffer = Empty;
	BulletRotate = Up;

	BulletUIPosition = CVector2(g_pGraphics->GetTargetWidth() * 0.5f, 0);
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
		if (g_pInput->IsKeyPush(MOFKEY_W))
		{
			BulletRotate = Up;
		}
		else if (g_pInput->IsKeyPush(MOFKEY_D))
		{
			BulletRotate = Right;
		}
		else if (g_pInput->IsKeyPush(MOFKEY_S))
		{
			BulletRotate = Down;
		}
		else if (g_pInput->IsKeyPush(MOFKEY_A))
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
			Panel.Update(Bullets[i].GetBulletRect[0], Bullets[i].GetXPos(), Bullets[i].GetBulletType());
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
	Panel.Render();
	Texture.RenderScale(position.x , position.y , 0.25f);

	for (int i = 0; i < Bullets.GetArrayCount(); i++)
	{
		if (!Bullets[i].GetShow()) { continue; }
		Bullets[i].Render();
	}

	UIFrameTexture.Render(BulletUIPosition.x , BulletUIPosition.y);
	if (BulletBuffer != Empty)
	{
		BulletUITexture[BulletBuffer].RenderRotate(BulletUIPosition.x + (UIFrameTexture.GetWidth() * 0.5),
			BulletUIPosition.y + (UIFrameTexture.GetHeight() * 0.5), 
			MOF_ToRadian(90 * BulletRotate), TEXTUREALIGNMENT_CENTERCENTER);
	}
}

void CPlayer::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 100, MOF_COLOR_GREEN, "プレイヤ座標　　X %1f : Y %2f", position.x, position.y);
	CGraphicsUtilities::RenderString(0, 150, MOF_COLOR_GREEN, "保持弾種：%s",
		BulletBuffer == Triangle ? "三角" : BulletBuffer == Square ? "四角" : "空");
	CGraphicsUtilities::RenderString(0, 200, MOF_COLOR_GREEN,"回転情報：%s",
		BulletRotate == Up ? "上" : BulletRotate == Right ? "右" : BulletRotate == Down ? "下" : "左");
	CGraphicsUtilities::RenderString(0, 250, MOF_COLOR_GREEN, "現在存在する弾数：%d", Bullets.GetArrayCount());
	CGraphicsUtilities::RenderString(500, 0, MOF_COLOR_GREEN,"アイテムUI座標 %1f %2f", BulletUIPosition.x, BulletUIPosition.y);

	for (int i = 0; i < Bullets.GetArrayCount(); i++)
	{
		Bullets[i].RenderDebug(i);
	}
	Panel.RenderDebug();
	CGraphicsUtilities::RenderCircle(Collision , MOF_COLOR_GREEN);
}

void CPlayer::Release()
{
	Panel.Release();
	Texture.Release();
	for (int i = 0; i < BULLET_CATEGORY; i++)
	{
		BulletTexture[i].Release();
		BulletUITexture[i].Release();
	}
	BulletUITexture[BULLET_CATEGORY].Release();
}