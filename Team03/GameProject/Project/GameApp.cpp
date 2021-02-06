/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

#include	"ResourceManager.h"
#include	"SceneTitle.h"
#include	"SceneGame.h"
#include	"SceneGameClear.h"
#include	"SceneGameOver.h"

#include	"Stage1.h"
#include	"Stage2.h"
#include	"Stage3.h"

std::unique_ptr<CSceneBase> gpSecene(new CSceneTitle());

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	CUtilities::SetFPS(60);
	g_pGraphics->SetScreenSize(1920, 1080);
	//�f�ރt�H���_�̎w��
	CUtilities::SetCurrentDirectory("Resource");
	
	CResourceManager::Singleton()
		// �摜�̓ǂݍ���
			// Secen
		.LoadTexture("Title", "images/background/Title.png")
		.LoadTexture("GameClear", "images/background/game_clear.png")
		.LoadTexture("GameOver", "images/background/game_over.png")
			// Background
		.LoadTexture("wave1","images/background/wave1_background.png")
		.LoadTexture("wave2","images/background/wave2_background.png")
		.LoadTexture("wave3","images/background/wave3_background.png")
		.LoadTexture("wave4","images/background/wave4_background.png")
		.LoadTexture("wave5","images/background/wave5_background.png")
		.LoadTexture("wave6","images/background/wave6_background.png")
			// Player
		.LoadTexture("Player", "images/player/PlayerUFO.png")
		.LoadTexture("PlayerBullet", "images/player/PlayerBullet.png")
		.LoadTexture("PlayerArrow", "images/player/PlayerArrow.png")
			// Enemy
		.LoadTexture("Enemy", "images/enemy/Enemyufo.png")
		.LoadTexture("bullet_blue", "images/enemy/Bullet_1.png")
		.LoadTexture("bullet_purple", "images/enemy/Bullet_2.png")
			// Cloud
		.LoadTexture("cloud_left", "images/cloud/cloud_left.png")
		.LoadTexture("cloud_right", "images/cloud/cloud_right.png")
		.LoadTexture("cloud_gray_left", "images/cloud/cloud_gray_left.png")
		.LoadTexture("cloud_gray_right", "images/cloud/cloud_gray_right.png")
			// Item
		.LoadTexture("ItemLife", "images/item/ItemLife.png")
			// effect
		.LoadTexture("effect_explosion", "images/effect/explosion.png")
		.LoadTexture("effect_cloud_right_highlight", "images/effect/cloud_right_highlight.png")
		.LoadTexture("effect_cloud_left_highlight", "images/effect/cloud_left_highlight.png")
			// UI
				// tutorial
		.LoadTexture("tutorial_AttackText","images/ui/tutorial/AttackText.png")
				// Life
		.LoadTexture("ui_life_0","images/ui/life/ui_zannki0.png")
		.LoadTexture("ui_life_1","images/ui/life/ui_zannki1.png")
		.LoadTexture("ui_life_2","images/ui/life/ui_zannki2.png")
		.LoadTexture("ui_life_3","images/ui/life/ui_zannki3.png")
		.LoadTexture("ui_life_4","images/ui/life/ui_zannki4.png")
		.LoadTexture("ui_life_5","images/ui/life/ui_zannki5.png")
				// wave
		.LoadTexture("ui_wave_1","images/ui/wave/ui_wave1.png")
		.LoadTexture("ui_wave_2","images/ui/wave/ui_wave2.png")
		.LoadTexture("ui_wave_3","images/ui/wave/ui_wave3.png")
		.LoadTexture("ui_wave_4","images/ui/wave/ui_wave4.png")
		.LoadTexture("ui_wave_5","images/ui/wave/ui_wave5.png")
		.LoadTexture("ui_wave_6","images/ui/wave/ui_wave6.png")

		// ���̓ǂݍ���
		.LoadSound("bgm_title", "sounds/BGM/title.mp3")
		.LoadSound("bgm_clear", "sounds/BGM/gameclear.mp3")
		.LoadSound("bgm_over", "sounds/BGM/gameover.mp3")
		.LoadSound("bgm_stage123", "sounds/BGM/stage123.mp3")
		.LoadSound("bgm_stage456", "sounds/BGM/stage456.mp3")

		.LoadSound("se_barrage", "sounds/SE/Barrage.mp3")
		.LoadSound("se_decision", "sounds/SE/Decision.mp3")
		.LoadSound("se_explosion", "sounds/SE/Explosion.mp3")
		.LoadSound("se_FastMove", "sounds/SE/FastMove.mp3")
		.LoadSound("se_PlayerShot", "sounds/SE/PlayerShot.mp3")
		.LoadSound("se_teleport", "sounds/SE/Teleport.mp3");


	gpSecene->Initialize();

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();

	gpSecene->Update();

	if (gpSecene->IsSceneEnd()) {
		gpSecene->Release();
		switch (gpSecene->NextScene())
		{
		case NextScene::Title:
			gpSecene.reset(new CSceneTitle());
			break;
		case NextScene::Game:
			gpSecene.reset(new CSceneGame(stg1));
			break;
		case NextScene::GameClear:
			gpSecene.reset(new CSceneGameClear());
			break;
		case NextScene::GameOver:
			gpSecene.reset(new CSceneGameOver());
			break;
		default:
			break;
		}
		gpSecene->Initialize();
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	gpSecene->Render();
	gpSecene->RenderDebug();

	//�`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){
	gpSecene->Release();
	CResourceManager::Singleton().Release();
	return TRUE;
}