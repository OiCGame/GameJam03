#include "Character.h"

#include "GameDefine.h"
#include "Item.h"


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
	m_HP(3),
	m_BulletNo(0),
	m_RevivalCount(2),
	m_bShow(true),
	m_bAutoShot(false),
	m_ShotInterval(20),
	m_ShotIntervalCount(m_ShotInterval),
	m_b3WayShot(false),
	m_BulletLevel(1) {
}

CCharacter::~CCharacter() {
}

void CCharacter::SetTexture(Mof::CTexture* ptr) {
	this->m_pTexture = ptr;
}

void CCharacter::SetBulletTexture(Mof::CTexture* ptr) {
	m_pBulletTexture = ptr;
}

void CCharacter::SetCanvas(UICanvas * ptr) {
	m_pCanvas = ptr;
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
uint32_t CCharacter::GetBulletShotLevel(void) const {
	return this->m_BulletLevel;
}
bool CCharacter::IsShow(void) const {
	return this->m_bShow;
}

bool CCharacter::Initialize(Mof::CVector2 init_pos) {
	m_InitPos = init_pos;
	m_Position = Vector2(m_InitPos.x, g_pGraphics->GetTargetHeight());
	return true;
}

bool CCharacter::Update(std::array<CBullet, 256>& bullet_container, int pha) {
	if (!this->m_bShow) {
		return false;
	} // if
	if (pha == 1) {
		m_Position.y -= 4;
	}
	else {
		m_Move = Mof::CVector2();

		if (m_Position.y > m_InitPos.y) {
			m_Position.y -= 3;
		}

	this->Move();
	if (CInputManager::GetInstance().GetPush(9) && m_bAutoShot) {
		this->Shot(bullet_container);
	} // if
	if (CInputManager::GetInstance().GetHold(9)) {
		m_ShotIntervalCount++;
		if (m_ShotInterval < m_ShotIntervalCount) {
			this->Shot(bullet_container);
			m_ShotIntervalCount = 0;
		} // if
	} // if

		m_Position.x = std::clamp(m_Position.x + m_Move.x, 0.0f, 1024.0f - m_pTexture->GetWidth());

	} // else
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
		m_bShow = false;
		return true;
	} // if
	return false;
}

bool CCharacter::Revival(void) {
	m_RevivalCount--;
	m_bShow = true;
	m_HP = (4);
	return true;
}

bool CCharacter::OnUses(const std::shared_ptr<class CItem>& ptr) {
	ptr->Use(*this);
	return true;
}

void CCharacter::AddRevivalCount(void) {
	int temp = m_RevivalCount;
	m_RevivalCount++;

	auto& player_tex = *m_pTexture;
	auto pos = Mof::CVector2(0.0f, ::g_pGraphics->GetTargetHeight() - player_tex.GetHeight());
	float width = player_tex.GetWidth();
	pos.x += width * temp;

	auto name = std::string("image");
	name += std::to_string(temp);
	m_pCanvas->AddImage(name.c_str(), &player_tex, pos);
}

void CCharacter::BulletPowerUp(int level) {
	if (m_BulletLevel < level) {
		m_BulletLevel = level;
	} // if
}

void CCharacter::AttachAutoShot(void) {
	m_bAutoShot = true;
}

void CCharacter::Attach3WayShot(void) {
	m_b3WayShot = true;
}