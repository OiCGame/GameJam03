#include	"GameApp.h"


MofBool CGameApp::Initialize(void) {
    return TRUE;
}

MofBool CGameApp::Update(void) {
    g_pInput->RefreshKey();
    return TRUE;
}

MofBool CGameApp::Render(void) {
    g_pGraphics->RenderStart();

    g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

    g_pGraphics->RenderEnd();
    return TRUE;
}

MofBool CGameApp::Release(void) {
    return TRUE;
}