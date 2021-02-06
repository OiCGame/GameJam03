/*************************************************************************//*!
					
					@file	Sprite3D.h
					@brief	3D�X�v���C�g�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPRITE3D__H__

#define		__SPRITE3D__H__

//INCLUDE
#include	"SpriteBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	3D�X�v���C�g�N���X

			3D�X�v���C�g�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSprite3D : public CSpriteBase {
		//----------------------------------------------------------------------------
		////�O���C�u�����Ƃ̑Ή��̂��߂ɂ���ʃp�����[�^�[��public�Ή��ɂ��Ă���
		//----------------------------------------------------------------------------
	public:
		/*******************//*!
		�䗦�ێ��t���O
		*//********************/
		MofBool							m_bRatio;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSprite3D();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pName		�e�N�X�`���t�@�C����

				@return			None
		*//**************************************************************************/
		CSprite3D(LPCMofChar pName);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pTex		�e�N�X�`��

				@return			None
		*//**************************************************************************/
		CSprite3D(LPTexture pTex);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pName		�X�v���C�g��
				@param[in]		pTex		�e�N�X�`��

				@return			None
		*//**************************************************************************/
		CSprite3D(LPCMofChar pName,LPTexture pTex);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�e�N�X�`��

				@return			None
		*//**************************************************************************/
		CSprite3D(const CSprite3D& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CSprite3D();
		
		/*************************************************************************//*!
				@brief			�e�N�X�`���̃R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[�e�N�X�`��<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		virtual ISprite* CreateCopyObject(void) const;

		/*************************************************************************//*!
				@brief			�X�v���C�g�̍X�V
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Update(void);

		/*************************************************************************//*!
				@brief			�X�v���C�g�̕`��
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(void);
		
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���擾
				@param			None

				@return			�摜�̕�
		*//**************************************************************************/
		virtual MofFloat GetWidth(void);
		/*************************************************************************//*!
				@brief			�����擾
				@param			None

				@return			�摜�̍���
		*//**************************************************************************/
		virtual MofFloat GetHeight(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CSprite3D,MOF_SPRITE3DCLASS_ID);
	};

	#include	"Sprite3D.inl"

	//�|�C���^�u������
	typedef CSprite3D*			LPSprite3D;
}

#endif

//[EOF]