#pragma once
#include "SceneBase.h"
#include "Game.h"

class CSceneGame : public CSceneBase
{
private:
	CGame m_Game;
public:
	CSceneGame();
	~CSceneGame();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};

