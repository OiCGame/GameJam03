#include "SceneGameOver.h"

CSceneGameOver::CSceneGameOver() :
	m_Texture() {

	if (!m_Texture.Load("gameover.png")) {
		::OutputDebugString("failed to load game over texture");
	} // if
}

CSceneGameOver::~CSceneGameOver() {
	m_Texture.Release();
}

bool CSceneGameOver::Load() {
	return false;
}

void CSceneGameOver::Initialize() {

}

void CSceneGameOver::Update() {
	FadeInOut();
	if (m_bEndStart) { return; }
	if (CInputManager::GetInstance().GetPush(9)) {
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_TITLE;
	}
}

void CSceneGameOver::Render() {
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

void CSceneGameOver::RenderDebug() {

}

void CSceneGameOver::Release() {

}