#include "ShopShip.h"


CShopShip::CShopShip() :
	m_Position(),
	m_pTexture(),
	m_bShow(false),
	m_pTextures(),
	m_pPlayer(),
	m_Items(),
	m_TransportDistance(0),
	m_TransportDistanceCount(0){
}

CShopShip::~CShopShip() {
}

void CShopShip::SetTexutre(Mof::CTexture * ptr) {
	this->m_pTexture = ptr;
}

void CShopShip::SetResources(std::unordered_map<std::string, Mof::CTexture>* ptr) {
	this->m_pTextures = ptr;
}

void CShopShip::SetPlayer(CCharacter * ptr) {
	this->m_pPlayer = ptr;
}

bool CShopShip::IsShow(void) const {
	return this->m_bShow;
}

void CShopShip::AddItem(const std::shared_ptr<CItem>& ptr) {
	ptr->SetPlayer(m_pPlayer);
	ptr->SetShow(false);
	m_Items.push_back(ptr);
}

void CShopShip::Start(void) {
	m_Position.x = 1024.0f;
	m_Position.y = 300.0f;
	m_bShow = true;
	
	m_TransportDistance = m_Position.x / m_Items.size();
}

bool CShopShip::Update(std::vector<std::shared_ptr<CItem>>& out) {
	auto prev = m_Position.x;
	m_Position.x--;

	m_TransportDistanceCount += std::abs(m_Position.x - prev);
	
	if (m_TransportDistance < m_TransportDistanceCount && !m_Items.empty()) {
		out.reserve(m_Items.size());
		std::move(m_Items.end() - 1, m_Items.end(), std::back_inserter(out));
		out.at(out.size() - 1)->SetPosition(m_Position);
		out.at(out.size() - 1)->SetShow(true);

		auto it = std::remove(
			m_Items.begin(),
			m_Items.end(), 
			m_Items.at(m_Items.size() - 1));
		m_Items.erase(it, m_Items.end());

		m_TransportDistanceCount = 0.0f;
	} // if
	


	if (m_Position.x < 0.0f - m_pTexture->GetWidth()) {
		m_bShow = false;
	} // if

	return true;
}

bool CShopShip::Render(void) {
	if (m_pTexture) {
		m_pTexture->Render(m_Position.x, m_Position.y);
	} // if
	return true;
}