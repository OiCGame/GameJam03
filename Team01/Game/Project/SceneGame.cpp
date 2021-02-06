#include "SceneGame.h"

CSceneGame::CSceneGame() {
}

CSceneGame::~CSceneGame() {
}

bool CSceneGame::Load() {
	return false;
}

void CSceneGame::Initialize() {
	m_Game.Initialize();
}

void CSceneGame::Update() {
	FadeInOut();
	if (m_bEndStart) { return; }
	m_Game.Update();
	//	if (g_pInput->IsKeyPush(MOFKEY_F2)) {
	if (m_Game.GetPhaseNo() == 2)
	{
		m_Alpha = 255;
	}

//	if (m_Game.IsAllPhaseEnd()) {
	if (m_Game.BossDead()) {
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_GAMECLEAR;
	}
	//	if (g_pInput->IsKeyPush(MOFKEY_F3)) {
	if (m_Game.IsPlayerDead()) {
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_GAMEOVER;
	}
}

void CSceneGame::Render() {
	m_Game.Render();
	RenderFade();
}

void CSceneGame::RenderDebug() {

}

void CSceneGame::Release() {
	m_Game.Release();
}