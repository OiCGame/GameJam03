#include	"Player.h"

//�ꎞ�I��
#define		MOVESPEED	10

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Load()
{
	PlayerTexture.Load("UI/�Q�[���{��/��s�@.png");
}

void CPlayer::Initialize()
{
	PlayerPosition = CVector2((g_pGraphics->GetTargetWidth() - (PlayerTexture.GetWidth() * 0.25f)) * 0.5f,
		g_pGraphics->GetTargetHeight() - (PlayerTexture.GetHeight() * 0.25f));
	PlayerCollisionRadius = PlayerTexture.GetWidth() * 0.1;
	PlayerCollisionPosCorrection = CVector2(PlayerTexture.GetWidth() * 0.125f, PlayerTexture.GetHeight() * 0.125f);
	PlayerCollision = CCircle(PlayerPosition + PlayerCollisionPosCorrection, PlayerCollisionRadius);
}

void CPlayer::Update()
{
	if (g_pInput->IsKeyHold(MOFKEY_LEFT))
	{
		PlayerPosition.x -= MOVESPEED;
		if (PlayerPosition.x <= 0) { PlayerPosition.x = 0; }
	}
	else if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
	{
		PlayerPosition.x += MOVESPEED;
		if (PlayerPosition.x + (PlayerTexture.GetHeight() * 0.25f) >= g_pGraphics->GetTargetWidth())
		{
			PlayerPosition.x = g_pGraphics->GetTargetWidth() - (PlayerTexture.GetHeight() * 0.25f);
		}
	}

	if (g_pInput->IsKeyPull(MOFKEY_SPACE))
	{
		//���ˏ�����������
	}

	PlayerCollision = CCircle(PlayerPosition + PlayerCollisionPosCorrection, PlayerCollisionRadius);
}

void CPlayer::Render()
{
	PlayerTexture.RenderScale(PlayerPosition.x , PlayerPosition.y , 0.25f);
}

void CPlayer::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 100, "�v���C�����W�@�@X%1f : Y%2f", PlayerPosition.x, PlayerPosition.y);
	CGraphicsUtilities::RenderCircle(PlayerCollision , MOF_COLOR_GREEN);
}

void CPlayer::Release()
{
	PlayerTexture.Release();
}
