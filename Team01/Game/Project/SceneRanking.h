#pragma once
#include "SceneBase.h"

class CSceneRanking : public CSceneBase
{
private:
	static const int m_ScoreCount = 10;
	int		m_Score[m_ScoreCount];

	std::string		m_RankingMessage[2] = { "ランキング","PRESS ENTER KEY : タイトルに戻る" };
public:
	CSceneRanking();
	~CSceneRanking();

	bool Load();
	void Initialize();
	void Update();
	void Render();
	void RenderDebug(void);
	void Release();
};

