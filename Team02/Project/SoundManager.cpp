#include "SoundManager.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CSoundManager::CSoundManager(void)
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CSoundManager::~CSoundManager(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// �C���X�^���X�̎擾
/// </summary>
/// <returns>�}�l�[�W���[</returns>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CSoundManager & CSoundManager::GetInstance(void)
{
    static CSoundManager instance;
    return instance;
}

// ********************************************************************************
/// <summary>
/// �t�@�C���̓ǂݍ���
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
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
/// �X�V
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
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
/// ���
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
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
/// �Đ��\�T�E���h�G�t�F�N�g�̎擾
/// </summary>
/// <param name="se">�擾����SE</param>
/// <returns>�Đ��\SE�f�[�^�|�C���^</returns>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
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
/// �T�E���h�G�t�F�N�g�̎擾
/// </summary>
/// <param name="se">�擾����SE</param>
/// <param name="j">�擾����SE�̃v�[���ԍ�</param>
/// <returns>SE�f�[�^�|�C���^</returns>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CSoundBuffer * CSoundManager::GetSE(SE_Name se, int j)
{
    return &m_SEBufferPool[se][j];
}

// ********************************************************************************
/// <summary>
/// BGM�f�[�^�̎擾
/// </summary>
/// <param name="bgm">�擾����BGM</param>
/// <returns>BGM�f�[�^�|�C���^</returns>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CSoundBuffer * CSoundManager::GetBGM(BGM_Name bgm)
{
    return &m_BGMBuffer[bgm];
}