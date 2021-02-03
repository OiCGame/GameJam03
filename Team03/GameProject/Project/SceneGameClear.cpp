#include "SceneGameClear.h"

#include	"ResourceManager.h"

void CSceneGameClear::Initialize()
{
	m_pBackground = &CResourceManager::Singleton().GetTextureList()->at("GameClear");
}

void CSceneGameClear::Update()
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
