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
    Panel.Initialize(GetData().StageNo);

    CTexture* texArray[]
    {
        /**/Player.GetBulletTexture(0)/*/GameUI.GetMiniBlockTexture(0)/**/,
        /**/Player.GetBulletTexture(1)/*/GameUI.GetMiniBlockTexture(1)/**/,
    };
    Panel.SetTexture(texArray);

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Initialize();
    }
    BlockFallTimer.Start();
    int       bulletType    = (GetData().StageNo == 0) ? 1 : CUtilities::Random(2);
    CTexture* pBlockTexture = Player.GetBulletTexture(bulletType);
    Block[0].FallStart(pBlockTexture, bulletType);
	
	//207はタイマーUI枠の幅、textureの読み込み位置を再検討？
	Timer.Initialize(GameTime, CVector2(((int)g_pGraphics->GetTargetWidth() * 0.5) - 207,0));

    GameUI.Initialize();
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
	Timer.Load();
    GameUI.Load();
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
    // タイマーの更新
    BlockFallTimer.Update();
    // DEBUG : １キーでタイトルへ
    if (g_pInput->IsKeyPush(MOFKEY_1))
    {
        ChangeScene(SceneName::Title);
    }
    if (g_pInput->IsKeyPush(MOFKEY_0))
    {
        ChangeScene(SceneName::GameClear);
    }
	if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		DebugEnable = !DebugEnable;
	}
	if (g_pInput->IsKeyPush(MOFKEY_NUMPAD3))
	{
		Timer.SetTime(-10);
	}


    if (BlockFallTimer.GetTime() > BlockFallIntervalSecond)
    {
        for (int i = 0; i < BLOCK_COUNT; i++)
        {
            if (Block[i].IsShow())
            {
                continue;
            }

            int       bulletType    = (GetData().StageNo == 0) ? 1 : CUtilities::Random(2);
            CTexture* pBlockTexture = Player.GetBulletTexture(bulletType);

            Block[i].FallStart(pBlockTexture, bulletType);
            BlockFallTimer.Reset();
            break;
        }
    }

	Player.Update();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Update();

		if (Player.IsBulletBuffer()) { continue; }
		if (Player.CheckHitCollision(Block[i].GetCollisionCircle()))
		{
			int btype = Block[i].GetBulletType();
			/*if (btype == 3)
			{
				Timer.SetTime(-10);
			}
			else
			{
				Player.SetBullet(btype);
			}*/
			Block[i].SetShow(false);
		}
    }
	//後程可能であればポインタに変更したい
	CDynamicArray<CBullet>*	tmpBullet;
	tmpBullet = Player.GetBulletArray();
	int PanelNum = -1;
	for (int i = 0; i < tmpBullet->GetArrayCount(); i++)
	{
		PanelNum = Panel.CheckHitCollision(tmpBullet->GetData(i).GetRectangle(),
			tmpBullet->GetData(i).GetPosX(), tmpBullet->GetData(i).GetBulletType(),
			tmpBullet->GetData(i).GetRotate());
		if (PanelNum != -1)
		{
			CVector2 PanelPos = Panel.GetPanelPosition(PanelNum);
			//パネルの中央にエフェクトが来るように調整
				PanelPos.x -= 140;
				PanelPos.y -= 150;						
			g_EffectManager.Start(Effect_Hit, PanelPos);
			g_SoundManager.GetSE(SE_PanelSet)->Play();
			tmpBullet->GetData(i).SetShow(false);
		}
	}

    // あとで変えたいのでダミー情報を送っておく
    Panel.Update(/*CRectangle(), -1, -1*/);

	Timer.Update();

	if (Timer.GetTime() <= 0)
	{
		ChangeScene(SceneName::GameOver);
	}

	if (Panel.IsClear())
	{
		ChangeScene(SceneName::GameClear);
	}
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
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Render();
    }

    Panel.Render();

	Player.Render();

    GameUI.Render();
    if (Player.IsBulletBuffer())
    {
        GameUI.RenderBulletUI(Player.GetBulletBuffer(), Player.GetBulletRotate());
    }
	Timer.Render();

    // DEBUG
    if (DebugEnable) {
        Player.RenderDebug();
        for (int i = 0; i < BLOCK_COUNT; i++)
        {
            Block[i].RenderDebug();
        }
        Timer.RenderDebug();
        Panel.RenderDebug();
        GameUI.RenderDebug();
    }
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
    Panel.Release();
	Player.Release();
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Release();
    }
	Timer.Release();
    GameUI.Release();
}
