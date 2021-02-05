#include "Character.h"

#include "GameDefine.h"


void CCharacter::Move(void) {
	float threshold = 0.25f;
	if (CInputManager::GetInstance().GetHorizontal() < -threshold) {
		m_Move -= m_Speed;
	} // if
	else if (threshold < CInputManager::GetInstance().GetHorizontal()) {
		m_Move += m_Speed;
	} // else if
}

bool CCharacter::Shot(std::array<CBullet, 256>& bullet_container) {
	auto bullet_size = bullet_container.at(0).GetTextureSize();
	auto offset = Mof::CVector2(2.0f, 10.0f);
	auto size = Mof::CVector2(m_pTexture->GetWidth(), m_pTexture->GetHeight());
	auto pos = Mof::CVector2(m_Position.x + size.x * 0.5f - bullet_size.x * 0.5f,
		m_Position.y);

	for (int i = 0; i < bullet_container.size(); i++) {
		auto move = Mof::CVector2(0.0f, -5.0f);

		if (bullet_container[i].IsShow()) {
			continue;
		} // if
		bullet_container[i].Shot(pos + offset, move);
		bullet_container[i].SetNo(m_BulletNo);
		m_BulletNo++;
		break;
	} // for



	if (m_b3WayShot) {
		for (int i = 0; i < bullet_container.size(); i++) {
			auto move = Mof::CVector2(1.0f, -5.0f);

			if (bullet_container[i].IsShow()) {
				continue;
			} // if
			bullet_container[i].Shot(pos + offset, move);
			bullet_container[i].SetNo(m_BulletNo);
			m_BulletNo++;
			break;
		} // for


		for (int i = 0; i < bullet_container.size(); i++) {
			auto move = Mof::CVector2(-1.0f, -5.0f);

			if (bullet_container[i].IsShow()) {
				continue;
			} // if
			bullet_container[i].Shot(pos + offset, move);
			bullet_container[i].SetNo(m_BulletNo);
			m_BulletNo++;
			break;
		} // for
	} // if




	return true;
}

CCharacter::CCharacter() :
	m_Position(),
	m_Move(),
	m_Speed(2.0f, 0.0f),
	m_pTexture(nullptr),
	m_pBulletTexture(nullptr),
	m_HP(4),
	m_BulletNo(0),
	m_RevivalCount(1),
	m_bShow(true),
	m_bAutoShot(false),
	m_ShotInterval(20),
	m_ShotIntervalCount(0),
	m_b3WayShot(false) {
}

CCharacter::~CCharacter() {
}

void CCharacter::SetTexture(Mof::CTexture* ptr) {
	this->m_pTexture = ptr;
}

void CCharacter::SetBulletTexture(Mof::CTexture* ptr) {
	m_pBulletTexture = ptr;
}

Mof::CVector2 CCharacter::GetPosition(void) const {
	return this->m_Position;
}

Mof::CRectangle CCharacter::GetCollisionRectangle(void) const {
	auto rect = Mof::CRectangle(0.0f, 0.0f,
		m_pTexture->GetWidth(), m_pTexture->GetHeight());
	rect.Translation(m_Position);
	rect.Expansion(-25.0f, -25.0f);
	return rect;
}

uint32_t CCharacter::GetRevivalCount(void) const {
	return this->m_RevivalCount;
}
bool CCharacter::IsShow(void) const {
	return this->m_bShow;
}

bool CCharacter::Initialize(Mof::CVector2 init_pos) {
	m_Position = init_pos;
	return true;
}

bool CCharacter::Update(std::array<CBullet, 256>& bullet_container) {
	if (!this->m_bShow) {
		return false;
	} // if

	m_Move = Mof::CVector2();

	this->Move();
	if (::g_pInput->IsKeyPush(MOFKEY_SPACE) && m_bAutoShot) {
		this->Shot(bullet_container);
	} // if
	if (::g_pInput->IsKeyHold(MOFKEY_SPACE)) {
		m_ShotIntervalCount++;
		if (m_ShotInterval < m_ShotIntervalCount) {
			this->Shot(bullet_container);
			m_ShotIntervalCount = 0;
		} // if
	} // if


	m_Position += m_Move;
	return true;
}

bool CCharacter::Render(void) {
	if (!this->m_bShow) {
		return false;
	} // if

	m_pTexture->Render(m_Position.x, m_Position.y);
#ifdef _DEBUG
	::CGraphicsUtilities::RenderFillRect(
		this->GetCollisionRectangle(),
		MOF_ARGB(100, 100, 100, 100)
	);
#endif // _DEBUG
	return true;
}

bool CCharacter::Release(void) {
	return true;
}

bool CCharacter::Damage(void) {
	m_HP--;
	if (m_HP <= 0) {
		m_RevivalCount--;
		m_bShow = false;
		return true;
	} // if
	return false;
}