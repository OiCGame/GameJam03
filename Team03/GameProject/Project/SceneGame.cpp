#include "SceneGame.h"
#include	"ResourceManager.h"
#include	"EnemyManager.h"
#include	"Enemy.h"

void CSceneGame::DebugKey()
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
		if (m_WaveNo < 5) {
			this->NextWave(++m_WaveNo);
		}
	}
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CEnemyManager::Singleton().StartMove(5.0f, CVector2(3.5f, 3.5f), TYPE_ALL);
	}
	if (g_pInput->IsKeyPush(MOFKEY_1))
	{
		CEnemyManager::Singleton().StartShot(LauncherInit_Line{ CVector2(0,0),CVector2(10,0), BulletType::red, 20, 0.2f });
	}
	else if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		CEnemyManager::Singleton().StartShot(LauncherInit_Polygon{ CVector2(0,0),CVector2(10,10), BulletType::red, 20, 0.2f });
	}
	else if (g_pInput->IsKeyPush(MOFKEY_3))
	{
		CEnemyManager::Singleton().StartShot(LauncherInit_PolygonRotation{ CVector2(300,0),CVector2(5,5), BulletType::red, 60, 0.2f , 5 , 5, 6 });
	}
}

void CSceneGame::Flow_SetEnemyMove()
{
	// ˆÚ“®‚Ìİ’è
	CEnemyManager::Singleton().StartMove(5.0f, CVector2(3.5f, 3.5f), TYPE_MOVE);
	// Next Flow
	m_NowGameFlow = GameFlow::Enemy_Moving;
}

void CSceneGame::Flow_EnemyMoving()
{
	if (!CEnemyManager::Singleton().IsMoveEnd()) { return; }
	// Next Flow
	m_NowGameFlow = GameFlow::Player_SetShot;
}

void CSceneGame::Flow_SetPlayerShot()
{
	// c’e”‚Ìİ’è
	m_Player.SetBulletRemain(CEnemyManager::Singleton().GetEnemyCount());
	// “G‚ª’e–‹¶¬‚·‚é‚Ü‚Å‚ÌŠÔ
	m_FlowWiatTime = 20;
	// Next Flow
	m_NowGameFlow = GameFlow::Player_Shooting;
}

void CSceneGame::Flow_PlayerShooting()
{
	// XV (ƒvƒŒƒCƒ„[‚ª”­Ë)
	m_Player.Update();

	// “G‚ÌŒ‚’Ä”»’è
	for (auto it = m_Player.GetBullet()->begin(); it != m_Player.GetBullet()->end(); it++) {
		for (int i = CEnemyManager::Singleton().GetEnemyCount() - 1; i >= 0 ; i--)
		{
			if (it->GetCircle().CollisionCircle(CEnemyManager::Singleton().GetEnemy(i)->GetCircle())) {
				CEnemyManager::Singleton().GetEnemy(i)->SetShow(false);
				it->SetShow(false);
			}
		}
	}

	if (m_Player.GetBulletRemain() > 0 && m_FlowWiatTime > 0) {
		m_FlowWiatTime -= CUtilities::GetFrameSecond();
	}
	else {
		if (m_Player.GetBullet()->size() > 0) { return; }
		if (CEnemyManager::Singleton().GetEnemyCount() > 0) {
			// Next Flow
			m_NowGameFlow = GameFlow::Enemy_SetShot;
		}
		else {
			this->NextWave(++m_WaveNo);
		}
	}
}

void CSceneGame::Flow_SetEnemyShot()
{
	// “G‚Ì’e–‹ƒpƒ^[ƒ“‚ğİ’è & ”­Ë
	CEnemyManager::Singleton().StartShot(LauncherInit_Polygon{ CVector2(0,0),CVector2(10,10), BulletType::red, 20, 0.2f });
	// Next Flow
	m_NowGameFlow = GameFlow::Enemy_Shots;
}

void CSceneGame::Flow_EnemyShots()
{
	// XV
	CEnemyBulletManager::Singleton().Update();
	if (CEnemyBulletManager::Singleton().GetBulletList()->size() > 0) {
		// XV (‰ñ”ğ)
		m_Player.Update();
		// ’e–‹‚ÆƒvƒŒƒCƒ„[‚Ì“–‚½‚è”»’è
		if (!m_Player.IsDamageableable()) { return; }
		auto pBulletList = CEnemyBulletManager::Singleton().GetBulletList();
		for (auto it = pBulletList->begin(); it != pBulletList->end(); it++) {
			if (it->CollisionCircle(m_Player.GetCircle())) {
				m_Player.TakeDamage();
			}
		}
	}
	else {
		// Next Flow
		m_NowGameFlow = GameFlow::Enemy_SetMove;
	}
}

void CSceneGame::NextWave(int wave_no)
{
	// GameClear”»’è
	if (wave_no >= m_MaxWave) {
		this->SetNextScene(NextScene::GameClear);
		this->SceneEnd();
		return;
	}
	// GameFlow‚Ì‰Šú‰»
	m_NowGameFlow = GameFlow::Enemy_SetMove;
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
	this->DebugKey();

	// Gameover”»’è
	if (m_Player.GetLife() < 0) {
		this->SetNextScene(NextScene::GameOver);
		this->SceneEnd();
		return;
	}

	switch (m_NowGameFlow)
	{
	case GameFlow::Enemy_SetMove:	this->Flow_SetEnemyMove();	break;
	case GameFlow::Enemy_Moving:		this->Flow_EnemyMoving();	break;
	case GameFlow::Player_SetShot:		this->Flow_SetPlayerShot();	break;
	case GameFlow::Player_Shooting:	this->Flow_PlayerShooting();	break;
	case GameFlow::Enemy_SetShot:	this->Flow_SetEnemyShot();	break;
	case GameFlow::Enemy_Shots:		this->Flow_EnemyShots();		break;
	}

	CEnemyManager::Singleton().Update();
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
	CGraphicsUtilities::RenderString(0, 120, "wait time => %0.3f", m_FlowWiatTime);
	CGraphicsUtilities::RenderString(0, 150, "flow NO => %d", m_NowGameFlow);

}

void CSceneGame::Release()
{
	CEnemyManager::Singleton().Release();
}
