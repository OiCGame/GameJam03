#include "Game.h"

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
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Initialize();
    }
    BlockFallTimer.Start();
    int       bulletType    = (GetData().StageNo == 0) ? 1 : CUtilities::Random(2);
    CTexture* pBlockTexture = Player.GetBulletTexture(bulletType);
    Block[0].FallStart(pBlockTexture, bulletType);
	
	Timer.Initialize( 300,CVector2(1450,500));
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
	if (g_pInput->IsKeyPush(MOFKEY_2))
	{
		DebugEnable = !DebugEnable;
	}

    if (BlockFallTimer.GetTime() > 2.0f)
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
			Player.SetBullet(Block[i].GetBulletType());
			Block[i].SetShow(false);
		}
    }
	Timer.Update();

	if (Timer.GetTime() <= 0)
	{
		ChangeScene(SceneName::GameOver);
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
    // DEBUG
    CGraphicsUtilities::RenderString(0, 0, "GAME");
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Render();
    }
	if (DebugEnable) {
        Player.RenderDebug();
        for (int i = 0; i < BLOCK_COUNT; i++)
        {
            Block[i].RenderDebug();
        }
		Timer.RenderDebug();
    }
	Player.Render();
	Timer.Render();
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
	Player.Release();
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        Block[i].Release();
    }
	Timer.Release();
}
