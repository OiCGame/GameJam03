#include "SceneTitle.h"

CSceneTitle::CSceneTitle() {

}

CSceneTitle::~CSceneTitle() {

}

void CSceneTitle::Initialize() {

}

void CSceneTitle::Update() {
	if (CInputManager::GetInstance().GetPush(1))
	{
		m_bEnd = true;
		m_NextSceneNo = SCENENO_GAME;
	}
}

void CSceneTitle::Render() {

	for (int i = 0; i < m_MessageCount; i++)
	{
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_OptionMessage[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 350 + i * 40;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_OptionMessage[i].c_str());
	}
}

void CSceneTitle::RenderDebug() {

}

void CSceneTitle::Release() {

}