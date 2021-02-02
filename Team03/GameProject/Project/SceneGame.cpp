#include "SceneGame.h"

void CSceneGame::Initialize()
{
	m_Player.Initialize(CVector2(500, 500));
}

void CSceneGame::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		this->SetNextScene(NextScene::GameClear);
		this->SceneEnd();
	}
	if (g_pInput->IsKeyPush(MOFKEY_F2)) {
		this->SetNextScene(NextScene::GameOver);
		this->SceneEnd();
	}
	m_Player.Update();
}

void CSceneGame::Render()
{
	m_Player.Render();
}

void CSceneGame::RenderDebug()
{
	m_Player.RenderDebug(450, 0);
	CGraphicsUtilities::RenderString(0, 0, "Game");	
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenGameClear");
	CGraphicsUtilities::RenderString(0, 60, "push to F2 => next SecenGameOver");
}

void CSceneGame::Release()
{
}
