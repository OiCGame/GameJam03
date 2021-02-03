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

	//LauncherInit_Line{ CVector2(0,100),CVector2(10,0), BulletType::red, 20, 0.2f }
	//LauncherInit_Polygon{ CVector2(0,100),CVector2(10,0), BulletType::red, 20, 0.2f }
	//LauncherInit_PolygonRotation{ CVector2(300,300),CVector2(5,5), BulletType::red, 60, 0.2f , 5 , 5, 6 }

	CEnemyBulletManager::Singleton().Update();
}

void CSceneGame::Render()
{
	CEnemyBulletManager::Singleton().Render();
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
