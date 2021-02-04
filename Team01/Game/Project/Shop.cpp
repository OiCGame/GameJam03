#include "Shop.h"


CShopItem::CShopItem() :
	m_pFont(),
	m_Position(),
	m_pTexture(),
	m_DatailText() {
}

CShopItem::~CShopItem() {
}

bool CShopItem::Initialize(Mof::CFont * font, Mof::CVector2 pos, Mof::CTexture * tex, const std::string & text) {
	return true;
}

bool CShopItem::Render(void) {
	return true;
}

CShop::CShop() :
	m_Font(),
	m_pResources(),
	m_PlayerTexturePath(),
	m_BulletTexturePath() {
}

CShop::~CShop() {
}

bool CShop::Initialize(std::unordered_map<std::string, Mof::CTexture>* resources, std::string playerTexturePath, std::string bulletTexturePath) {
	if (!m_Font.Create(64, "メイリオ")) {
		return false;
	} // if


	m_pResources = resources;
	m_PlayerTexturePath = playerTexturePath;
	m_BulletTexturePath = bulletTexturePath;
	return true;
}

bool CShop::Render(void) {
	auto&player_tex = m_pResources->at(m_PlayerTexturePath);

	{
		auto offset = Mof::CVector2(-32.0f, 32.0f);
		auto rect = Mof::CRectangle(0.0f, 0.0f, 384.0f, 160.0f);
		auto window_size = Mof::CVector2(
			::g_pFramework->GetWindow()->GetWidth(),
			::g_pFramework->GetWindow()->GetHeight());

		rect.Translation(Mof::CVector2(window_size.x - rect.GetWidth() + offset.x, 0.0f + offset.y));
		::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_WHITE);

		float margin = 8.0f;
		rect.Expansion(-margin);
		::CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_BLACK);

		auto image_back_rect = Mof::CRectangle(0.0f, 0.0f, player_tex.GetWidth(), player_tex.GetHeight());
		image_back_rect.Translation(Mof::CVector2(
			rect.GetTopLeft().x + margin,
			rect.GetTopLeft().y + margin
		));
		::CGraphicsUtilities::RenderFillRect(image_back_rect, MOF_ARGB(255, 128, 128, 128));
		player_tex.Render(image_back_rect.Left, image_back_rect.Top);

		auto detail_rect = Mof::CRectangle(
			image_back_rect.Right + margin,
			image_back_rect.Top,
			rect.Right - margin,
			image_back_rect.Bottom);
		::CGraphicsUtilities::RenderFillRect(detail_rect, MOF_ARGB(255, 128, 128, 128));
		::CGraphicsUtilities::RenderString(detail_rect.Left, detail_rect.Top, "残機\nリトライ回数が増える");

		auto price_rect = Mof::CRectangle(
			image_back_rect.Left,
			image_back_rect.Bottom + margin,
			detail_rect.Right,
			image_back_rect.Bottom + image_back_rect.GetHeight());
		::CGraphicsUtilities::RenderFillRect(price_rect, MOF_ARGB(255, 128, 128, 128));

		std::string price_text = "コスト : ";
		price_text += std::to_string(10000);
		m_Font.RenderString(price_rect.Left, price_rect.Top, price_text.c_str());
	}

	return true;
}