/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"EnemyManager.h"
#include	"Enemy.h"


/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){

	//�f�ރt�H���_�̎w��
	CUtilities::SetCurrentDirectory("Resource");

	CEnemyManager::Singleton().Initialize();
	for (int i = 0; i < 2; i++)
	{
		auto enemy = std::make_shared<CEnemy>();
		enemy->Initialize();
		//enemy->SetMoveParameter(CVector2(450*(i+1), 200), TYPE_MOVE, CVector2(3.5f, 3.5f));
		CEnemyManager::Singleton().AddEnemy(enemy);
	}
	

	//�ړ��ʒu�̓o�^
	for (int i = 0; i < 6; i++)
	{
		int x = CUtilities::Random(CGraphicsUtilities::GetGraphics()->GetTargetWidth());
		int y = CUtilities::Random(CGraphicsUtilities::GetGraphics()->GetTargetHeight());
		CEnemyManager::Singleton().AddMovePos(CVector2(x, y));
	}

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
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		CEnemyManager::Singleton().StartMove(5.0f, CVector2(3.5f, 3.5f),TYPE_ALL);
	}
	CEnemyManager::Singleton().Update();


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

	CEnemyManager::Singleton().Render();

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
	CEnemyManager::Singleton().Release();
	return TRUE;
}