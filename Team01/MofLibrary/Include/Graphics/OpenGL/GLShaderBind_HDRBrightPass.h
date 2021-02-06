/*************************************************************************//*!
					
					@file	GLShaderBind_HDRBrightPass.h
					@brief	HDR�p���P�x���o�V�F�[�_�[�o�C���h�B<br>
							HDR�p���P�x���o�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

															@author	CDW
															@date	2015.11.06
*//**************************************************************************/

//ONCE
#ifndef		__GLSHADERBIND_HDRBRIGHTPASS__H__

#define		__GLSHADERBIND_HDRBRIGHTPASS__H__

//INCLUDE
#include	"GLShaderBind_SpriteBase.h"

namespace Mof {

	/*******************************//*!
	@brief	HDR�p���P�x���o�V�F�[�_�[�o�C���h�B
	
			HDR�p���P�x���o�V�F�[�_�[�Ƀp�����[�^�[���֘A�t���邽�߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGLShaderBind_HDRBrightPass : public CShaderBind_SpriteBase {
	public:
		/*******************************//*!
		@brief	�X�v���C�g�`����̓R���X�^���g�o�b�t�@��

		@author	CDW
		*//********************************/
		enum ConstParam
		{
			PARAM_HDRBRIGHTPASS = CShaderBind_SpriteBase::PARAM_MAX,

			PARAM_MAX,
		};
		/*******************************//*!
		@brief	臒l�����̓R���X�^���g�o�b�t�@

		@author	CDW
		*//********************************/
		struct ConstHDRBrightPassParam
		{
			MofFloat Threshold;
			MofFloat MiddleGray;
			MofFloat BrightPassOffset;
		};
		/*******************//*!
		�v���~�e�B�u�`��V�[�����ݒ�
		*//********************/
		ConstHDRBrightPassParam					m_HDRBrightPassParam;
	protected:
		/*******************//*!
		臒l���P�[�V����
		*//********************/
		GLuint									m_ThresholdLocation;
		/*******************//*!
		��P�x���P�[�V����
		*//********************/
		GLuint									m_MiddleGrayLocation;
		/*******************//*!
		�I�t�Z�b�g���P�[�V����
		*//********************/
		GLuint									m_BrightPassOffsetLocation;
		/*******************//*!
		�P�x�e�N�X�`��
		*//********************/
		GLuint									m_AdaptedLumTexLocation;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CGLShaderBind_HDRBrightPass();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CGLShaderBind_HDRBrightPass(const CGLShaderBind_HDRBrightPass& pObj);
		
		/*************************************************************************//*!
				@brief			�o�C���_�̐���
				@param[in]		pShader		�V�F�[�_�[
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader);
	
		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n);
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(MofU32 n,LPMofVoid pData);
		/*************************************************************************//*!
				@brief			�e�N�X�`���̐ݒ�
				@param[in]		n			�ԍ�
				@param[in]		pTex		�e�N�X�`��
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetTexture(MofU32 n,LPTexture pTex);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ݒ�p�����[�^�[�����擾����
				@param			None

				@return			�p�����[�^�[�̐�
		*//**************************************************************************/
		virtual MofS32 GetParamCount(void) const { return PARAM_MAX; }

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGLShaderBind_HDRBrightPass,MOF_GLSHADERBINDHDRBRIGHTPASSCLASS_ID);
	};

	#include	"GLShaderBind_HDRBrightPass.inl"
	
	//�u������
	typedef CGLShaderBind_HDRBrightPass		CShaderBind_HDRBrightPass;
	typedef CShaderBind_HDRBrightPass*			LPShaderBind_HDRBrightPass;
}

#endif

//[EOF]