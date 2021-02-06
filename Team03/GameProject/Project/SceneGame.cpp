#include "SceneGame.h"
#include	"ResourceManager.h"
#include	"EnemyManager.h"
#include	"Enemy.h"

#include	"EffectManager.h"

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
		CEnemyManager::Singleton().StartMove(5.0f, CVector2(3.5f, 3.5f), TYPE_ALL, 1.0f);
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
	// 移動の設定

	CEnemyManager::Singleton().StartMove(
		m_EnemyMoveTime[m_WaveNo],
		CVector2(stageData[m_WaveNo].EnemySpeed, stageData[m_WaveNo].EnemySpeed),
		TYPE_ALL,
		m_EnemyTeleportInterval[m_WaveNo]
	);

	// Next Flow
	m_NowGameFlow = GameFlow::Enemy_Moving;
}

void CSceneGame::Flow_EnemyMoving()
{
	m_Player.MoveUpdate();
	if (!CEnemyManager::Singleton().IsMoveEnd()) { return; }
	// Next Flow
	m_NowGameFlow = GameFlow::Player_SetShot;
}

void CSceneGame::Flow_SetPlayerShot()
{
	// 残弾数の設定
	m_Player.SetBulletRemain(CEnemyManager::Singleton().GetEnemyCount());
	// 敵が弾幕生成するまでの時間
	m_FlowWaitTime = cm_WaitTime;
	// Next Flow
	m_NowGameFlow = GameFlow::Player_Shooting;
}

void CSceneGame::Flow_PlayerShooting()
{
	// 更新 (プレイヤーが発射)
	m_Player.Update();

	// 敵の撃墜判定
	for (auto pPlayer = m_Player.GetBullet()->begin(); pPlayer != m_Player.GetBullet()->end(); pPlayer++) {
		for (int i = CEnemyManager::Singleton().GetEnemyCount() - 1; i >= 0 ; i--)
		{
			auto pEnemy = CEnemyManager::Singleton().GetEnemy(i);
			if (pPlayer->GetCircle().CollisionCircle(pEnemy->GetCircle())) {
				pEnemy->SetShow(false);
				pPlayer->SetShow(false);
				m_pSE_Explosion->Play();
				// エフェクト追加
				CEffectManager::Singleton().addEffect(
					&CResourceManager::Singleton().GetTextureList()->at("effect_explosion"),
					pEnemy->GetCenterPos()
				);
			}
		}
	}

	
	if (CEnemyManager::Singleton().GetEnemyCount() > 0) {
		if (m_Player.GetBulletRemain() > 0 && m_FlowWaitTime > 0) {
			m_FlowWaitTime -= CUtilities::GetFrameSecond();
		}
		else {
			if (m_Player.GetBullet()->size() > 0) { return; }
			// Next Flow
			m_NowGameFlow = GameFlow::Enemy_SetShot;
		}
	}
	else {
		if (CEffectManager::Singleton().FinishedAll()) {
			this->NextWave(++m_WaveNo);
		}
	}

}

void CSceneGame::Flow_SetEnemyShot()
{
	// 敵の弾幕パターンを設定 & 発射
	CEnemyManager::Singleton().StartShot(LauncherInit_PolygonRotation{ CVector2(300,0),CVector2(5,5), BulletType::purple, 60, 0.2f , 5 , 5, 6 });
	// Next Flow
	m_NowGameFlow = GameFlow::Enemy_Shots;
}

