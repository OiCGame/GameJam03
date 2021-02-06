#include "SceneTitle.h"

#include	"ResourceManager.h"

void CSceneTitle::Initialize()
{
	CSceneBase::Initialize();
	m_pTexture = &CResourceManager::Singleton().GetTextureList()->at("Title");
	m_pTextureLevel1 = &CResourceManager::Singleton().GetTextureList()->at("Level1");
	m_pTextureLevel2 = &CResourceManager::Singleton().GetTextureList()->at("Level2");
	m_pTextureLevel3 = &CResourceManager::Singleton().GetTextureList()->at("Level3");
	m_pBGM = &CResourceManager::Singleton().GetSoundList()->at("bgm_title");
	m_pBGM->SetLoop(true);
	m_pBGM->SetVolume(0.1f);
	m_pSE = &CResourceManager::Singleton().GetSoundList()->at("se_decision");
	m_pSE->SetVolume(0.5f);
	m_pBGM->Play();
}

void CSceneTitle::Update()
{
	CSceneBase::Update();

	if (g_pInput->IsKeyPush(MOFKEY_S))
	{
		titleMenuIndex++;
		if (titleMenuIndex >= 3) {
			titleMenuIndex = 0;
		}
	}
	else if (g_pInput->IsKeyPush(MOFKEY_W))
	{
		titleMenuIndex--;
		if (titleMenuIndex < 0) {
			titleMenuIndex += 3;
		}
	}

	//if (g_pInput->IsKeyPush(MOFKEY_F1)) {
	//	m_pBGM->Stop();

	//	this->SetNextScene(NextScene::Game);
	//	this->SceneEnd();
	//}

	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
		m_pBGM->Stop();
		m_pSE->Play();

		switch (titleMenuIndex)
		{
		case 0:
			this->SetNextScene(NextScene::Game1);
			break;
		case 1:
			this->SetNextScene(NextScene::Game2);
			break;
		case 2:
			this->SetNextScene(NextScene::Game3);
			break;
		}

		this->SceneEnd();
	}
}

void CSceneTitle::Render()
{
	m_pTexture->Render(0, 0);

	float scale[] = { 1 , 1, 1 };
	scale[titleMenuIndex] = 1.2f;

	m_pTextureLevel1->RenderScale(1470,760, scale[0], TEXALIGN_CENTERCENTER);
	m_pTextureLevel2->RenderScale(1470,840, scale[1], TEXALIGN_CENTERCENTER);
	m_pTextureLevel3->RenderScale(1470,920, scale[2], TEXALIGN_CENTERCENTER);

	CSceneBase::Render();
}

void CSceneTitle::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 0, "Title");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenGame");
}

void CSceneTitle::Release()
{
}
