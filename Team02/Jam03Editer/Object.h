#pragma once
#include "Mof.h"

// ********************************************************************************
/// <summary>
/// ‚·‚×‚Ä‚ÌŠî’êƒNƒ‰ƒX‚É‚·‚é‚Â‚à‚è
/// </summary>
// ********************************************************************************
class CObject
{
protected:

    Vector3 m_Position{ 0.0f, 0.0f, 0.0f };

    Vector3 m_Rotate  { 0.0f, 0.0f, 0.0f };
    
    Vector3 m_Scale   { 1.0f, 1.0f, 1.0f };

    bool    m_bEnable { true };

public:

    CObject(void) = default;

    ~CObject(void) = default;

    inline void SetPosition(const Vector3& posision)
    {
        m_Position = posision;
    }

    inline void SetRotate(const Vector3& rotate)
    {
        m_Rotate = rotate;
    }
    
    inline void SetScale(const Vector3& scale)
    {
        m_Scale = scale;
    }

    inline void SetEnable(bool b)
    {
        m_bEnable = b;
    }

    inline bool IsEnable(void) const
    {
        return m_bEnable;
    }
};

