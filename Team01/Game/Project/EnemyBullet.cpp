#include "EnemyBullet.h"

CEnemyBullet::CEnemyBullet():
m_Pos(0.0f,0.0f),
m_Move(0.0f,0.0f),
m_Radius(6.0f),
m_Speed(3.0f),
m_Dir(0.0f),
m_bDraw(false){

}

CEnemyBullet::~CEnemyBullet() {

}

void CEnemyBullet::Initialize(float dir) {
	m_Dir = dir;
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

	if (m_Pos.y - m_Radius > g_pGraphics->GetTargetHeight() || m_Pos.y + m_Radius < 0 || m_Pos.x - m_Radius > g_pGraphics->GetTargetWidth() || m_Pos.x + m_Radius < 0)
		m_bDraw = false;
}

int CEnemyBullet::Collition(CRectangle prec) {
	if (!m_bDraw)
	{
		return 0;
	}
	if (GetRec().CollisionRect(prec))
	{
		m_bDraw = false;
		return 1;
	}
	return 0;
}

void CEnemyBullet::Render() {
	if (!m_bDraw) { return; }
	CGraphicsUtilities::RenderFillCircle(m_Pos.x, m_Pos.y, m_Radius, MOF_COLOR_RED);
}

void CEnemyBullet::Release() {

}