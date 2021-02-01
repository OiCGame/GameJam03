#pragma once
#include "Mof.h"

// ********************************************************************************
/// <summary>
/// �{�^���N���X
/// </summary>
// ********************************************************************************
class CButton
{
private:

    CTexture* m_pBtnTexture;            //! �{�^���{�̉摜
    CTexture* m_pPushTexture;           //! ������Ă��鎞�̃{�^���摜
    Vector2   m_Scale{ 1.0f, 1.0f };    //! �摜�\���{��

public:

    CButton(void);
    ~CButton(void);

    void Initialize(CTexture* pBase, CTexture* pPush, const Vector2& scale);

    void Update(void);

    void Render(void);

    void Release(void);
};

