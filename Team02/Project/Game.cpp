#include "Game.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="data">共通データ</param>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CGame::CGame(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
	DebugEnable = false;
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CGame::~CGame(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// 初期化
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGame::Initialize(void)
{
	Player.Initialize();
    Block.Initialize();
}

// ********************************************************************************
/// <summary>
/// 読み込み
/// </summary>
/// <returns>true : 成功, false : 失敗</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CGame::Load(void)
{
	Player.Load();
    Block.Load();

    return true;
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGame::Update(void)
{
    // DEBUG : １キーでタイトルへ
    if (g_pInput->IsKeyPush(MOFKEY_1))
    {
        ChangeScene(SceneName::Title);
    }
	if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		DebugEnable = !DebugEnable;
	}
	Player.Update();
    Block.Update();
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGame::Render(void)
{
    // DEBUG
    CGraphicsUtilities::RenderString(0, 0, "GAME");
	Player.Render();
    Block.Render();
    Block.RenderBlock();
	if (DebugEnable) { Player.RenderDebug(); }
	
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGame::Release(void)
{
	Player.Release();
    Block.Release();
}
