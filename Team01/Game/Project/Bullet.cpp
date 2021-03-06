#include "Bullet.h"


CBullet::CBullet() :
	m_Position(),
	m_Move(0.0f, -5.0f),
	m_pTexture(),
	m_bShow(false),
//	m_bUnDisappear(true),
	m_bUnDisappear(false) {
}

CBullet::~CBullet() {
}

void CBullet::SetTexture(Mof::CTexture* ptr) {
	this->m_pTexture = ptr;
}

void CBullet::Hide(void) {
	if (!m_bUnDisappear)
		this->m_bShow = false;
}

Mof::CVector2 CBullet::GetTextureSize(void) const {
	auto tex = m_pTexture;
	if (tex) {
		return Mof::CVector2(tex->GetWidth(), tex->GetHeight());
	} // if
	return Mof::CVector2();
}

Mof::CRectangle CBullet::GetCollisionRectangle(void) const {
	auto rect = Mof::CRectangle(0.0f, 0.0f,
		m_pTexture->GetWidth(), m_pTexture->GetHeight());
	rect.Translation(m_Position);
	return rect;
}

bool CBullet::IsShow(void) const {
	return this->m_bShow;
}

bool CBullet::Update(void) {
	m_Position += m_Move;

	if (m_Position.y < 0.0f) {
		this->Hide();
	} // if
	return true;
}

bool CBullet::Render(void) {

	auto tex = m_pTexture;
	if (tex) {
		tex->Render(m_Position.x, m_Position.y);
	} // if
	return true;
}

bool CBullet::Shot(Mof::CVector2 init_pos, Mof::CVector2 move) {
	m_bShow = true;
	m_Position = init_pos;
	m_Move = move;
	return true;
}