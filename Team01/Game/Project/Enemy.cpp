#include "Enemy.h"

CEnemy::CEnemy() :
	m_HP(10),
	m_Speed(0.0f),
	m_Dir(90.0f),
	m_bDrow(true){
}

CEnemy::~CEnemy() {
}

void CEnemy::Move(void) {
	m_Move.y = sin(MOF_ToRadian(m_Dir)) * m_Speed;
	m_Move.x = cos(MOF_ToRadian(m_Dir)) * m_Speed;

	m_Pos += m_Move;

	m_Dir += 0.0f;
}

Mof::CVector2 CEnemy::GetPosition(void) const {
	return this->m_Pos;
}

void CEnemy::Initialize(Vector2 pos) {
	m_Pos = pos;

	m_BulletColumn = rand() % 32;
	m_BulletAmount = rand() % 5 + 1;
	m_BulletSetAmount = rand() % 5 + 5;

	m_BulletCount = m_BulletColumn * m_BulletAmount * m_BulletSetAmount;

	m_Bullet = new CEnemyBullet[m_BulletCount];


	int dirpat = 360 / m_BulletColumn;
	float dirSplit = rand() % dirpat;

	float dir = 90 - (m_BulletColumn - 1) * dirSplit / 2;

	for (int i = 0; i < m_BulletCount; i++) {
		int dp = i % m_BulletColumn;
		m_Bullet[i].Initialize(dir + dp * dirSplit);
	}

	m_BulletNo = 0;
	m_BulletSetNo = 0;
	m_BulletRemGap = 0;
	m_BulletSetRemGap = 0;
}

void CEnemy::SetTexture(Mof::CTexture* ptr) {
	m_pTexture = ptr;
}

void CEnemy::Update() {
	for (int i = 0; i < m_BulletNo; i++) {
		m_Bullet[i].Update();
	}

	if (m_BulletNo >= m_BulletCount) { return; }
	if (m_BulletSetRemGap > 0) {
		m_BulletSetRemGap--;
		return;
	}
	if (m_BulletRemGap > 0) {
		m_BulletRemGap--;
		return;
	}
	for (int i = 0; i < m_BulletColumn; i++) {
		m_Bullet[m_BulletNo].Generation(m_Pos);
		m_BulletNo++;
	}
	m_BulletRemGap = m_BulletGap;
	m_BulletSetNo++;
	if (m_BulletSetNo >= m_BulletAmount) {
		m_BulletSetNo = 0;
		m_BulletSetRemGap = m_BulletSetGap;
	}
}

int CEnemy::CollitionBullet(CRectangle prec) {
	int col = 0;
	for (int i = 0; i < m_BulletCount; i++)
	{
		col += m_Bullet[i].Collition(prec);
	}
	return col;
}

void CEnemy::Render() {
#ifdef _DEBUG
	::CGraphicsUtilities::RenderRect(
		this->GetCollisionRectangle(),
		MOF_ARGB(100, 100, 100, 100)
	);
#endif // _DEBUG
	m_pTexture->Render(m_Pos.x - m_pTexture->GetWidth() / 2, m_Pos.y - m_pTexture->GetHeight() / 2);
	for (int i = 0; i < m_BulletCount; i++) {
		m_Bullet[i].Render();
	}
}

void CEnemy::Release() {
	if (m_Bullet) {
		delete[] m_Bullet;
		m_Bullet = NULL;
	}
}

Mof::CRectangle CEnemy::GetCollisionRectangle(void) const {
	auto rect = Mof::CRectangle(0.0f, 0.0f,
		m_pTexture->GetWidth(), m_pTexture->GetHeight());
	auto size = Vector2(m_pTexture->GetWidth() * 0.5f, m_pTexture->GetHeight() * 0.5f);
	auto pos = m_Pos;
	rect.Translation(m_Pos - size);
	return rect;
}

void CEnemy::Damage(void) {
	m_HP--;
	if (m_HP <= 0) {
		m_bDrow = false;
	} // if
}