#include "SceneGameOver.h"

CSceneGameOver::CSceneGameOver() {

}

CSceneGameOver::~CSceneGameOver() {

}

void CSceneGameOver::Initialize() {

}

void CSceneGameOver::Update() {
	if (CInputManager::GetInstance().GetPush(1))
	{
		m_bEnd = true;
		m_NextSceneNo = SCENENO_TITLE;
	}
}

void CSceneGameOver::Render() {

	for (int i = 0; i < m_MessageCount; i++)
	{
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_OptionMessage[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 350 + i * 40;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_OptionMessage[i].c_str());
	}
}

void CSceneGameOver::RenderDebug() {

}

void CSceneGameOver::Release() {

}