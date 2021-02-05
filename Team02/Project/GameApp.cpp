/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

//SCENE
#include    "Title.h"
#include    "Game.h"
#include    "GameClear.h"
#include    "GameOver.h"

//MANAGER
#include    "SoundManager.h"
#include    "EffectManager.h"

/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {
	
    CUtilities::SetCurrentDirectory("Resource");

    m_BackTexture.Load("UI/共通/背景.png");

    // サウンドデータの読み込み
    g_SoundManager.Load();
    // エフェクトデータの読み込み
    g_EffectManager.Load();

    // SceneManagerに各シーンの追加とフェードカラーの設定
    m_SceneManager
        .Add<CTitle>(SceneName::Title)
        .Add<CGame>(SceneName::Game)
        .Add<CGameClear>(SceneName::GameClear)
        .Add<CGameOver>(SceneName::GameOver)
        .SetFadeColor(MOF_COLOR_WHITE);

    m_SceneManager.Initialize(SceneName::Title);
#ifdef _DEBUG
    // DEBUG : デバッグ用でゲームシーンからスタートする
    //m_SceneManager.Initialize(SceneName::Game);
#endif //_DEBUG

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void) {
	//キーの更新
	g_pInput->RefreshKey();
    // サウンドデータの更新
    g_SoundManager.Update();
    // エフェクトの更新
    g_EffectManager.Update();

    // ESCキーで終了
    if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
    {
        PostQuitMessage(0);
    }

    // シーンマネージャーの更新
    if (!m_SceneManager.Update())
    {
        return FALSE;
    }

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void) {
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

    m_BackTexture.Render(0, 0);

    // シーンマネージャーの描画
    if (!m_SceneManager.Render())
    {
        return FALSE;
    }

    // エフェクトの描画
    g_EffectManager.Render();

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
MofBool CGameApp::Release(void) {

    m_BackTexture.Release();

    // サウンドデータの解放
    g_SoundManager.Release();

    // エフェクトデータの解放
    g_EffectManager.Release();
	
    return TRUE;
}