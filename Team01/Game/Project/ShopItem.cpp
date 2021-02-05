#include "ShopItem.h"


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

uint32_t CShopItem::GetPrice(void) const {
	return this->m_Price;
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

	std::string price_text = "ƒRƒXƒg : ";
	price_text += std::to_string(m_Price);
	m_pFont->RenderString(price_rect.Left, price_rect.Top, price_text.c_str());
	*/
	return true;
}
