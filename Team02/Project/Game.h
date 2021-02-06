#pragma once
#include "SceneDefine.h"
#include "Player.h"
#include "Block.h"
#include "Timer.h"
#include "Panel.h"
#include "GameUI.h"
#include "EffectManager.h"

constexpr int   GameTime                =   60;
constexpr float BlockFallIntervalSecond = 1.3f;

// ********************************************************************************
/// <summary>
/// �Q�[���V�[���N���X
/// </summary>
// ********************************************************************************
class CGame : public MyApp::CScene
{
private:
	CPlayer		    Player;
    CBlock		    Block[BLOCK_COUNT];
	CTimer			Timer;
	bool		    DebugEnable;
    sip::CStopWatch BlockFallTimer;
    CPanel			Panel;
    CGameUI         GameUI;
    sip::CStopWatch ClearUITimer;
    sip::CStopWatch GameOverUITimer;
    sip::CStopWatch StartTimer;

public:

    // ********************************************************************************
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="data">���ʃf�[�^</param>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    explicit CGame(const InitData& data);
    
    // ********************************************************************************
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    ~CGame(void);

    // ********************************************************************************
    /// <summary>
    /// ������
    /// </summary>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    void Initialize(void);

    // ********************************************************************************
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <returns>true : ����, false : ���s</returns>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    bool Load(void);

    // ********************************************************************************
    /// <summary>
    /// �X�V
    /// </summary>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    void Update(void) override;

    // ********************************************************************************
    /// <summary>
    /// �`��
    /// </summary>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    void Render(void) override;

    // ********************************************************************************
    /// <summary>
    /// ���
    /// </summary>
    /// <created>���̂���,2021/02/01</created>
    /// <changed>���̂���,2021/02/01</changed>
    // ********************************************************************************
    void Release(void);

private:

    void StartBGM(void);
    void StopBGM(void);
};

