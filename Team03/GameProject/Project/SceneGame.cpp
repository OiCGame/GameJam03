#include "SceneGame.h"
#include	"ResourceManager.h"
#include	"EnemyManager.h"
#include	"Enemy.h"

void CSceneGame::Initialize()
{
	m_pCloudTexture = &CResourceManager::Singleton().GetTextureList()->at("cloud_left");

	m_Player.Initialize(CVector2(500, 500));

	CEnemyManager::Singleton().Initialize();
	for (int i = 0; i < 2; i++)
	{
		auto enemy = std::make_shared<CEnemy>();
		enemy->Initialize();
		//enemy->SetMoveParameter(CVector2(450*(i+1), 200), TYPE_MOVE, CVector2(3.5f, 3.5f));
		CEnemyManager::Singleton().AddEnemy(enemy);
	}


	//ˆÚ“®ˆÊ’u‚Ì“o˜^
	for (int i = 0; i < 6; i++)
	{
		int x = CUtilities::Random(CGraphicsUtilities::GetGraphics()->GetTargetWidth());
		int y = CUtilities::Random(CGraphicsUtilities::GetGraphics()->GetTargetHeight());
		CEnemyManager::Singleton().AddMovePos(CVector2(x, y));
	}
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

	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CEnemyManager::Singleton().StartMove(5.0f, CVector2(3.5f, 3.5f), TYPE_ALL);
	}
	CEnemyManager::Singleton().Update();

	//LauncherInit_Line{ CVector2(0,100),CVector2(10,0), BulletType::red, 20, 0.2f }
	//LauncherInit_Polygon{ CVector2(0,100),CVector2(10,0), BulletType::red, 20, 0.2f }
	//LauncherInit_PolygonRotation{ CVector2(300,300),CVector2(5,5), BulletType::red, 60, 0.2f , 5 , 5, 6 }

	CEnemyBulletManager::Singleton().Update();
}

void CSceneGame::Render()
{
	CEnemyBulletManager::Singleton().Render();
	CEnemyManager::Singleton().Render();

	for (const auto & pos : m_CloudPositions[0]) {
		m_pCloudTexture->Render(
			pos[0] - m_pCloudTexture->GetWidth()*0.5f,
			pos[1] - m_pCloudTexture->GetHeight() * 0.5f
		);
	}

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
	CEnemyManager::Singleton().Release();
}
