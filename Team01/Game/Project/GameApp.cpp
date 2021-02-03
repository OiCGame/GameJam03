#include	"GameApp.h"


#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
#include "SceneRanking.h"

CSceneBase* g_pScene = NULL;
bool g_bDebug = false;

MofBool CGameApp::Initialize(void) {
	::CUtilities::SetCurrentDirectory("Resource");

	g_pScene = new CSceneTitle();
	return TRUE;
}

MofBool CGameApp::Update(void) {
	g_pInput->RefreshKey();
	::CInputManager::GetInstance().Refresh();

	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		g_bDebug = !g_bDebug;
	}

	g_pScene->Update();
	if (g_pScene->IsEnd())
	{
		int change = g_pScene->GetNextScene();
		g_pScene->Release();
		delete g_pScene;

		switch (change)
		{
		case SCENENO_TITLE:
			g_pScene = new CSceneTitle();
			g_pScene->SetScene(SCENENO_TITLE);
			break;
		case SCENENO_GAME:
			g_pScene = new CSceneGame();
			g_pScene->SetScene(SCENENO_GAME);
			break;
		case SCENENO_GAMEOVER:
			g_pScene = new CSceneGameOver();
			g_pScene->SetScene(SCENENO_GAMEOVER);
			break;
		case SCENENO_GAMECLEAR:
			g_pScene = new CSceneGameClear();
			g_pScene->SetScene(SCENENO_GAMECLEAR);
			break;
		case SCENENO_RANKING:
			g_pScene = new CSceneRanking();
			g_pScene->SetScene(SCENENO_RANKING);
			break;
		default:
			break;
		}
		g_pScene->Initialize();
	}

	return TRUE;
}


MofBool CGameApp::Render(void) {
	g_pGraphics->RenderStart();

	g_pGraphics->ClearTarget(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0);


	g_pScene->Render();
	if (g_bDebug)
	{
		g_pScene->RenderDebug();
	}

	g_pGraphics->RenderEnd();
	return TRUE;
}

MofBool CGameApp::Release(void) {
	//g_Game.Release();
	g_pScene->Release();
	if (g_pScene)
	{
		delete g_pScene;
		g_pScene = NULL;
	}
	return TRUE;
}