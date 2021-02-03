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
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEndStart = true;
		m_NextSceneNo = SCENENO_GAMECLEAR;
	}
	if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
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