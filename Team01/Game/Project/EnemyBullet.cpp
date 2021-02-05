#include "EnemyBullet.h"

CEnemyBullet::CEnemyBullet() :
	m_Pos(0.0f, 0.0f),
	m_Move(0.0f, 0.0f),
	m_Radius(6.0f),
	m_Speed(3.0f),
	m_Dir(0.0f),
	m_ReflectionCount(2),
	m_PopDirCnt(8),
	m_PopLen(0),
	m_PopRad(4),
	m_bDraw(false) {
}

CEnemyBullet::~CEnemyBullet() {

}

void CEnemyBullet::Initialize(float dir, int reflect) {
	m_Dir = dir;
	m_ReflectionNo = reflect;
}

void CEnemyBullet::Generation(Vector2 pos) {
	m_bDraw = true;
	m_Pos = pos;
}

void CEnemyBullet::Update() {
	if (!m_bDraw) { return; }
	m_Move.y = sin(MOF_ToRadian(m_Dir)) * m_Speed;
	m_Move.x = cos(MOF_ToRadian(m_Dir)) * m_Speed;

	m_Pos += m_Move;

	float w = g_pGraphics->GetTargetWidth();
	float h = g_pGraphics->GetTargetHeight();

	if (m_ReflectionNo > 0) {
		if (m_Pos.x < m_Radius) {
			m_ReflectionNo--;
			m_Pos.x = m_Radius;
			m_Dir = 180 - m_Dir;
		}
		else if (m_Pos.x > w - m_Radius) {
			m_ReflectionNo--;
			m_Pos.x = w - m_Radius;
			m_Dir = 180 - m_Dir;
		}
		else if (m_Pos.y < m_Radius) {
			m_ReflectionNo--;
			m_Pos.y = m_Radius;
			m_Dir = 360 - m_Dir;
		}
		else if (m_Pos.y > h - m_Radius) {
			m_ReflectionNo--;
			m_Pos.y = h - m_Radius;
			m_Dir = 360 - m_Dir;
		}
		if (m_Dir < 0)
			m_Dir += 360;
		if (m_Dir > 360)
			m_Dir -= 360;
	}
	else {
		if (m_Pos.y - m_Radius > h || m_Pos.y + m_Radius < 0 || m_Pos.x - m_Radius > w || m_Pos.x + m_Radius < 0)
			m_bDraw = false;
	}
}

void CEnemyBullet::PopUpdate() {
	m_PopLen += 0.5f;
	m_PopRad -= 0.1f;
	if (m_PopRad < 0)
		m_PopRad = 0;
}

int CEnemyBullet::Collision(CRectangle prec) {
	if (!m_bDraw) {
		return 0;
	}
	if (GetRec().CollisionRect(prec)) {
		m_bDraw = false;
		return 1;
	}
	return 0;
}

void CEnemyBullet::Render() {
	if (!m_bDraw) { return; }
	CGraphicsUtilities::RenderFillCircle(m_Pos.x, m_Pos.y, m_Radius, MOF_COLOR_RED);
}

void CEnemyBullet::PopRender() {
	if (!m_bDraw) { return; }
	float dir = 360 / m_PopDirCnt;
	float x = 0;
	float y = 0;
	for (int i = 0; i < m_PopDirCnt; i++)
	{
		x = m_Pos.x + cos(MOF_ToRadian(dir * i)) * m_PopLen;
		y = m_Pos.y + sin(MOF_ToRadian(dir * i)) * m_PopLen;
		CGraphicsUtilities::RenderFillCircle(x, y, m_PopRad, MOF_COLOR_RED);
	}
}

void CEnemyBullet::Release() {

}