#include "EnemyBullet.h"

CEnemyBullet::CEnemyBullet():
m_Pos(0.0f,0.0f),
m_Move(0.0f,0.0f),
m_Radius(6.0f),
m_Speed(3.0f),
m_Dir(0.0f),
m_bDrow(false){

}

CEnemyBullet::~CEnemyBullet() {

}

void CEnemyBullet::Initialize(float dir) {
	m_Dir = dir;
}

void CEnemyBullet::Generation(Vector2 pos) {
	m_bDrow = true;
	m_Pos = pos;
}

void CEnemyBullet::Update() {
	if (!m_bDrow) { return; }
	m_Move.y = sin(MOF_ToRadian(m_Dir)) * m_Speed;
	m_Move.x = cos(MOF_ToRadian(m_Dir)) * m_Speed;

	m_Pos += m_Move;
}

void CEnemyBullet::Render() {
	if (!m_bDrow) { return; }
	CGraphicsUtilities::RenderFillCircle(m_Pos.x, m_Pos.y, m_Radius, MOF_COLOR_RED);
}

void CEnemyBullet::Release() {

}