void CSceneGame::Flow_EnemyShots()
{
	// 更新
	CEnemyBulletManager::Singleton().Update();
	if (CEnemyBulletManager::Singleton().GetBulletList()->size() > 0) {
		// 更新 (回避)
		m_Player.Update();
		// lifeの更新
		m_pUI_Life = &CResourceManager::Singleton().GetTextureList()->at(m_UI_LifeTexture[m_Player.GetLife()]);
		// 弾幕とプレイヤーの当たり判定
		if (!m_Player.IsDamageableable()) { return; }
		auto pBulletList = CEnemyBulletManager::Singleton().GetBulletList();
		for (auto pEnemyBullet = pBulletList->begin(); pEnemyBullet != pBulletList->end(); pEnemyBullet++) {
			if (pEnemyBullet->CollisionCircle(m_Player.GetCircle())) {
				m_Player.TakeDamage();
				m_pSE_Explosion->Play();
				// エフェクト追加
				CEffectManager::Singleton().addEffect(
					&CResourceManager::Singleton().GetTextureList()->at("effect_explosion"),
					m_Player.GetPostion()
				);
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
	// GameClear判定
	if (wave_no > m_MaxWave) {
		m_WaveNo = m_MaxWave;
		this->SetNextScene(NextScene::GameClear);
		this->SceneEnd();
		return;
	}
	// GameFlowの初期化
	m_NowGameFlow = GameFlow::Enemy_SetMove;
	m_FlowWaitTime = cm_WaitTime;
	// 敵Statusの再設定
	CEnemyManager::Singleton().Release();
	// 敵の量を設定
	for (int i = 0; i < stageData[m_WaveNo].EnemyAmount; i++)
	{
		auto enemy = std::make_shared<CEnemy>();
		enemy->Initialize();
		CEnemyManager::Singleton().AddEnemy(enemy);
	}
	//移動位置の登録
	for (const auto & cloud : stageData[m_WaveNo].CloudPositions)
	{
		CEnemyManager::Singleton().AddMoveCloud(cloud);
	}

	// 雲の画像を再設定
	// BGMの設定
	if (wave_no < 4) {
		m_pCloudTexture_left = &CResourceManager::Singleton().GetTextureList()->at("cloud_left");
		m_pCloudTexture_right = &CResourceManager::Singleton().GetTextureList()->at("cloud_right");
		auto pS = &CResourceManager::Singleton().GetSoundList()->at("bgm_stage123");
		if (m_pBGM != pS) {
			if (m_pBGM) { m_pBGM->Stop(); }
			m_pBGM = pS; 
			m_pBGM->SetVolume(0.05f);
			m_pBGM->SetLoop(true);
			m_pBGM->Play();
		}
	}
	else {
		m_pCloudTexture_left = &CResourceManager::Singleton().GetTextureList()->at("cloud_gray_left");
		m_pCloudTexture_right = &CResourceManager::Singleton().GetTextureList()->at("cloud_gray_right");
		auto pS = &CResourceManager::Singleton().GetSoundList()->at("bgm_stage456");
		if (m_pBGM != pS) {
			if (m_pBGM) { m_pBGM->Stop(); }
			m_pBGM = pS; 
			m_pBGM->SetVolume(0.05f);
			m_pBGM->SetLoop(true);
			m_pBGM->Play();
		}

	}

	// Itemの再設定
	if (wave_no >= 3 && m_Player.GetLife() < 5) {
		m_Item.Initialize(CVector2(
			CUtilities::Random(g_pGraphics->GetTargetWidth() * 0.1, g_pGraphics->GetTargetWidth() * 0.9),
			-30
		));
	}


	// 背景の再設定
	m_pBackgroundTexture = &CResourceManager::Singleton().GetTextureList()->at(m_WaveBackground[wave_no]);
	// UIの更新
	m_pUI_Wave = &CResourceManager::Singleton().GetTextureList()->at(m_UI_WaveTexture[m_WaveNo]);
}

void CSceneGame::Initialize()
{
	CSceneBase::Initialize();
	DESIGNVECTOR design;
	AddFontResourceEx(TEXT("LightNovelPOPv2.otf"), FR_PRIVATE, &design);
	LOGFONT lf = {
	64,0,0,0,0,0,0,0,
	SHIFTJIS_CHARSET,
	OUT_TT_ONLY_PRECIS,
	CLIP_DEFAULT_PRECIS,
	PROOF_QUALITY,
	FIXED_PITCH | FF_MODERN,
	TEXT("ラノベPOP v2")
	};
	HFONT hFont = CreateFontIndirect(&lf);
	font.Create(hFont);
	m_pSE_Explosion = &CResourceManager::Singleton().GetSoundList()->at("se_explosion");
	m_pSE_Explosion->SetVolume(0.3f);
	
	m_Player.Initialize(CVector2(g_pGraphics->GetTargetWidth()*0.5f, g_pGraphics->GetTargetHeight()*0.5f));
	
	m_pUI_Life = &CResourceManager::Singleton().GetTextureList()->at(m_UI_LifeTexture[m_Player.GetLife()]);

	CEnemyManager::Singleton().Initialize(); // ResetEnemies()内に移植するかも？
	this->NextWave(m_WaveNo);


}

void CSceneGame::Update()
{
	CSceneBase::Update();
	//this->DebugKey();

	// Gameover判定
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

	m_Item.Update();
	if (m_Item.IsShow()) {
		if (m_Player.ItemCollisionCheck(m_Item)) {
			m_pUI_Life = &CResourceManager::Singleton().GetTextureList()->at(m_UI_LifeTexture[m_Player.GetLife()]);
			m_Item.m_bShow = false;
		}
	}
	

	CEnemyManager::Singleton().Update();
	CEffectManager::Singleton().Update();
}

void CSceneGame::Render()
{
	m_pBackgroundTexture->Render(0, 0);

	CEnemyBulletManager::Singleton().Render();
	CEnemyManager::Singleton().Render();

	m_Item.Render();

	for (const auto & cloud : stageData[m_WaveNo].CloudPositions) {
		auto texture = cloud.Right ? m_pCloudTexture_right : m_pCloudTexture_left;
		texture->RenderScale(cloud.Pos.x, cloud.Pos.y, 0.9f ,TextureAlignment::TEXALIGN_CENTERCENTER);
	}

	// effect
	CEffectManager::Singleton().Render();

	m_Player.Render();

	m_pUI_Life->Render(5, 8);
	m_pUI_Wave->Render(m_pUI_Life->GetWidth() + 5, 15);
	font.RenderFormatString(1000, 0, MOF_XRGB(255, 0, 0), "%d", (int)m_FlowWaitTime);

	if (m_WaveNo == 0) {
		if (m_NowGameFlow == GameFlow::Player_Shooting) {
			CResourceManager::Singleton().GetTextureList()->at("tutorial_AttackText").Render(g_pGraphics->GetTargetWidth()*0.5, 100, TextureAlignment::TEXALIGN_TOPCENTER);
		}
	}

	CSceneBase::Render();
}

void CSceneGame::RenderDebug()
{
	m_Player.RenderDebug(450, 0);
	CGraphicsUtilities::RenderString(0, 0, "Game");	
	CGraphicsUtilities::RenderString(0, 30, "push to F1 => next SecenGameClear");
	CGraphicsUtilities::RenderString(0, 60, "push to F2 => next SecenGameOver");
	CGraphicsUtilities::RenderString(0, 90, "push to F3 => next wave");
	CGraphicsUtilities::RenderString(0, 120, "wait time => %0.3f", m_FlowWaitTime);
	CGraphicsUtilities::RenderString(0, 150, "flow NO => %d", m_NowGameFlow);
}

void CSceneGame::Release()
{
	font.Release();
	DESIGNVECTOR design;
	RemoveFontResourceEx(TEXT("LightNovelPOPv2.otf"), FR_PRIVATE,&design);
	CEffectManager::Singleton().Release();
	CEnemyBulletManager::Singleton().Release();
	CEnemyManager::Singleton().Release();
	m_pBGM->Stop();
}
