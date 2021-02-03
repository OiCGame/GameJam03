#include "SceneGameClear.h"

CSceneGameClear::CSceneGameClear() {

}

CSceneGameClear::~CSceneGameClear() {

}

void CSceneGameClear::Initialize() {

}

void CSceneGameClear::Update() {
	if (CInputManager::GetInstance().GetPush(1))
	{
		m_bEnd = true;
		m_NextSceneNo = SCENENO_TITLE;
	}
}

void CSceneGameClear::Render() {

	for (int i = 0; i < m_MessageCount; i++)
	{
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_OptionMessage[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 350 + i * 40;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_OptionMessage[i].c_str());
	}
}

void CSceneGameClear::RenderDebug() {

}

void CSceneGameClear::Release() {

}