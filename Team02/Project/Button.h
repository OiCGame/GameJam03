#pragma once
#include "Mof.h"

// ********************************************************************************
/// <summary>
/// ボタンクラス
/// </summary>
// ********************************************************************************
class CButton
{
private:

    CTexture* m_pBtnTexture;            //! ボタン本体画像
    CTexture* m_pPushTexture;           //! 押されている時のボタン画像
    Vector2   m_Scale{ 1.0f, 1.0f };    //! 画像表示倍率

public:

    CButton(void);
    ~CButton(void);

    void Initialize(CTexture* pBase, CTexture* pPush, const Vector2& scale);

    void Update(void);

    void Render(void);

    void Release(void);
};

