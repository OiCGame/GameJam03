#pragma once
#include "SceneBase.h"

class CSceneTitle : public CSceneBase
{
private:
	static const int m_MessageCount = 3;
	std::string		m_Message[m_MessageCount] = { "連鎖するシューティング","ゲームスタート", "ランキング" };
public:
	CSceneTitle();
	~CSceneTitle();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};