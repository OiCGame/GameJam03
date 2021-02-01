#include	"GameApp.h"


#include <vector>

#include "Character.h"
#include "Bullet.h"

#include <array>

Mof::CTexture g_PlayerTexture;
Mof::CTexture g_BulletTexture;
CCharacter g_Player;
std::array<CBullet, 256>g_BulletContainer;

MofBool CGameApp::Initialize(void) {
    ::CUtilities::SetCurrentDirectory("Resource");
    g_PlayerTexture.Load("player/Plane1Up.png");
    g_BulletTexture.Load("bullet/01Bullets.png");
    g_Player.Initialize(Mof::CVector2(512.0f, 600.0f));
    g_Player.SetTexture(&g_PlayerTexture);

    for (auto& bullet : g_BulletContainer) {
        bullet.SetTexture(&g_BulletTexture);
    } // for
    return TRUE;
}

MofBool CGameApp::Update(void) {
    g_pInput->RefreshKey();

	CInputManager::GetInstance().Refresh();

    g_Player.Update(g_BulletContainer);


    for (auto& bullet : g_BulletContainer) {
        bullet.Update();
    } // for

    return TRUE;
}

MofBool CGameApp::Render(void) {
    g_pGraphics->RenderStart();

    g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

    g_Player.Render();
    for (auto& bullet : g_BulletContainer) {
        bullet.Render();
    } // for

    g_pGraphics->RenderEnd();
    return TRUE;
}

MofBool CGameApp::Release(void) {
    g_PlayerTexture.Release();
    g_BulletTexture.Release();
    return TRUE;
}