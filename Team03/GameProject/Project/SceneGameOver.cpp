#include "SceneGameOver.h"

#include	"ResourceManager.h"

void CSceneGameOver::Initialize()
{
	m_pBackground = &CResourceManager::Singleton().GetTextureList()->at("GameOver");
}

void CSceneGameOver::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		this->SetNextScene(NextScene::Title);
		this->SceneEnd();
	}

	if (g_pInput->IsKeyPush(MOFKEY_SPACE)) {
		this->SetNextScene(NextScene::Title);
		this->SceneEnd();
	}
}

void CSceneGameOver::Render()
{
}

void CSceneGameOver::RenderDebug()
{
	m_pBackground->Render(0, 0);

	CGraphicsUtilities::RenderString(0, 0, "GameOver");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenTitle");
}

void CSceneGameOver::Release()
{
}
