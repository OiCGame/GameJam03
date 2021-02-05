#include "Image.h"

CImage::CImage(CTexture * pTexture)
{
    SetTexture(pTexture);
}

void CImage::Update(void)
{
    if (!m_bMoveEnable)
    {
        return;
    }

    Vector2 mp;
    g_pInput->GetMousePos(mp);
    if (GetRect().CollisionPoint(mp))
    {
        static Vector2 offset;
        if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON))
        {
            offset = mp - GetRect().GetTopLeft();
        }
        if (g_pInput->IsMouseKeyHold(MOFMOUSE_LBUTTON))
        {
            m_Position.x = mp.x - offset.x;
            m_Position.y = mp.y - offset.y;
        }
    }
}

void CImage::Render(void)
{
    if (m_pTexture == nullptr)
    {
        return;
    }
    if (m_bMoveEnable)
    {
        Vector2 mp;
        g_pInput->GetMousePos(mp);
        if (GetRect().CollisionPoint(mp))
        {
            CRectangle rect = GetRect();
            rect.Expansion(1);
            MofU32 col = MOF_COLOR_BLUE;
            if (g_pInput->IsMouseKeyHold(MOFMOUSE_LBUTTON))
            {
                col = MOF_COLOR_GREEN;
            }
            CGraphicsUtilities::RenderRect(rect, col);
        }
    }
    m_pTexture->RenderScaleRotate(m_Position.x, m_Position.y, m_Scale.x, m_Scale.y, m_Rotate.z, m_TexAlignment);
}

void CImage::Release(void)
{
    switch (m_TextureFlag)
    {
    case CImage::TextureFlag::Null:
        break;
    case CImage::TextureFlag::Set:
        m_pTexture = nullptr;
        break;
    case CImage::TextureFlag::Load:
        MOF_SAFE_DELETE(m_pTexture);
        break;
    default:
        break;
    }
    m_TextureFlag = TextureFlag::Null;
    m_pTexture = nullptr;
}

void CImage::SetMoveEnable(bool b)
{
    m_bMoveEnable = b;
}

void CImage::SetTexture(CTexture * pTexture)
{
    if (m_pTexture)
    {
        Release();
    }
    m_pTexture = pTexture;
    m_TextureFlag = TextureFlag::Set;
}

bool CImage::Load(const std::string & pFile)
{
    if (m_pTexture)
    {
        Release();
    }

    m_pTexture = new CTexture();

    if (!m_pTexture->Load(pFile.c_str()))
    {
        return false;
    }
    m_TextureFlag = TextureFlag::Load;
    return true;
}

CRectangle CImage::GetRect(void) const
{
    CRectangle rect;
    if (m_pTexture == nullptr)
    {
        return rect;
    }
    rect.SetPosition(Vector2(m_Position.x, m_Position.y));
    rect.SetWidth (m_pTexture->GetWidth()  * m_Scale.x);
    rect.SetHeight(m_pTexture->GetHeight() * m_Scale.y);
    
    int vflag = m_TexAlignment & 0xF0;
    int hflag = m_TexAlignment & 0x0F;
    switch (vflag)
    {
    case TEXALIGN_TOP:
        break;
    case TEXALIGN_VCENTER:
        rect.SetPosition(Vector2(m_Position.x, m_Position.y - rect.GetHeight() * 0.5f));
        break;
    case TEXALIGN_BOTTOM:
        rect.SetPosition(Vector2(m_Position.x, m_Position.y - rect.GetHeight()));
        break;
    }
    switch (hflag)
    {
    case TEXALIGN_LEFT:
        break;
    case TEXALIGN_HCENTER:
        rect.SetPosition(Vector2(m_Position.x - rect.GetWidth() * 0.5f, m_Position.y));
        break;
    case TEXALIGN_RIGHT:
        rect.SetPosition(Vector2(m_Position.x - rect.GetWidth(), m_Position.y));
        break;
    }

    return rect;
}
