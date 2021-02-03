#include "Enemy.h"

CEnemy::CEnemy()
{
}

CEnemy::~CEnemy()
{
}

bool CEnemy::Initialize(void)
{
	if (!m_EnemyTexture.Load("Enemyufo.png"))
	{
		return false;
	}
	m_Position = CVector2(CGraphicsUtilities::GetGraphics()->GetTargetWidth() * 0.5f - m_EnemyTexture.GetWidth() * 0.5f, 0);
	for (int i = 0; i < 5; i++)
	{
		m_OldPos[i] = m_Position;
	}
	m_bShow = true;
	m_MoveEnd = true;
	m_AfterimageInterval = AFTERIMAGE_INTERVAL;
	m_TeleportInterval = 0.0f;

	return true;
}

void CEnemy::Update(void)
{
	if (m_TeleportInterval >= 1.0f)
	{
		m_MoveEnd = true;
	}

	m_AfterimageInterval--;
	if (m_AfterimageInterval <= 0)
	{
		for (int i = 0; i < 5; i++)
		{
			m_OldPos[i] = m_OldPos[i + 1];
		}
		m_OldPos[4] = m_Position;
		m_AfterimageInterval = AFTERIMAGE_INTERVAL;
	}

	switch (m_Type)
	{
	case TYPE_TELEPORT:
		if (m_TeleportInterval == 0.0f)
		{
			m_Position = CVector2(m_MovePos.x - GetRectangle().GetWidth()*0.5f, m_MovePos.y - GetRectangle().GetHeight()*0.5f);
		}
		m_TeleportInterval += CUtilities::GetFrameSecond();
		break;
	case TYPE_MOVE:
		UpdateMove();
		break;
	}
	
}

void CEnemy::Render(void)
{
	for (int i = 0; i < 5; i++)
	{
		m_EnemyTexture.Render(m_OldPos[i].x, m_OldPos[i].y, MOF_ARGB(40 * (i + 1), 255, 255, 255));
	}
	m_EnemyTexture.Render(m_Position.x, m_Position.y);
	
	CGraphicsUtilities::RenderCircle(GetCircle(), MOF_COLOR_CWHITE);
}

void CEnemy::Release(void)
{
	m_EnemyTexture.Release();
}

void CEnemy::UpdateMove(void)
{
	CVector2 dvec = m_MovePos - GetCenterPos();
	float d = dvec.Length();
	if (d <= m_MoveSpeed.x || d <= m_MoveSpeed.y)
	{
		m_Position = CVector2(m_MovePos.x - GetRectangle().GetWidth()*0.5f, m_MovePos.y - GetRectangle().GetHeight()*0.5f);
		m_MoveEnd = true;
		return;
	}
	dvec.x /= d;
	dvec.y /= d;
	m_Position += dvec * m_MoveSpeed;
}


void CEnemy::SetMoveParameter(CVector2 mPos, int type, CVector2 speed)
{
	m_MovePos = mPos;
	m_MoveSpeed = speed;
	if (type == TYPE_ALL)
	{
		CUtilities::Random(TYPE_ALL);
	}
	else
	{
		m_Type = type;
	}

	m_TeleportInterval = 0.0f;
	m_MoveEnd = false;
}

CRectangle CEnemy::GetRectangle(void)
{
	return CRectangle(m_Position.x,m_Position.y, m_Position.x + m_EnemyTexture.GetWidth(),m_Position.y + m_EnemyTexture.GetHeight());
}

CCircle CEnemy::GetCircle(void)
{
	return CCircle(GetCenterPos(), GetRectangle().GetWidth() * 0.5f);
}

Vector2 CEnemy::GetCenterPos(void)
{
	return GetRectangle().GetCenter();
}

bool CEnemy::IsShow(void)
{
	return m_bShow;
}

bool CEnemy::IsMoveEnd(void)
{
	return m_MoveEnd;
}
