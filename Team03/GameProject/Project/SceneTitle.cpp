#include "SceneTitle.h"

#include	"ResourceManager.h"

void CSceneTitle::Initialize()
{
	m_pBGM = &CResourceManager::Singleton().GetSoundList()->at("bgm_title");
	m_pBGM->SetLoop(true);
	m_pBGM->SetVolume(0.1f);

	m_pBGM->Play();
}

void CSceneTitle::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		m_pBGM->Stop();

		this->SetNextScene(NextScene::Game);
		this->SceneEnd();
	}
}

void CSceneTitle::Render()
{
}

void CSceneTitle::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 0, "Title");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenGame");
}

void CSceneTitle::Release()
{
}
