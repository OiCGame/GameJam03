#include "Bullet.h"

bool CBullet::CollisionCircle(const CCircle & circle)
{
	return m_Body.CollisionCircle(circle);
}

void CBullet::Initialize(const CVector2 & position, const CVector2 & vector, const float & wait, const BulletType& type)
{
	m_Body.SetValue(
		position.x,
		position.y,
		c_radius
	);
	m_Vector = vector;
	m_WaitTime = wait;
	// テクスチャー設定
	switch (type)
	{
	case	BulletType::red:
		break;
	case	BulletType::purple:
		break;
	case	BulletType::yellow:
		break;
	case	BulletType::orange:
		break;
	default:
		break;
	}
}

void CBullet::Update()
{
	m_Stopwatch += CUtilities::GetFrameSecond();
	if (!m_ShowFlag && m_Stopwatch >= m_WaitTime) {
		m_ShowFlag = true;
	}
	if (!m_ShowFlag) { return; }
	m_Body.x += m_Vector.x;
	m_Body.y += m_Vector.y;
}

bool CBullet::IsShow()
{
	return m_ShowFlag;
}

bool CBullet::IsSurvival()
{
	if (m_Body.x < 0 || g_pGraphics->GetTargetWidth() < m_Body.x) {
		return false;
	}
	if (m_Body.y < 0 || g_pGraphics->GetTargetHeight() < m_Body.y) {
		return false;
	}
	return true;
}

void CBullet::Render()
{
	if (!m_ShowFlag) { return; }
	if (!m_pTexture) {
		CGraphicsUtilities::RenderFillCircle(m_Body, MOF_COLOR_WHITE);
	}
	else {
		m_pTexture->Render(
			m_Body.Position.x - m_pTexture->GetWidth() * 0.5f,
			m_Body.Position.y - m_pTexture->GetHeight() *0.5f
		);
	}
}
