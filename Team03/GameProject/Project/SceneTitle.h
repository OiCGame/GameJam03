#pragma once

#include	"SceneBase.h"

class CSceneTitle : public CSceneBase
{
private:
	CTexture* m_pTexture;
	CTexture* m_pTextureLevel1;
	CTexture* m_pTextureLevel2;
	CTexture* m_pTextureLevel3;
	CSoundBuffer* m_pBGM;
	CSoundBuffer* m_pSE;

	int titleMenuIndex = 0;
public:
	void Initialize() override;
	void Update()  override;
	void Render()  override;
	void RenderDebug() override;
	void Release()  override;
};

