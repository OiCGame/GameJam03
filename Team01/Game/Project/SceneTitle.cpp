#include "SceneTitle.h"

CSceneTitle::CSceneTitle() {

}

CSceneTitle::~CSceneTitle() {

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
	if (CInputManager::GetInstance().GetPush(1))
	{
		m_bEndStart = true;
		switch (m_SelectNo)
		{
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
	for (int i = 0; i < m_MessageCount; i++)
	{
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_Message[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 350 + i * 40;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_Message[i].c_str());
		if (i == m_SelectNo + 1)
			CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, MOF_XRGB(255, 0, 0), m_Message[i].c_str());
	}
	RenderFade();
}

void CSceneTitle::RenderDebug() {

}

void CSceneTitle::Release() {

}