#include "SceneGameOver.h"

void CSceneGameOver::Initialize()
{
}

void CSceneGameOver::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		this->SetNextScene(NextScene::Title);
		this->SceneEnd();
	}
}

void CSceneGameOver::Render()
{
}

void CSceneGameOver::RenderDebug()
{
	CGraphicsUtilities::RenderString(0, 0, "GameOver");
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenTitle");
}

void CSceneGameOver::Release()
{
}
