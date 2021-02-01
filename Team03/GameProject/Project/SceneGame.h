#pragma once

#include	 "SceneBase.h"

class CSceneGame : public CSceneBase
{
public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

