#include "EffectManager.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CEffectManager::CEffectManager(void)
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CEffectManager::~CEffectManager(void)
{
}

// ********************************************************************************
/// <summary>
/// インスタンスの取得
/// </summary>
/// <returns>マネージャー</returns>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CEffectManager & CEffectManager::GetInstance(void)
{
    static CEffectManager instance;
    return instance;
}

// ********************************************************************************
/// <summary>
/// 読み込み
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CEffectManager::Load(void)
{
    std::string animFile[] =
    {
        "Effect/ヒットエフェクト/hit.anim",
    };
    for (int i = 0; i < Effect_Count; i++)
    {
        m_EffectAnimData[i].Load(animFile[i].c_str());
    }
    std::string texFile[] =
    {
        "Effect/ヒットエフェクト/effect.png",
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
/// 更新
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
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
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
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
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
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
/// エフェクトの開始
/// </summary>
/// <param name="effect">再生するエフェクト</param>
/// <param name="pos">再生する座標</param>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
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
/// エフェクトの開始
/// </summary>
/// <param name="effect">再生するエフェクト</param>
/// <param name="x">再生するX座標</param>
/// <param name="y">再生するY座標</param>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CEffectManager::Start(Effect_Name effect, float x, float y)
{
    Start(effect, Vector2(x, y));
}
