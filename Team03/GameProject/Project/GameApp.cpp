/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

#include	"ResourceManager.h"
#include	"SceneTitle.h"
#include	"SceneGame.h"
#include	"SceneGameClear.h"
#include	"SceneGameOver.h"

std::unique_ptr<CSceneBase> gpSecene(new CSceneTitle());

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	CUtilities::SetFPS(60);
	g_pGraphics->SetScreenSize(1920, 1080);
	//素材フォルダの指定
	CUtilities::SetCurrentDirectory("Resource");
	
	CResourceManager::Singleton()
		// 画像の読み込み
		.LoadTexture("GameClear", "images/background/game_clear.png")
		.LoadTexture("GameOver", "images/background/game_over.png")
		.LoadTexture("Player", "images/player/PlayerUFO.png")
		.LoadTexture("PlayerBullet", "images/player/PlayerBullet.png")
		.LoadTexture("PlayerArrow", "images/player/PlayerArrow.png")
		.LoadTexture("PlayerArrow", "images/item/ItemLife.png")
		// 音の読み込み
		.LoadSound("bgm_title", "sounds/BGM/title.mp3");


	gpSecene->Initialize();

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//キーの更新
	g_pInput->RefreshKey();

	gpSecene->Update();

	if (gpSecene->IsSceneEnd()) {
		switch (gpSecene->NextScene())
		{
		case NextScene::Title:
			gpSecene.reset(new CSceneTitle());
			break;
		case NextScene::Game:
			gpSecene.reset(new CSceneGame());
			break;
		case NextScene::GameClear:
			gpSecene.reset(new CSceneGameClear());
			break;
		case NextScene::GameOver:
			gpSecene.reset(new CSceneGameOver());
			break;
		default:
			break;
		}
		gpSecene->Initialize();
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	gpSecene->Render();
	gpSecene->RenderDebug();

	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void){
	gpSecene->Release();
	CResourceManager::Singleton().Release();
	return TRUE;
}