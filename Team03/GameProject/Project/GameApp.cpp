/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"EnemyManager.h"
#include	"Enemy.h"


/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//素材フォルダの指定
	CUtilities::SetCurrentDirectory("Resource");

	CEnemyManager::Singleton().Initialize();
	for (int i = 0; i < 2; i++)
	{
		auto enemy = std::make_shared<CEnemy>();
		enemy->Initialize();
		//enemy->SetMoveParameter(CVector2(450*(i+1), 200), TYPE_MOVE, CVector2(3.5f, 3.5f));
		CEnemyManager::Singleton().AddEnemy(enemy);
	}
	

	//移動位置の登録
	for (int i = 0; i < 6; i++)
	{
		int x = CUtilities::Random(CGraphicsUtilities::GetGraphics()->GetTargetWidth());
		int y = CUtilities::Random(CGraphicsUtilities::GetGraphics()->GetTargetHeight());
		CEnemyManager::Singleton().AddMovePos(CVector2(x, y));
	}

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
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CEnemyManager::Singleton().StartMove(5.0f, CVector2(3.5f, 3.5f),TYPE_ALL);
	}
	CEnemyManager::Singleton().Update();


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

	CEnemyManager::Singleton().Render();

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
	CEnemyManager::Singleton().Release();
	return TRUE;
}