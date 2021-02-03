#include "Bullet.h"

void CBullet::Initialize(const CVector2 & position, const CVector2 & vector, const float & wait)
{
	m_Body.SetValue(
		position.x,
		position.y,
		5
	);
	m_Vector = vector;
	m_WaitTime = wait;
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
	CGraphicsUtilities::RenderCircle(m_Body, MOF_COLOR_WHITE);
}
