#include "Button.h"
#include "RoundRect.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CButton::CButton(void)
    : m_pBtnTexture(nullptr)
    , m_pFontTexture(nullptr)
    , m_Scale(1.0f, 1.0f)
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CButton::~CButton(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <param name="pos">�`����W</param>
/// <param name="pBase">�{�̃{�^���e�N�X�`���|�C���^</param>
/// <param name="pFont">�t�H���g�e�N�X�`���|�C���^</param>
/// <param name="scale">�\���{��</param>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
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
/// �`��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
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
/// ���
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CButton::Release(void)
{
    m_pBtnTexture  = nullptr;
    m_pFontTexture = nullptr;
}

// ********************************************************************************
/// <summary>
/// �{�^���̋�`�擾
/// </summary>
/// <returns>�{�^����`, ��������NoneRect</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
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
/// �}�E�X���d�Ȃ��Ă��邩�̃t���O�擾
/// </summary>
/// <returns>true : �d�Ȃ��Ă���, false : �d�Ȃ��Ă��Ȃ�</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsMouseOver(void) const
{
    Vector2 mp;
    g_pInput->GetMousePos(mp);
    return GetRect().CollisionPoint(mp);
}

// ********************************************************************************
/// <summary>
/// �{�^���������ꂽ�u�Ԃ̃t���O�擾
/// </summary>
/// <returns>true : �����ꂽ�u��, false : ����ȊO</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsPush(void) const
{
    return IsMouseOver() && g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON);
}

// ********************************************************************************
/// <summary>
/// �{�^����������Ă���Ԃ̃t���O�擾
/// </summary>
/// <returns>true : ������Ă���, false : ������Ă��Ȃ�</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsHold(void) const
{
    return IsMouseOver() && g_pInput->IsMouseKeyHold(MOFMOUSE_LBUTTON);
}

// ********************************************************************************
/// <summary>
/// �{�^�����痣�ꂽ�u�Ԃ̃t���O�擾
/// </summary>
/// <returns>true : ���ꂽ�u��, false : ����ȊO</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CButton::IsPull(void) const
{
    return IsMouseOver() && g_pInput->IsMouseKeyPull(MOFMOUSE_LBUTTON);
}

// ********************************************************************************
/// <summary>
/// �{�^���̕\�����W�ύX
/// </summary>
/// <param name="position">�\�����W</param>
/// <created>���̂���,2021/02/04</created>
/// <changed>���̂���,2021/02/04</changed>
// ********************************************************************************
void CButton::SetPosition(const Vector2 & position)
{
    m_Pos = position;
}
