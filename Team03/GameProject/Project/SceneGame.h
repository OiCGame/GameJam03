#pragma once
#include	 "Mof.h"
#include	 "SceneBase.h"
#include	 "Player.h"

class CSceneGame : public CSceneBase
{
private:
	CPlayer m_Player;

public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

