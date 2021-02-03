#pragma once
#include "SceneBase.h"

class CSceneTitle : public CSceneBase
{
private:
	static const int m_MessageCount = 2;
	std::string		m_OptionMessage[m_MessageCount] = { "�A������V���[�e�B���O","Pless Space : Start" };
public:
	CSceneTitle();
	~CSceneTitle();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};