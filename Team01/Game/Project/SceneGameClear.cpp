#include "SceneGameClear.h"

CSceneGameClear::CSceneGameClear() :
	m_Texture() {
	if (!m_Texture.Load("gameclear.png")) {
		::OutputDebugString("failed to load game clear texture");
	} // if
}

CSceneGameClear::~CSceneGameClear() {
	m_Texture.Release();
}

bool CSceneGameClear::Load() {
	return false;
}

void CSceneGameClear::Initialize() {

}

void CSceneGameClear::Update() {
	FadeInOut();
	if (m_bEndStart) { return; }
	if (CInputManager::GetInstance().GetPush(1)) {
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_TITLE;
	}
}

void CSceneGameClear::Render() {
	m_Texture.Render(0.0f, 0.0f);
	for (int i = 0; i < m_MessageCount; i++) {
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_OptionMessage[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 350 + i * 40;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_OptionMessage[i].c_str());
	}
	RenderFade();
}

void CSceneGameClear::RenderDebug() {

}

void CSceneGameClear::Release() {

}