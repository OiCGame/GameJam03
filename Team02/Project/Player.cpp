#include	"Player.h"

//ˆêŽž“I‚É
constexpr auto MOVESPEED = 10;

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Load()
{
	Texture.Load("UI/ƒQ[ƒ€–{•Ò/”òs‹@.png");
	BulletTexture[Triangle].Load("UI/ƒQ[ƒ€–{•Ò/ŽOŠp.png");
	BulletTexture[Square].Load("UI/ƒQ[ƒ€–{•Ò/ŽlŠp.png");
	BulletUITexture[Triangle].Load("UI/ƒQ[ƒ€–{•Ò/ƒAƒCƒeƒ€˜g_ŽOŠp.png");
	BulletUITexture[Square].Load("UI/ƒQ[ƒ€–{•Ò/ƒAƒCƒeƒ€˜g_ŽlŠp.png");
	BulletUITexture[Empty].Load("UI/ƒQ[ƒ€–{•Ò/ƒAƒCƒeƒ€˜g_‹ó”’.png");
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

	BulletUIPosition = CVector2(g_pGraphics->GetTargetWidth()*0.5, 0);
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

	BulletUITexture[BulletBuffer].Render(BulletUIPosition.x , BulletUIPosition.y);
}

void CPlayer::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 100, MOF_COLOR_GREEN, "ƒvƒŒƒCƒ„À•W@@X %1f : Y %2f", position.x, position.y);
	CGraphicsUtilities::RenderString(0, 150, MOF_COLOR_GREEN, "•ÛŽ’eŽíF%s",
		BulletBuffer == Triangle ? "ŽOŠp" : BulletBuffer == Square ? "ŽlŠp" : "‹ó");
	CGraphicsUtilities::RenderString(0, 200, MOF_COLOR_GREEN,"‰ñ“]î•ñF%s",
		BulletRotate == Up ? "ã" : BulletRotate == Right ? "‰E" : BulletRotate == Down ? "‰º" : "¶");
	CGraphicsUtilities::RenderString(0, 250, MOF_COLOR_GREEN,"Œ»Ý‘¶Ý‚·‚é’e”F%d", Bullets.GetArrayCount());

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