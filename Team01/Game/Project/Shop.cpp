#include "Shop.h"

#include "Item1Up.h"
#include "ItemBulletPowerUp1.h"
#include "Item3Way.h"
#include "ItemAuto.h"


void CShop::ItemSelect(void) {
	if (auto ptr = m_pSelectItem.lock()) {
		ptr->SetSelectFlag(false);
	} // if
	m_pSelectItem = m_Items.at(m_SelectIndex);
	m_pSelectItem.lock()->SetSelectFlag(true);
}

std::shared_ptr<CItem> CShop::CreateItem(int index) {
	std::shared_ptr<CItem> ptr;
	switch (index) {
	case 0:
		ptr = std::make_shared<CItem1Up>();
		ptr->SetTexture(&m_pResources->at("shop/1Up.png"));
		break;
	case 1:
		ptr = std::make_shared<CItemBulletPowerUp1>();
		ptr->SetTexture(&m_pResources->at("shop/Lv.1.png"));
		break;
	case 2:
		ptr = std::make_shared<CItemAuto>();
		ptr->SetTexture(&m_pResources->at("shop/A.png"));
		break;
	case 3:
		ptr = std::make_shared<CItem3Way>();
		ptr->SetTexture(&m_pResources->at("shop/3way.png"));
		break;
	default:
		break;
	} // swicth
	return ptr;
}

CShop::CShop() :
	m_Font(),
	m_pResources(),
	m_Items(),
	m_SelectIndex(0),
	m_pSelectItem(),
	m_bShow(false),
	m_pCanvas(),
	m_bAutoShotSoldout(false),
	m_b3WayShotSoldout(false),
	m_ShotLvUpMaxCount(3),
	m_ShotLvUpCount(0) {
}

CShop::~CShop() {
}

void CShop::SetShowFlag(bool flag) {
	m_bShow = flag;
}

void CShop::SetCanvasPtr(UICanvas * ptr) {
	this->m_pCanvas = ptr;
}


bool CShop::IsShow(void) const {
	return this->m_bShow;
}

bool CShop::Initialize(std::unordered_map<std::string, Mof::CTexture>* resources) {
	if (!m_Font.Create(32, "メイリオ")) {
		return false;
	} // if
	m_pResources = resources;

	struct InitParam {
		Mof::CTexture* texture;
		uint32_t price;
	};
	InitParam params[]{
		{&m_pResources->at("shop/shop-hart.png"), 1},
		{&m_pResources->at("shop/shop-atk-Up.png"), 9},
		{&m_pResources->at("shop/shop-auto.png"), 5},
		{&m_pResources->at("shop/shop-spazer.png"), 2}
	};
	m_Items.reserve(sizeof(params) / sizeof(InitParam));

	for (auto& param : params) {
		auto ptr = std::make_shared<CShopItem>();
		ptr->Initialize(&m_Font, param.texture, param.price);
		m_Items.push_back(ptr);
	} // for
	m_pSelectItem.reset();

	m_bAutoShotSoldout = false;
	m_b3WayShotSoldout = false;
	m_ShotLvUpCount = 0;

	return true;
}

bool CShop::Update(CShopShip& out) {
	// index
	if (CInputManager::GetInstance().GetVertical() > 0.25f) {
		m_SelectIndex--;
		if (m_SelectIndex < 0) {
			m_SelectIndex = 0;
		} // if
		this->ItemSelect();
	} // if
	else if (CInputManager::GetInstance().GetVertical() < -0.25f) {
		if (m_pSelectItem.expired()) {
			m_SelectIndex = 0;
		} // if
		else {
			m_SelectIndex++;
		} // else

		if (m_Items.size() - 1 < m_SelectIndex) {
			m_SelectIndex = m_Items.size() - 1;
		} // if
		this->ItemSelect();
	} // else if


	switch (m_SelectIndex)
	{
	case 0:
		// 一機アップ
		break;
	case 1:
		if (m_ShotLvUpCount < m_ShotLvUpMaxCount)
		{
			return false;
		}
		break;
	case 2:
		if (m_bAutoShotSoldout)
		{
			return false;
		}
		break;
	case 3:
		if (m_b3WayShotSoldout)
		{
			return false;
		}
	default:
		break;
	}


	// buy
	if (CInputManager::GetInstance().GetPush(0) && !m_pSelectItem.expired()) {
		auto ptr = m_pSelectItem.lock();
		if (ptr->GetPrice() < m_pCanvas->GetScore()) {

			if (m_SelectIndex == 2) {
				m_bAutoShotSoldout = true;
				m_Items.at(m_SelectIndex)->SetTexture(&m_pResources->at("shop/shop-has-auto.png"));
				m_Items.at(m_SelectIndex)->Soldout();
			} // if
			if (m_SelectIndex == 3) {
				m_b3WayShotSoldout = true;
				m_Items.at(m_SelectIndex)->SetTexture(&m_pResources->at("shop/shop-has-spazer.png"));
				m_Items.at(m_SelectIndex)->Soldout();
			} // if




			m_pCanvas->SubtractScore(ptr->GetPrice());
			auto ptr = this->CreateItem(m_SelectIndex);
			out.AddItem(ptr);


		} // if
	} // if

	return true;
}

bool CShop::Render(void) {
	auto offset = Mof::CVector2(-32.0f, 32.0f);
	auto window_size = Mof::CVector2(
		::g_pFramework->GetWindow()->GetWidth(),
		::g_pFramework->GetWindow()->GetHeight());
	auto rect = Mof::CRectangle(0.0f, 0.0f, 300.0f, 128.0f);
	auto pos = Mof::CVector2(window_size.x - rect.Right + offset.x, 0.0f);
	for (auto& item : m_Items) {
		item->Render(pos);
		pos.y += rect.GetHeight();
	} // for
	return true;
}