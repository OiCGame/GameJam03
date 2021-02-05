#include "Item.h"

CItem::CItem() :
	m_Position(),
	m_pTexture(),
	m_bShow(false) {
}

CItem::~CItem() {
}

void CItem::SetPosition(Mof::CVector2 pos) {
	m_Position = pos;
}

void CItem::SetTexture(Mof::CTexture * ptr) {
	m_pTexture = ptr;
}

void CItem::SetShow(bool flag) {
	this->m_bShow = flag;
}

void CItem::SetPlayer(CCharacter * ptr) {
	this->m_pTarget = ptr;
}

Mof::CRectangle CItem::GetRectangle(void) const {
	auto pos = m_Position;
	auto size = Mof::CVector2(m_pTexture->GetWidth(), m_pTexture->GetHeight());
	return Mof::CRectangle(pos, pos + size);
}

bool CItem::IsShow(void) const {
	return this->m_bShow;
}

bool CItem::Update(void) {
	Mof::CVector2 direction = m_pTarget->GetPosition() - m_Position;
	direction.Normal(direction);

	float acceleration = 2.0f;
	m_Position += direction * acceleration;
	return true;
}

bool CItem::Render(void) {
	if (m_pTexture) {
		m_pTexture->Render(m_Position.x, m_Position.y);
	} // if
	return true;
}

bool CItem::Use(CCharacter & out) {
	
	out.AddRevivalCount();


	return true;
}