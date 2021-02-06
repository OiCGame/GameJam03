#include "Game.h"
#include "SoundManager.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="data">���ʃf�[�^</param>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CGame::CGame(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
	DebugEnable = false;
    switch (data.pData->StageNo)
    {
    case 0:
        g_SoundManager.GetBGM(BGM_Name::BGM_Stage_1)->Play();
        break;
    case 1:
        g_SoundManager.GetBGM(BGM_Name::BGM_Stage_2)->Play();
        break;
    case 2:
        g_SoundManager.GetBGM(BGM_Name::BGM_Stage_3)->Play();
        break;
    default:
        break;
    }
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CGame::~CGame(void)
{
    for (int i = BGM_Stage_1; i <= BGM_Stage_3; i++)
    {
        if (g_SoundManager.GetBGM(BGM_Name(i))->IsPlay())
        {
            g_SoundManager.GetBGM(BGM_Name(i))->Stop();
        }
    }
    Release();
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
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
    int       bulletType    = (GetData().StageNo == 0) ? 1 : CUtilities::Random(3);
    CTexture* pBlockTexture = Player.GetBulletTexture(bulletType);
    Block[0].FallStart(pBlockTexture, bulletType);
	
	//207�̓^�C�}�[UI�g�̕��Atexture�̓ǂݍ��݈ʒu���Č����H
	Timer.Initialize(GameTime, CVector2(((int)g_pGraphics->GetTargetWidth() * 0.5) - 207,0));

    GameUI.Initialize();
}

// ********************************************************************************
/// <summary>
/// �ǂݍ���
/// </summary>
/// <returns>true : ����, false : ���s</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CGame::Load(void)
{
	Player.Load();
	Timer.Load();
    GameUI.Load();
    std::string stageFile[] = 
    {
        "StageData/stage_data1.stage",
        "StageData/stage_data2.stage",
        "StageData/stage_data3.stage",
    };
    Panel.Load(stageFile[GetData().StageNo].c_str());
    return true;
}

// ********************************************************************************
/// <summary>
/// �X�V
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CGame::Update(void)
{
    // �^�C�}�[�̍X�V
    BlockFallTimer.Update();
    // DEBUG : �P�L�[�Ń^�C�g����
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

            int       bulletType    = (GetData().StageNo == 0) ? 1 : CUtilities::Random(3);
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

		int btype = Block[i].GetBulletType();

		if (Player.IsBulletBuffer() && btype != 2) { continue; }
		if (Player.CheckHitCollision(Block[i].GetCollisionCircle()))
		{	
			if (btype == 2)
			{
				Timer.SetTime(-10);
				Timer.StartRenderTimeDamage();
                Player.Damage();
				g_SoundManager.GetSE(SE_Damage)->Play();
			}
			else
			{
				Player.SetBullet(btype);
				g_SoundManager.GetSE(SE_GetBullet)->Play();
			}
			Block[i].SetShow(false);
		}
    }
	//����\�ł���΃|�C���^�ɕύX������
	CDynamicArray<CBullet>*	tmpBullet;
	tmpBullet = Player.GetBulletArray();
	for (int i = 0; i < tmpBullet->GetArrayCount(); i++)
	{
		int panelNo = Panel.CheckHitCollision(tmpBullet->GetData(i));
        if (panelNo != -1)
        {
            CVector2 PanelPos = Panel.GetPanelPosition(panelNo);
            //�p�l���̒����ɃG�t�F�N�g������悤�ɒ���
            g_EffectManager.Start(Effect_Hit, PanelPos);
            g_SoundManager.GetSE(SE_PanelSet)->Play();
            tmpBullet->GetData(i).SetShow(false);
        }
	}

    Panel.Update();

    if (!ClearUITimer.IsStart())
    {
	    Timer.Update();
    }

	if (Timer.GetTime() <= 0)
	{
		ChangeScene(SceneName::GameOver);
	}

    
    ClearUITimer.Update();
    if (ClearUITimer.GetTime() > 1.6f)
    {
        ChangeScene(SceneName::GameClear);
    }
	if (Panel.IsClear() && !ClearUITimer.IsStart())
	{
        ClearUITimer.Start();
        Vector2 size{ 1920, 1080 };
        g_EffectManager.Start(Effect_Clear, size * 0.5f);
        g_SoundManager.GetSE(SE_GameClear)->Play();
	}
}

// ********************************************************************************
/// <summary>
/// �`��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
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
/// ���
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
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
