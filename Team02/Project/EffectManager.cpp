#include "EffectManager.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CEffectManager::CEffectManager(void)
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CEffectManager::~CEffectManager(void)
{
}

// ********************************************************************************
/// <summary>
/// �C���X�^���X�̎擾
/// </summary>
/// <returns>�}�l�[�W���[</returns>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CEffectManager & CEffectManager::GetInstance(void)
{
    static CEffectManager instance;
    return instance;
}

// ********************************************************************************
/// <summary>
/// �ǂݍ���
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CEffectManager::Load(void)
{
    std::string animFile[] =
    {
        "Effect/�q�b�g�G�t�F�N�g/hit.anim",
    };
    for (int i = 0; i < Effect_Count; i++)
    {
        m_EffectAnimData[i].Load(animFile[i].c_str());
    }
    std::string texFile[] =
    {
        "Effect/�q�b�g�G�t�F�N�g/effect.png",
    };
    for (int i = 0; i < Effect_Count; i++)
    {
        m_EffectTexture[i].Load(texFile[i].c_str());
    }
    for (int i = 0; i < Effect_Count; i++)
    {
        SpriteAnimationCreate* pAnim = m_EffectAnimData[i].GetAnim();
        int animCount = m_EffectAnimData[i].GetAnimationCount();
        for (int j = 0; j < EffectPoolCount; j++)
        {
            m_EffectMotion[i][j].Create(pAnim, animCount);
            m_EffectPos[i][j] = InvalidPos;
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
void CEffectManager::Update(void)
{
    for (int i = 0; i < Effect_Count; i++)
    {
        for (int j = 0; j < EffectPoolCount; j++)
        {
            if (m_EffectPos[i][j] == InvalidPos)
            {
                continue;
            }
            m_EffectMotion[i][j].AddTimer(CUtilities::GetFrameSecond());
            if (m_EffectMotion[i][j].IsEndMotion())
            {
                m_EffectMotion[i][j].SetTime(0);
                m_EffectPos[i][j] = InvalidPos;
            }
        }
    }
}

// ********************************************************************************
/// <summary>
/// �`��
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CEffectManager::Render(void)
{
    for (int i = 0; i < Effect_Count; i++)
    {
        for (int j = 0; j < EffectPoolCount; j++)
        {
            if (m_EffectPos[i][j] == InvalidPos)
            {
                continue;
            }
            Vector2& pos = m_EffectPos[i][j];
            m_EffectTexture[i].Render(pos.x, pos.y, m_EffectMotion[i][j].GetSrcRect(), TEXALIGN_CENTERCENTER);
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
void CEffectManager::Release(void)
{
    for (int i = 0; i < Effect_Count; i++)
    {
        m_EffectTexture[i].Release();
        m_EffectAnimData[i].Release();
        for (int j = 0; j < EffectPoolCount; j++)
        {
            m_EffectMotion[i][j].Release();
        }
    }
}

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�̊J�n
/// </summary>
/// <param name="effect">�Đ�����G�t�F�N�g</param>
/// <param name="pos">�Đ�������W</param>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CEffectManager::Start(Effect_Name effect, const Vector2 & pos)
{
    for (int j = 0; j < EffectPoolCount; j++)
    {
        if (m_EffectPos[effect][j] != InvalidPos)
        {
            continue;
        }
        m_EffectPos[effect][j] = pos;
        break;
    }
}

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�̊J�n
/// </summary>
/// <param name="effect">�Đ�����G�t�F�N�g</param>
/// <param name="x">�Đ�����X���W</param>
/// <param name="y">�Đ�����Y���W</param>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CEffectManager::Start(Effect_Name effect, float x, float y)
{
    Start(effect, Vector2(x, y));
}
