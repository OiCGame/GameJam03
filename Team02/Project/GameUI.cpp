#include "GameUI.h"

bool CGameUI::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/ゲーム本編");
    MofBool b[] =
    {
        BulletUITexture[Triangle].Load("ミニ三角ブロック.png"),
        BulletUITexture[Square].Load("ミニ四角ブロック.png"),
        UIFrameTexture.Load("アイテム枠_空白.png"),
        GuideImage.Load("ガイド2.png"),
    };
    CUtilities::SetCurrentDirectory("../../");

    for (const auto& it : b)
    {
        if (!it)
        {
            return false;
        }
    }

    return true;
}

void CGameUI::Initialize(void)
{

    BulletUIPosition = Vector2(g_pGraphics->GetTargetWidth() * 0.5f, 0);
}

void CGameUI::Render(void)
{
    UIFrameTexture.RenderScale(BulletUIPosition.x, BulletUIPosition.y , 0.5f);
    GuideImage.Render(g_pGraphics->GetTargetWidth() * 0.99f, g_pGraphics->GetTargetHeight() * 0.025f, TEXALIGN_TOPRIGHT);
}

void CGameUI::RenderBulletUI(int bullettype, int rotate)
{
    BulletUITexture[bullettype].RenderRotate(BulletUIPosition.x + (UIFrameTexture.GetWidth() * 0.25),
        BulletUIPosition.y + (UIFrameTexture.GetHeight() * 0.25),
        MOF_ToRadian(90 * rotate), TEXTUREALIGNMENT_CENTERCENTER);
}

void CGameUI::RenderDebug(void)
{
    CGraphicsUtilities::RenderString(500, 0, MOF_COLOR_GREEN, "アイテムUI座標 %1f %2f", BulletUIPosition.x, BulletUIPosition.y);
}

void CGameUI::Release(void)
{
    for (int i = 0; i < BULLET_CATEGORY; i++)
    {
        BulletUITexture[i].Release();
    }
    UIFrameTexture.Release();
    GuideImage.Release();
}
