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

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None

		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {
	
    CUtilities::SetCurrentDirectory("Resource");

    m_BackTexture.Load("UI/����/�w�i.png");

    // SceneManager�Ɋe�V�[���̒ǉ��ƃt�F�[�h�J���[�̐ݒ�
    m_SceneManager
        .Add<CTitle>(SceneName::Title)
        .Add<CGame>(SceneName::Game)
        .Add<CGameClear>(SceneName::GameClear)
        .Add<CGameOver>(SceneName::GameOver)
        .SetFadeColor(MOF_COLOR_WHITE);

    // DEBUG : �f�o�b�O�p�ŃQ�[���V�[������X�^�[�g����
    //m_SceneManager.Initialize(SceneName::Title);
    m_SceneManager.Initialize(SceneName::Game);

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
	
    return TRUE;
}