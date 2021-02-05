#include "SceneRanking.h"

CSceneRanking::CSceneRanking() :
	m_Texture() {

	if (!m_Texture.Load("ranking_scene.jpg")) {
		::OutputDebugString("failed to load ranking scene texture");
	} // if
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
	if (fp) {
		fread(m_Score, sizeof(int), m_ScoreCount, fp);
		fclose(fp);
	}
	else {
		for (int i = 0; i < m_ScoreCount; i++) {
			m_Score[i] = 0;
		}
	}

	std::sort(std::begin(m_Score), std::end(m_Score), [](int a, int b) {
		return a > b;
	});
}

void CSceneRanking::Update() {
	FadeInOut();
	if (m_bEndStart) { return; }
	if (CInputManager::GetInstance().GetPush(9)) {
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_TITLE;
	}
}

void CSceneRanking::Render() {
	m_Texture.Render(0.0f, 0.0f);

	for (int i = 0; i < 2; i++) {
		CRectangle r;
		CGraphicsUtilities::CalculateStringRect(0, 0, m_RankingMessage[i].c_str(), r);
		float wid = g_pGraphics->GetTargetWidth() / 2;
		float hei = 100 + i * 500;
		CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, m_RankingMessage[i].c_str());
		if (i == m_SelectNo)
			CGraphicsUtilities::RenderString(wid - r.GetWidth() / 2, hei, MOF_XRGB(255, 0, 0), m_RankingMessage[i].c_str());
	}
	for (int i = 0; i < m_ScoreCount; i++) {
		float offset = i < 9 ? 0.0f : -12.0f;

		CGraphicsUtilities::RenderString(
			g_pGraphics->GetTargetWidth() * 0.4f + offset,
			140 + 40 * i, MOF_XRGB(0, 0, 0),
			"%dà Å@%d",
			i + 1, m_Score[i]);
	}
	RenderFade();
}

void CSceneRanking::RenderDebug() {
}

void CSceneRanking::Release() {
	m_Texture.Release();
}