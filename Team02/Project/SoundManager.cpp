#include "SoundManager.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CSoundManager::CSoundManager(void)
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CSoundManager::~CSoundManager(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// インスタンスの取得
/// </summary>
/// <returns>マネージャー</returns>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CSoundManager & CSoundManager::GetInstance(void)
{
    static CSoundManager instance;
    return instance;
}

// ********************************************************************************
/// <summary>
/// ファイルの読み込み
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CSoundManager::Load(void)
{
    for (int i = 0; i < BGM_Count; i++)
    {
        //m_BGMBuffer[i].Load();
        m_BGMBuffer[i].SetLoop(TRUE);
    }

    for (int i = 0; i < SE_Count; i++)
    {
        for (int j = 0; j < SoundPoolCount; j++)
        {
            //m_SEBufferPool[i][j].Load();
        }
    }
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CSoundManager::Update(void)
{
    for (int i = 0; i < BGM_Count; i++)
    {
        m_BGMBuffer[i].Update();
    }

    for (int i = 0; i < SE_Count; i++)
    {
        for (int j = 0; j < SoundPoolCount; j++)
        {
            m_SEBufferPool[i][j].Update();
        }
    }
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CSoundManager::Release(void)
{
    for (int i = 0; i < BGM_Count; i++)
    {
        m_BGMBuffer[i].Release();
    }

    for (int i = 0; i < SE_Count; i++)
    {
        for (int j = 0; j < SoundPoolCount; j++)
        {
            m_SEBufferPool[i][j].Release();
        }
    }
}

// ********************************************************************************
/// <summary>
/// 再生可能サウンドエフェクトの取得
/// </summary>
/// <param name="se">取得するSE</param>
/// <returns>再生可能SEデータポインタ</returns>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CSoundBuffer * CSoundManager::GetSE(SE_Name se)
{
    for (int i = 0; i < SoundPoolCount; i++)
    {
        CSoundBuffer* pSE = &m_SEBufferPool[se][i];
        if (pSE->IsPlay())
        {
            continue;
        }
        return pSE;
    }
    return nullptr;
}

// ********************************************************************************
/// <summary>
/// サウンドエフェクトの取得
/// </summary>
/// <param name="se">取得するSE</param>
/// <param name="j">取得するSEのプール番号</param>
/// <returns>SEデータポインタ</returns>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CSoundBuffer * CSoundManager::GetSE(SE_Name se, int j)
{
    return &m_SEBufferPool[se][j];
}

// ********************************************************************************
/// <summary>
/// BGMデータの取得
/// </summary>
/// <param name="bgm">取得するBGM</param>
/// <returns>BGMデータポインタ</returns>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CSoundBuffer * CSoundManager::GetBGM(BGM_Name bgm)
{
    return &m_BGMBuffer[bgm];
}
