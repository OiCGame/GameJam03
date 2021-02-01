#include "SceneTitle.h"

void CSceneTitle::Initialize()
{
}

void CSceneTitle::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
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
