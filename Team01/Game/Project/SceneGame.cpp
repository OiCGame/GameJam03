#include "SceneGame.h"

CSceneGame::CSceneGame() {

}

CSceneGame::~CSceneGame() {

}

void CSceneGame::Initialize() {
	m_Game.Initialize();
}

void CSceneGame::Update() {
	m_Game.Update();
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextSceneNo = SCENENO_GAMECLEAR;
	}
	if (g_pInput->IsKeyPush(MOFKEY_F3))
	{
		m_bEnd = true;
		m_NextSceneNo = SCENENO_GAMEOVER;
	}
}

void CSceneGame::Render() {
	m_Game.Render();
}

void CSceneGame::RenderDebug() {

}

void CSceneGame::Release() {
	m_Game.Release();
}