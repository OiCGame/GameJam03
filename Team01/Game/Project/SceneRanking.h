#pragma once
#include "SceneBase.h"

class CSceneRanking : public CSceneBase
{
private:
	static const int m_ScoreCount = 10;
	int		m_Score[m_ScoreCount];

	std::string		m_RankingMessage[2] = { "�����L���O","PRESS ENTER KEY : �^�C�g���ɖ߂�" };
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

