#include "Shop.h"


CShopItem::CShopItem() :
	m_pFont(),
	m_pTexture(),
	m_DetailsText(),
	m_Price(0),
	m_Frame(Mof::CRectangle(0.0f, 0.0f, 384.0f, 160.0f)),
	m_bSelect(false) {
}

CShopItem::~CShopItem() {
}

void CShopItem::SetSelectFlag(bool flag) {
	m_bSelect = flag;
}

Mof::CVector2 CShopItem::GetSize(void) const {
	return Mof::CVector2(m_Frame.GetWidth(), m_Frame.GetHeight());
}

//bool CShopItem::Initialize(Mof::CFont * font, Mof::CTexture * tex, const std::string & text, uint32_t price) {
bool CShopItem::Initialize(Mof::CFont * font, Mof::CTexture * tex, uint32_t price) {
	m_pFont = font;
	m_pTexture = tex;
	m_Price = price;
	return true;
}

bool CShopItem::Render(Mof::CVector2 position) {
	auto rect = m_Frame;

	m_pTexture->Render(position.x, position.y);
	if (m_bSelect) {
		auto pos = position;
		float s = 8.0f;
		float width = m_pTexture->GetWidth();
		float height = m_pTexture->GetHeight();
		std::vector<Mof::CRectangle> rects = {
			Mof::CRectangle(pos.x, pos.y, pos.x + width, pos.y + s),
			Mof::CRectangle(pos.x, pos.y, pos.x + s, pos.y + height),
			Mof::CRectangle(pos.x + width - s, pos.y, pos.x + width , pos.y + height),
			Mof::CRectangle(pos.x, pos.y + height - s, pos.x + width , pos.y + height)
		};
		for (auto&rect : rects) {
			::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_YELLOW);
		} // for
	} // if


	position.x += 108.0f;
	position.y += 78.0f;


	std::string price_text = std::to_string(m_Price);
	m_pFont->RenderString(position.x, position.y, price_text.c_str());
	/*
	rect.Translation(position);
	::CGraphicsUtilities::RenderFillRect(rect, m_bSelect ? MOF_COLOR_YELLOW : MOF_COLOR_WHITE);

	float margin = 8.0f;
	rect.Expansion(-margin);
	::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);

	auto image_back_rect = Mof::CRectangle(0.0f, 0.0f, m_pTexture->GetWidth(), m_pTexture->GetHeight());
	image_back_rect.Translation(Mof::CVector2(
		rect.GetTopLeft().x + margin,
		rect.GetTopLeft().y + margin
	));
	::CGraphicsUtilities::RenderFillRect(image_back_rect, MOF_ARGB(255, 128, 128, 128));
	m_pTexture->Render(image_back_rect.Left, image_back_rect.Top);

	auto detail_rect = Mof::CRectangle(
		image_back_rect.Right + margin,
		image_back_rect.Top,
		rect.Right - margin,
		image_back_rect.Bottom);
	::CGraphicsUtilities::RenderFillRect(detail_rect, MOF_ARGB(255, 128, 128, 128));
	::CGraphicsUtilities::RenderString(detail_rect.Left, detail_rect.Top, m_DetailsText.c_str());

	auto price_rect = Mof::CRectangle(
		image_back_rect.Left,
		image_back_rect.Bottom + margin,
		detail_rect.Right,
		image_back_rect.Bottom + image_back_rect.GetHeight());
	::CGraphicsUtilities::RenderFillRect(price_rect, MOF_ARGB(255, 128, 128, 128));

	std::string price_text = "コスト : ";
	price_text += std::to_string(m_Price);
	m_pFont->RenderString(price_rect.Left, price_rect.Top, price_text.c_str());
	*/
	return true;
}

void CShop::ItemSelect(void) {
	if (m_pSelectItem) {
		m_pSelectItem->SetSelectFlag(false);
	} // if
	m_pSelectItem = &m_Items.at(m_SelectIndex);
	m_pSelectItem->SetSelectFlag(true);
}

CShop::CShop() :
	m_Font(),
	m_pResources(),
	m_Items(),
	m_SelectIndex(0),
	m_pSelectItem(),
	m_Position(),
	m_bShipShow(false),
m_bShow(false){
}

CShop::~CShop() {
}

void CShop::SetShowFlag(bool flag) {
	m_bShow = flag;
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
		{&m_pResources->at("shop/shop-hart.png"), 10000},
		{&m_pResources->at("shop/shop-atk-Up.png"), 9000},
		{&m_pResources->at("shop/shop-has-auto.png"), 500000},
		{&m_pResources->at("shop/shop-spazer.png"), 10}
	};

	m_Items.resize(sizeof(params) / sizeof(InitParam));

	for (int i = 0; i < m_Items.size(); i++) {
		m_Items.at(i).Initialize(
			&m_Font, params[i].texture, params[i].price
		);
	} // for

	m_pSelectItem = &m_Items.at(m_SelectIndex);
	m_pSelectItem->SetSelectFlag(true);
	return true;
}

bool CShop::Update(std::vector<std::shared_ptr<CItem>>& out, CCharacter& player) {
	if (::g_pInput->IsKeyPush(MOFKEY_UP)) {
		m_SelectIndex--;
		if (m_SelectIndex < 0) {
			m_SelectIndex = 0;
		} // if
		this->ItemSelect();
	} // if
	else if (::g_pInput->IsKeyPush(MOFKEY_DOWN)) {
		m_SelectIndex++;
		if (m_Items.size() - 1 < m_SelectIndex) {
			m_SelectIndex = m_Items.size() - 1;
		} // if
		this->ItemSelect();
	} // else if


	if (::g_pInput->IsKeyPush(MOFKEY_Z) && !m_bShipShow) {
		m_bShipShow = true;
		m_Position.x = ::g_pFramework->GetWindow()->GetWidth();
		m_Position.y = ::g_pFramework->GetWindow()->GetHeight() * 0.5f;

	} // if

	if (m_bShipShow) {
		m_Position.x--;
		if (m_Position.x < 0.0f) {
			m_bShipShow = false;
		} // if
		
		if (m_Position.x < 512.0f) {
			auto ptr = std::make_shared<CItem>();

			ptr->SetPosition(m_Position);
			ptr->SetShow(true);
			ptr->SetPlayer(&player);

			switch (m_SelectIndex) {
			case 0:
				ptr->SetTexture(&m_pResources->at("shop/1Up.png"));
				break;
			case 1:
				ptr->SetTexture(&m_pResources->at("shop/3way.png"));
				break;
			case 2:
				ptr->SetTexture(&m_pResources->at("shop/A.png"));
				break;
			case 3:
				ptr->SetTexture(&m_pResources->at("shop/Lv.1.png"));
				break;
			default:
				break;
			} // swicth
		} // if

	} // if

	return true;
}

bool CShop::Render(void) {
	auto offset = Mof::CVector2(-32.0f, 32.0f);
	auto window_size = Mof::CVector2(
		::g_pFramework->GetWindow()->GetWidth(),
		::g_pFramework->GetWindow()->GetHeight());
	//	auto rect = m_PlayerItem.GetSize();
	auto rect = Mof::CRectangle(0.0f, 0.0f, 300.0f, 128.0f);

	auto pos = Mof::CVector2(window_size.x - rect.Right + offset.x, 0.0f);

	for (auto& item : m_Items) {
		item.Render(pos);
		pos.y += rect.GetHeight();
	} // for


	if (m_bShipShow) {
		m_pResources->at("shop/ship.png").Render(m_Position.x, m_Position.y);
	} // if
	return true;
}

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
