#include "SceneGameClear.h"

#include	"ResourceManager.h"

void CSceneGameClear::Initialize()
{
	m_pBackground = &CResourceManager::Singleton().GetTextureList()->at("GameClear");
	m_pBGM = &CResourceManager::Singleton().GetSoundList()->at("bgm_clear");
	m_pBGM->SetLoop(true);
	m_pBGM->SetVolume(0.1f);
	m_pSE = &CResourceManager::Singleton().GetSoundList()->at("se_decision");

	m_pBGM->Play();
}

void CSceneGameClear::Update()
{
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

void CSceneGameClear::Render()
{
}

void CSceneGameClear::RenderDebug()
{
	m_pBackground->Render(0, 0);

	CGraphicsUtilities::RenderString(0, 0, "GameClear");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenTitle");
}

void CSceneGameClear::Release()
{
}
