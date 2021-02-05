/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

//SCENE
#include    "Title.h"
#include    "Game.h"
#include    "GameClear.h"
#include    "GameOver.h"

//MANAGER
#include    "SoundManager.h"
#include    "EffectManager.h"

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {
	
    CUtilities::SetCurrentDirectory("Resource");

    m_BackTexture.Load("UI/����/�w�i.png");

    // �T�E���h�f�[�^�̓ǂݍ���
    g_SoundManager.Load();
    // �G�t�F�N�g�f�[�^�̓ǂݍ���
    g_EffectManager.Load();

    // SceneManager�Ɋe�V�[���̒ǉ��ƃt�F�[�h�J���[�̐ݒ�
    m_SceneManager
        .Add<CTitle>(SceneName::Title)
        .Add<CGame>(SceneName::Game)
        .Add<CGameClear>(SceneName::GameClear)
        .Add<CGameOver>(SceneName::GameOver)
        .SetFadeColor(MOF_COLOR_WHITE);

    m_SceneManager.Initialize(SceneName::Title);

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Update(void) {
	//�L�[�̍X�V
	g_pInput->RefreshKey();
    // �T�E���h�f�[�^�̍X�V
    g_SoundManager.Update();
    // �G�t�F�N�g�̍X�V
    g_EffectManager.Update();

    // ESC�L�[�ŏI��
    if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
    {
        PostQuitMessage(0);
    }

    // �V�[���}�l�[�W���[�̍X�V
    if (!m_SceneManager.Update())
    {
        return FALSE;
    }

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void) {
	//�`��J�n
	g_pGraphics->RenderStart();
	//��ʂ̃N���A
	g_pGraphics->ClearTarget(0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0);

    m_BackTexture.Render(0, 0);

    // �V�[���}�l�[�W���[�̕`��
    if (!m_SceneManager.Render())
    {
        return FALSE;
    }

    // �G�t�F�N�g�̕`��
    g_EffectManager.Render();

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
MofBool CGameApp::Release(void) {

    m_BackTexture.Release();

    // �T�E���h�f�[�^�̉��
    g_SoundManager.Release();

    // �G�t�F�N�g�f�[�^�̉��
    g_EffectManager.Release();
	
    return TRUE;
}