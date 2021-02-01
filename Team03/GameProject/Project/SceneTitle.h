#pragma once

#include	"SceneBase.h"

class CSceneTitle : public CSceneBase
{
public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

