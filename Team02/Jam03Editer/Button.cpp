#include "Button.h"
#include "RoundRect.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CButton::CButton(void)
    : m_pBtnTexture(nullptr)
    , m_pFontTexture(nullptr)
    , m_Scale(1.0f, 1.0f)
{
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CButton::~CButton(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// 初期化
/// </summary>
/// <param name="pos">描画座標</param>
/// <param name="pBase">本体ボタンテクスチャポインタ</param>
/// <param name="pFont">フォントテクスチャポインタ</param>
/// <param name="scale">表示倍率</param>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CButton::Initialize(const Vector2& pos, CTexture * pBase, CTexture * pFont, const Vector2 & scale)
{
    m_Pos          = pos;
    m_pBtnTexture  = pBase;
    m_pFontTexture = pFont;
    m_Scale        = scale;
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CButton::Render(void)
{
    g_pGraphics->SetStencilEnable(TRUE);

    g_pGraphics->SetStencilControl(COMPARISON_ALWAYS, STENCIL_INCR, STENCIL_INCR, STENCIL_INCR);

    CRectangle rect = GetRect();
    if (m_pBtnTexture)
    {
        m_pBtnTexture->Render(rect);
    }

    if (m_pFontTexture)
    {
        if (m_pBtnTexture)
        {
            float x = rect.Left + (rect.GetWidth()  - m_pFontTexture->GetWidth()  * m_Scale.x) * 0.5f;
            float y = rect.Top  + (rect.GetHeight() - m_pFontTexture->GetHeight() * m_Scale.y) * 0.5f;
            rect.SetPosition(Vector2(x, y));
            rect.SetWidth (m_pFontTexture->GetWidth()  * m_Scale.x);
            rect.SetHeight(m_pFontTexture->GetHeight() * m_Scale.y);
        }
        m_pFontTexture->Render(rect);
    }

    g_pGraphics->SetStencilControl(COMPARISON_LESS, STENCIL_KEEP, STENCIL_KEEP, STENCIL_KEEP);

    if (IsHold())
    {
        CGraphicsUtilities::RenderFillRect(GetRect(), MOF_ALPHA_WHITE(64));
    }
    g_pGraphics->SetStencilEnable(FALSE);
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CButton::Release(void)
{
    m_pBtnTexture  = nullptr;
    m_pFontTexture = nullptr;
}

// ********************************************************************************
/// <summary>
/// ボタンの矩形取得
/// </summary>
/// <returns>ボタン矩形, もしくはNoneRect</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CRectangle CButton::GetRect(void) const
{
    if (m_pBtnTexture == nullptr)
    {
        if (m_pFontTexture)
        {
            Vector2 size(m_pFontTexture->GetWidth(), m_pFontTexture->GetHeight());
            return CRectangle(m_Pos, m_Pos + size * m_Scale);
        }
        return sip::NoneRect;
    }
    Vector2 size(m_pBtnTexture->GetWidth(), m_pBtnTexture->GetHeight());
    return CRectangle(m_Pos, m_Pos + size * m_Scale);
}

// ********************************************************************************
/// <summary>
/// マウスが重なっているかのフラグ取得
/// </summary>
/// <returns>true : 重なっている, false : 重なっていない</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsMouseOver(void) const
{
    Vector2 mp;
    g_pInput->GetMousePos(mp);
    return GetRect().CollisionPoint(mp);
}

// ********************************************************************************
/// <summary>
/// ボタンが押された瞬間のフラグ取得
/// </summary>
/// <returns>true : 押された瞬間, false : それ以外</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsPush(void) const
{
    return IsMouseOver() && g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON);
}

// ********************************************************************************
/// <summary>
/// ボタンが押されている間のフラグ取得
/// </summary>
/// <returns>true : 押されている, false : 押されていない</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsHold(void) const
{
    return IsMouseOver() && g_pInput->IsMouseKeyHold(MOFMOUSE_LBUTTON);
}

// ********************************************************************************
/// <summary>
/// ボタンから離れた瞬間のフラグ取得
/// </summary>
/// <returns>true : 離れた瞬間, false : それ以外</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsPull(void) const
{
    return IsMouseOver() && g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON);
}

// ********************************************************************************
/// <summary>
/// ボタンの表示座標変更
/// </summary>
/// <param name="position">表示座標</param>
/// <created>いのうえ,2021/02/04</created>
/// <changed>いのうえ,2021/02/04</changed>
// ********************************************************************************
void CButton::SetPosition(const Vector2 & position)
{
    m_Pos = position;
}
