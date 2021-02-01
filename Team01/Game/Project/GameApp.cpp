#include	"GameApp.h"


#include "Character.h"


Mof::CTexture g_PlayerTexture;
Character g_Player;


MofBool CGameApp::Initialize(void) {
    ::CUtilities::SetCurrentDirectory("Resource");
    g_PlayerTexture.Load("player/Plane1Up.png");
    g_Player.Initialize(Mof::CVector2(512.0f, 600.0f));
    g_Player.SetTexture(&g_PlayerTexture);
    return TRUE;
}

MofBool CGameApp::Update(void) {
    g_pInput->RefreshKey();

    g_Player.Update();


    return TRUE;
}

MofBool CGameApp::Render(void) {
    g_pGraphics->RenderStart();

    g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);


    g_Player.Render();

    g_pGraphics->RenderEnd();
    return TRUE;
}

MofBool CGameApp::Release(void) {
    g_PlayerTexture.Release();
    return TRUE;
}