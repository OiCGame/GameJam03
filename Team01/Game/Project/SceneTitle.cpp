#include "SceneTitle.h"


CSceneTitle::CSceneTitle() :
	m_Texture(),
	m_Font() {

	if (!m_Texture.Load("title.png")) {
		::OutputDebugString("failed to load title texture");
	} // if
	if (!m_ShopTexture.Load("shop.png")) {
		::OutputDebugString("failed to load title texture");
	} // if


	if (!m_Font.Create(48, "ÉÅÉCÉäÉI")) {
		::OutputDebugString("failed to create title font");
	} // if
}

CSceneTitle::~CSceneTitle() {
	m_Texture.Release();
	m_ShopTexture.Release();
}

bool CSceneTitle::Load() {
	return false;
}

void CSceneTitle::Initialize() {
}

void CSceneTitle::Update() {
	FadeInOut();
	if (m_bEndStart) { return; }
	SelectVertical(m_SelectNo, m_MessageCount - 1, true);
	if (CInputManager::GetInstance().GetPush(1)) {
		m_bEndStart = true;
		switch (m_SelectNo) {
		case 0:
			m_NextSceneNo = SCENENO_GAME;
			break;
		case 1:
			m_NextSceneNo = SCENENO_RANKING;
			break;
		default:
			break;
		}
	}
}

void CSceneTitle::Render() {
	m_Texture.Render(0.0f, 0.0f);

	m_ShopTexture.Render(400.0f, 0.0f);

	for (int i = 0; i < m_MessageCount; i++) {
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_Message[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 350 + i * 40;
		m_Font.RenderString(wid - r.GetWidth() / 2, hei, m_Message[i].c_str());
		//CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_Message[i].c_str());

		if (i == m_SelectNo + 1)
			m_Font.RenderString(wid - r.GetWidth() / 2, hei, MOF_XRGB(255, 0, 0), m_Message[i].c_str());
		//CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, MOF_XRGB(255, 0, 0), m_Message[i].c_str());


	}
	RenderFade();
}

void CSceneTitle::RenderDebug() {

}

void CSceneTitle::Release() {

}