#include "SceneGameOver.h"

#include	"ResourceManager.h"

void CSceneGameOver::Initialize()
{
	CSceneBase::Initialize();
	m_pBackground = &CResourceManager::Singleton().GetTextureList()->at("GameOver");
	m_pBGM = &CResourceManager::Singleton().GetSoundList()->at("bgm_over");
	m_pBGM->SetLoop(true);
	m_pBGM->SetVolume(0.1f);
	m_pSE = &CResourceManager::Singleton().GetSoundList()->at("se_decision");

	m_pBGM->Play();
}

void CSceneGameOver::Update()
{
	CSceneBase::Update();
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		m_pBGM->Stop();
		this->SetNextScene(NextScene::Title);
		this->SceneEnd();
	}

	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
		m_pBGM->Stop();
		this->SetNextScene(NextScene::Title);
		this->SceneEnd();
	}
}

void CSceneGameOver::Render()
{
	m_pBackground->Render(0, 0);
	CSceneBase::Render();
}

void CSceneGameOver::RenderDebug()
{

	CGraphicsUtilities::RenderString(0, 0, "GameOver");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenTitle");
}

void CSceneGameOver::Release()
{
}
