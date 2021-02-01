#pragma once

#include "SceneBase.h"

class CSceneGameClear : public CSceneBase
{
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

