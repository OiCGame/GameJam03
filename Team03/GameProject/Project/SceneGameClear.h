#pragma once

#include "SceneBase.h"

class CSceneGameClear : public CSceneBase
{
private:
	CTexture* m_pBackground;
	CSoundBuffer* m_pBGM;
	CSoundBuffer* m_pSE;

public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

