#pragma once

#include	"SceneBase.h"

class CSceneTitle : public CSceneBase
{
private:
	CTexture* m_pTexture;
	CSoundBuffer* m_pBGM;

public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

