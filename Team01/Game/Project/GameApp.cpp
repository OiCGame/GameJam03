#include	"GameApp.h"


#include <vector>

#include "Character.h"
#include "Bullet.h"

#include <array>

Mof::CTexture g_PlayerTexture;
Mof::CTexture g_BulletTexture;
Character g_Player;
<<<<<<< HEAD
CEnemy*	g_Enemy = NULL;
=======
std::array<Bullet, 256>g_BulletContainer;
>>>>>>> 626b02220252bca2cf7e611295dd0f28211bffd1

MofBool CGameApp::Initialize(void) {
    ::CUtilities::SetCurrentDirectory("Resource");
    g_PlayerTexture.Load("player/Plane1Up.png");
    g_BulletTexture.Load("bullet/01Bullets.png");
    g_Player.Initialize(Mof::CVector2(512.0f, 600.0f));
    g_Player.SetTexture(&g_PlayerTexture);

<<<<<<< HEAD
	g_Enemy = new CEnemy[5];
	float w = g_pGraphics->GetTargetWidth() / 5;
	for (int i = 0; i < 5; i++)
	{
		g_Enemy[i].Initialize(Mof::CVector2(w * i, 100.0f));
		g_Enemy[i].SetTexture(&g_EnemyTexture);
	}
=======
    for (auto& bullet : g_BulletContainer) {
        bullet.SetTexture(&g_BulletTexture);
    } // for
>>>>>>> 626b02220252bca2cf7e611295dd0f28211bffd1
    return TRUE;
}

MofBool CGameApp::Update(void) {
    g_pInput->RefreshKey();

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
<<<<<<< HEAD
	for (int i = 0; i < 5; i++)
	{
		g_Enemy[i].Render();
	}
=======
    for (auto& bullet : g_BulletContainer) {
        bullet.Render();
    } // for
>>>>>>> 626b02220252bca2cf7e611295dd0f28211bffd1

    g_pGraphics->RenderEnd();
    return TRUE;
}

MofBool CGameApp::Release(void) {
    g_PlayerTexture.Release();
<<<<<<< HEAD
	g_EnemyTexture.Release();
	if (g_Enemy)
	{
		delete[] g_Enemy;
		g_Enemy = NULL;
	}
=======
    g_BulletTexture.Release();
>>>>>>> 626b02220252bca2cf7e611295dd0f28211bffd1
    return TRUE;
}