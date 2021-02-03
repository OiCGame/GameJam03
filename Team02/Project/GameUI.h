#pragma once
#include "Mof.h"
#include "Bullet.h"

// ********************************************************************************
/// <summary>
/// ゲームシーン用UIクラス
/// </summary>
// ********************************************************************************
class CGameUI
{
private:

    CTexture				BulletUITexture[BULLET_CATEGORY];
    CTexture				UIFrameTexture;
    Vector2				    BulletUIPosition;
    CTexture                GuideImage;

public:

    CGameUI(void) = default;

    ~CGameUI(void) = default;

    bool Load(void);

    void Initialize(void);

    void Render(void);

    void RenderBulletUI(int bullettype, int rotate);

    void RenderDebug(void);

    void Release(void);
};

