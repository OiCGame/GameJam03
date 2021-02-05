#include "SceneTitle.h"

#include	"ResourceManager.h"

void CSceneTitle::Initialize()
{
	m_pTexture = &CResourceManager::Singleton().GetTextureList()->at("Title");
	m_pBGM = &CResourceManager::Singleton().GetSoundList()->at("bgm_title");
	m_pBGM->SetLoop(true);
	m_pBGM->SetVolume(0.1f);
	m_pSE = &CResourceManager::Singleton().GetSoundList()->at("se_decision");

	m_pBGM->Play();
}

void CSceneTitle::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		m_pBGM->Stop();

		this->SetNextScene(NextScene::Game);
		this->SceneEnd();
	}

	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
		m_pBGM->Stop();
		m_pSE->Play();

		this->SetNextScene(NextScene::Game);
		this->SceneEnd();
	}
}

void CSceneTitle::Render()
{
	m_pTexture->Render(0, 0);
}

void CSceneTitle::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 0, "Title");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenGame");
}

void CSceneTitle::Release()
{
}
