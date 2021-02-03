#pragma once
#include "SceneBase.h"

class CSceneGameClear : public CSceneBase
{
private:
	static const int m_MessageCount = 2;
	std::string		m_OptionMessage[m_MessageCount] = { "�Q�[���N���A�[","Pless Space : �^�C�g���ɖ߂�" };
public:
	CSceneGameClear();
	~CSceneGameClear();
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};