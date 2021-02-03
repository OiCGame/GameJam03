#pragma once
#include "SceneBase.h"

class CSceneGameOver : public CSceneBase
{
private:
	static const int m_MessageCount = 2;
	std::string		m_OptionMessage[m_MessageCount] = { "ゲームオーバー","Pless Space : タイトルに戻る" };
public:
	CSceneGameOver();
	~CSceneGameOver();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};