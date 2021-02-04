#include "SceneGame.h"
#include	"ResourceManager.h"
#include	"EnemyManager.h"
#include	"Enemy.h"

void CSceneGame::NextWave(int wave_no)
{
	// “GStatus‚ÌÄİ’è
	CEnemyManager::Singleton().Release();
	// “G‚Ì—Ê‚ğİ’è
	for (int i = 0; i < m_EnemyCount[wave_no]; i++)
	{
		auto enemy = std::make_shared<CEnemy>();
		enemy->Initialize();
		CEnemyManager::Singleton().AddEnemy(enemy);
	}
	//ˆÚ“®ˆÊ’u‚Ì“o˜^
	for (const auto & pos : m_CloudPositions[wave_no])
	{
		CEnemyManager::Singleton().AddMovePos(CVector2(pos[0], pos[1]));
	}

	// ‰_‚Ì‰æ‘œ‚ğÄİ’è
	if (wave_no < 4) {
		m_pCloudTexture = &CResourceManager::Singleton().GetTextureList()->at("cloud_left");
	}
	else {
		m_pCloudTexture = &CResourceManager::Singleton().GetTextureList()->at("cloud_gray_left");
	}
	// ”wŒi‚ÌÄİ’è
	m_pBackgroundTexture = &CResourceManager::Singleton().GetTextureList()->at(m_WaveBackground[wave_no]);
}

void CSceneGame::Initialize()
{

	m_Player.Initialize(CVector2(500, 500));

	CEnemyManager::Singleton().Initialize(); // ResetEnemies()“à‚ÉˆÚA‚·‚é‚©‚àH
	this->NextWave(m_WaveNo);
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
	if (g_pInput->IsKeyPush(MOFKEY_F3)) {
		if(m_WaveNo < 5){
			this->NextWave(++m_WaveNo);
		}
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
	m_pBackgroundTexture->Render(0, 0);

	CEnemyBulletManager::Singleton().Render();
	CEnemyManager::Singleton().Render();

	for (const auto & pos : m_CloudPositions[m_WaveNo]) {
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
	CGraphicsUtilities::RenderString(0, 90, "push to F3 => next wave");
}

void CSceneGame::Release()
{
	CEnemyManager::Singleton().Release();
}
