#include "SceneRanking.h"

CSceneRanking::CSceneRanking() {

}

CSceneRanking::~CSceneRanking() {
	Release();
}

bool CSceneRanking::Load() {
	return false;
}

void CSceneRanking::Initialize() {
	m_SelectNo = 0;
	FILE* fp = fopen("Score/Score.dat", "rb");
	if (fp)
	{
		fread(m_Score, sizeof(int), m_ScoreCount, fp);
		fclose(fp);
	}
	else
	{
		for (int i = 0; i < m_ScoreCount; i++)
		{
			m_Score[i] = 0;
		}
	}
}

void CSceneRanking::Update() {
	FadeInOut();
	if (m_bEndStart) { return; }
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_TITLE;
	}
}

void CSceneRanking::Render() {
	for (int i = 0; i < 2; i++)
	{
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_RankingMessage[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 100 + i * 500;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_RankingMessage[i].c_str());
		if (i == m_SelectNo)
			CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, MOF_XRGB(255, 0, 0), m_RankingMessage[i].c_str());
	}
	for (int i = 0; i < m_ScoreCount; i++)
	{
		CGraphicsUtilities::RenderString(g_pGraphics->GetTargetWidth() * 0.4f, 140 + 40 * i, "%dà Å@%d", i + 1, m_Score[i]);
	}
	RenderFade();
}

void CSceneRanking::RenderDebug() {
}

void CSceneRanking::Release() {
}