#include "GameApp.h"

#include "Game.h"


CGame g_Game;


MofBool CGameApp::Initialize(void) {
	::CUtilities::SetCurrentDirectory("Resource");

	g_Game.Initialize();
	return TRUE;
}

MofBool CGameApp::Update(void) {
	g_pInput->RefreshKey();

	g_Game.Update();

	return TRUE;
}

MofBool CGameApp::Render(void) {
	g_pGraphics->RenderStart();
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

	g_Game.Render();

	g_pGraphics->RenderEnd();
	return TRUE;
}

MofBool CGameApp::Release(void) {
	g_Game.Release();
	return TRUE;
}