#include	"Player.h"

//�ꎞ�I��
constexpr auto MOVESPEED = 10;

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Load()
{
	Texture.Load("UI/�Q�[���{��/��s�@.png");
	BulletTexture[Triangle].Load("UI/�Q�[���{��/�O�p.png");
	BulletTexture[Square].Load("UI/�Q�[���{��/�l�p.png");
}

void CPlayer::Initialize()
{
	position = CVector2((g_pGraphics->GetTargetWidth() - (Texture.GetWidth() * 0.5f)) * 0.5f,
		g_pGraphics->GetTargetHeight() - (Texture.GetHeight()* 0.6f));
	CollisionRadius = Texture.GetWidth() * 0.1;
	CollisionPosCorrection = CVector2(Texture.GetWidth() * 0.25f, Texture.GetHeight() * 0.25f);
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
		if (position.x + (Texture.GetHeight() * 0.5f) >= g_pGraphics->GetTargetWidth())
		{
			position.x = g_pGraphics->GetTargetWidth() - (Texture.GetHeight() * 0.5f);
		}
	}

	if (g_pInput->IsKeyPush(MOFKEY_SPACE) && BulletBuffer != Empty)
	{
		
		ShotBullet(BulletBuffer);
	}
	if (BulletBuffer < Empty)
	{
		if (g_pInput->IsKeyPush(MOFKEY_LSHIFT) ||
			g_pInput->IsKeyPush(MOFKEY_RSHIFT))
		{
			BulletRotate++;
			if (BulletRotate >= 4)
			{
				BulletRotate = 0;
			}
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
			//Panel.Update(Bullets[i].GetBulletRect[0], Bullets[i].GetXPos(), Bullets[i].GetBulletType());
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
		position.x + (Texture.GetWidth() * 0.25), 
		position.y - BulletTexture[bullettype].GetHeight() * 0.5, bullettype, BulletRotate);
	Bullets.Add(A);

	BulletBuffer = Empty;
	BulletRotate = Up;
}


void CPlayer::Render()
{
	Texture.RenderScale(position.x , position.y , 0.5f);

	for (int i = 0; i < Bullets.GetArrayCount(); i++)
	{
		if (!Bullets[i].GetShow()) { continue; }
		Bullets[i].Render();
	}

    //! ikoutyuu
	if (BulletBuffer != Empty)
	{
	}
}

void CPlayer::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 100, MOF_COLOR_GREEN, "�v���C�����W�@�@X %1f : Y %2f", position.x, position.y);
	CGraphicsUtilities::RenderString(0, 150, MOF_COLOR_GREEN, "�ێ��e��F%s",
		BulletBuffer == Triangle ? "�O�p" : BulletBuffer == Square ? "�l�p" : "��");
	CGraphicsUtilities::RenderString(0, 200, MOF_COLOR_GREEN,"��]���F%s",
		BulletRotate == Up ? "��" : BulletRotate == Right ? "�E" : BulletRotate == Down ? "��" : "��");
	CGraphicsUtilities::RenderString(0, 250, MOF_COLOR_GREEN, "���ݑ��݂���e���F%d", Bullets.GetArrayCount());
	
	for (int i = 0; i < Bullets.GetArrayCount(); i++)
	{
		Bullets[i].RenderDebug(i);
	}
	CGraphicsUtilities::RenderCircle(Collision , MOF_COLOR_GREEN);
}

void CPlayer::Release()
{
	Texture.Release();
	for (int i = 0; i < BULLET_CATEGORY; i++)
	{
		BulletTexture[i].Release();
	}
}