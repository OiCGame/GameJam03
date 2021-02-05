#pragma once

#include	"SceneBase.h"

class CSceneTitle : public CSceneBase
{
private:
	CTexture* m_pTexture;
	CSoundBuffer* m_pBGM;
	CSoundBuffer* m_pSE;

public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

