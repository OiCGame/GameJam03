#include "SceneGameClear.h"

void CSceneGameClear::Initialize()
{
}

void CSceneGameClear::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		this->SetNextScene(NextScene::Title);
		this->SceneEnd();
	}
}

void CSceneGameClear::Render()
{
}

void CSceneGameClear::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 0, "GameClear");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenTitle");
}

void CSceneGameClear::Release()
{
}
