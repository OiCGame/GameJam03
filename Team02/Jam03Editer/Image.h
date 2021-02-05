#pragma once
#include "Object.h"

// ********************************************************************************
/// <summary>
/// 画像オブジェクト
/// </summary>
// ********************************************************************************
class CImage : public CObject
{
protected:

    enum class TextureFlag
    {
        Null,
        Set,
        Load,
    }                m_TextureFlag  { TextureFlag::Null };
                     
    bool             m_bMoveEnable  { true };
                     
    CTexture*        m_pTexture     { nullptr };

    TextureAlignment m_TexAlignment { TEXALIGN_TOPLEFT };

public:

    CImage(void) = default;

    ~CImage(void) { Release(); }

    CImage(CTexture* pTexture);

    void Update(void);

    void Render(void);

    void Release(void);

    void SetMoveEnable(bool b);

    void SetTexture(CTexture* pTexture);

    bool Load(const std::string& pFile);

    CRectangle GetRect(void) const;
};

