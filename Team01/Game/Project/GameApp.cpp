#include	"GameApp.h"


#include "Character.h"
#include "Enemy.h"


Mof::CTexture g_PlayerTexture;
Mof::CTexture g_EnemyTexture;
Character g_Player;
CEnemy*	g_Enemy = NULL;

MofBool CGameApp::Initialize(void) {
    ::CUtilities::SetCurrentDirectory("Resource");
    g_PlayerTexture.Load("player/Plane1Up.png");
	g_EnemyTexture.Load("enemy/Enemy01.png");
    g_Player.Initialize(Mof::CVector2(512.0f, 600.0f));
    g_Player.SetTexture(&g_PlayerTexture);

	g_Enemy = new CEnemy[5];
	float w = g_pGraphics->GetTargetWidth() / 5;
	for (int i = 0; i < 5; i++)
	{
		g_Enemy[i].Initialize(Mof::CVector2(w * i, 100.0f));
		g_Enemy[i].SetTexture(&g_EnemyTexture);
	}
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
	for (int i = 0; i < 5; i++)
	{
		g_Enemy[i].Render();
	}

    g_pGraphics->RenderEnd();
    return TRUE;
}

MofBool CGameApp::Release(void) {
    g_PlayerTexture.Release();
	g_EnemyTexture.Release();
	if (g_Enemy)
	{
		delete[] g_Enemy;
		g_Enemy = NULL;
	}
    return TRUE;
}