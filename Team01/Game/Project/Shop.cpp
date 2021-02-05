#include "Shop.h"

#include "Item1Up.h"
#include "ItemBulletPowerUp1.h"
#include "Item3Way.h"
#include "ItemAuto.h"


void CShop::ItemSelect(void) {
	if (auto ptr  = m_pSelectItem.lock()) {
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
	m_pCanvas(){
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
	if (!m_Font.Create(32, "ƒƒCƒŠƒI")) {
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
		{&m_pResources->at("shop/shop-has-auto.png"), 5},
		{&m_pResources->at("shop/shop-spazer.png"), 2}
	};
	m_Items.reserve(sizeof(params) / sizeof(InitParam));

	for (auto& param : params) {
		auto ptr = std::make_shared<CShopItem>();
		ptr->Initialize(&m_Font, param.texture, param.price);
		m_Items.push_back(ptr);
	} // for
	m_pSelectItem.reset();
	return true;
}

bool CShop::Update(CShopShip& out) {
	// index
	if (::g_pInput->IsKeyPush(MOFKEY_UP)) {
		m_SelectIndex--;
		if (m_SelectIndex < 0) {
			m_SelectIndex = 0;
		} // if
		this->ItemSelect();
	} // if
	else if (::g_pInput->IsKeyPush(MOFKEY_DOWN)) {
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
	
	
	// buy
	if (::g_pInput->IsKeyPush(MOFKEY_X) && !m_pSelectItem.expired()) {
		auto ptr = m_pSelectItem.lock();
		if (ptr->GetPrice() < m_pCanvas->GetScore()) {
			m_pCanvas->SubtractScore(ptr->GetPrice());

//			auto ptr = std::make_shared<CItem>();
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