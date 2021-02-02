#pragma once
#include "Mof.h"

// ********************************************************************************
/// <summary>
/// サウンド名
/// </summary>
// ********************************************************************************
enum SE_Name
{
    SE_Count,
};

enum BGM_Name
{
    BGM_Count,
};

constexpr int SoundPoolCont = 10;

// ********************************************************************************
/// <summary>
/// サウンド管理クラス
/// </summary>
// ********************************************************************************
class CSoundManager
{
private:

    //CSoundBuffer m_SEBufferPool[SE_Count][SoundPoolCont];
    //CSoundBuffer m_BGMBuffer[BGM_Count];

   // CSoundBuffer(void);

public:
    
    //~CSoundBuffer(void);

    static CSoundBuffer& GetInstance(void);

    void Load();

    void Update(void);

    void Release();

    CSoundBuffer& GetSE(SE_Name se);
};

