#include	"GameApp.h"


#include <vector>

#include "Game.h"
#include "Character.h"
#include "Enemy.h"
#include "Bullet.h"

Mof::CTexture g_PlayerTexture;
Mof::CTexture g_EnemyTexture;
Mof::CTexture g_BulletTexture;
CCharacter g_Player;
CEnemy g_Enemy[3];
std::array<CBullet, 256>g_BulletContainer;
//CBullet g_BulletContainer[256];

CGame g_Game;





MofBool CGameApp::Initialize(void) {
	::CUtilities::SetCurrentDirectory("Resource");

	
	g_Game.Initialize();
	/*
	g_PlayerTexture.Load("player/Plane1Up.png");
	g_EnemyTexture.Load("enemy/Enemy01.png");
	g_BulletTexture.Load("bullet/01Bullets.png");
	g_Player.Initialize(Mof::CVector2(512.0f, 600.0f));
	g_Player.SetTexture(&g_PlayerTexture);
	for (int i = 0; i < 3; i++) {
		g_Enemy[i].Initialize(Vector2(300 + i * 200, 200));
		g_Enemy[i].SetTexture(&g_EnemyTexture);
	}

	for (auto& bullet : g_BulletContainer) {
		bullet.SetTexture(&g_BulletTexture);
	} // for*/
	return TRUE;
}

MofBool CGameApp::Update(void) {
	g_pInput->RefreshKey();
	::CInputManager::GetInstance().Refresh();

	g_Game.Update();

	/*if (g_Player.IsShow()) {
		g_Player.Update(g_BulletContainer);
	} // if
	for (int i = 0; i < 3; i++) {
		if (g_Enemy[i].IsShow()) {
			g_Enemy[i].Update();
		} // if
	}

	for (auto& bullet : g_BulletContainer) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Update();
	} // for

	for (auto& bullet : g_BulletContainer) {
		for (int i = 0; i < 3; i++) {
			if (!g_Enemy[i].IsShow() || !bullet.IsShow()) {
				continue;
			} //
			if (g_Enemy[i].GetCollisionRectangle().CollisionRect(bullet.GetCollisionRectangle())) {
				g_Enemy[i].Damage();
				bullet.Hide();
			} // if
		}
	} // for*/
	return TRUE;
}


MofBool CGameApp::Render(void) {
	g_pGraphics->RenderStart();

	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

	g_Game.Render();

	/*if (g_Player.IsShow()) {
		g_Player.Render();
	} // if
	for (int i = 0; i < 3; i++) {
		if (g_Enemy[i].IsShow()) {
			g_Enemy[i].Render();
		} // if
	}
	for (auto& bullet : g_BulletContainer) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Render();
	} // for*/
	g_pGraphics->RenderEnd();
	return TRUE;
}

MofBool CGameApp::Release(void) {
	//g_Game.Release();
	for (int i = 0; i < 3; i++) {
		g_Enemy[i].Release();
	}
	g_PlayerTexture.Release();
	g_EnemyTexture.Release();
	g_BulletTexture.Release();
	g_Game.Release();
	return TRUE;
}