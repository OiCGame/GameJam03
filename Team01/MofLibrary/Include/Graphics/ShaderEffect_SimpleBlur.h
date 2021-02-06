/*************************************************************************//*!
					
					@file	ShaderEffect_SimpleBlur.h
					@brief	�P���ڂ����V�F�[�_�[�N���X�B

															@author	CDW
															@date	2015.06.17
*//**************************************************************************/

//ONCE
#ifndef		__SHADEREFFECT_SIMPLEBLUR__H__

#define		__SHADEREFFECT_SIMPLEBLUR__H__

//INCLUDE
#include	"ShaderEffect_BlurBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�K�E�X�ڂ����V�F�[�_�[�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderEffect_SimpleBlur : public CShaderEffect_BlurBase {
	protected:
		MofFloat	m_SampleStepX;	//<!�T���v�����O����s�N�Z���̉��Ԋu
		MofFloat	m_SampleStepY;	//<!�T���v�����O����s�N�Z���̏c�Ԋu
		MofS32		m_TexWidth;		//<!�e�N�X�`���̃T�C�Y
		MofS32		m_TexHeight;	//<!�e�N�X�`���̃T�C�Y
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderEffect_SimpleBlur();
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderEffect_SimpleBlur();
		
		/*************************************************************************//*!
				@brief			�V�F�[�_�[�G�t�F�N�g�̍쐬�B
				@param			None

				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create();
		
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		col			�`��F
		@param[in]		Alignment	�A���C�����g�iTextureAlignment����t���O�̑g�ݍ��킹�Ŏw��j
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,MofU32 col,TextureAlignment Alignment,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		px			�`��X���W
		@param[in]		py			�`��Y���W
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(MofFloat px,MofFloat py,LPTexture pTex);
		/*************************************************************************//*!
		@brief			�e�N�X�`���̕`��
		@param[in]		pTarget		�`��^�[�Q�b�g�̃e�N�X�`��
		@param[in]		pTex		�e�N�X�`��
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Render(LPTexture pTargetTex,LPTexture pTex);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�ڂ����̃p�����[�^�̐ݒ�
				@param[in]		SampleStepX		�T���v�����O����s�N�Z���̉��Ԋu
				@param[in]		SampleStepY		�T���v�����O����s�N�Z���̏c�Ԋu
				@param[in]		TexWidth		�e�N�X�`���̃T�C�Y
				@param[in]		TexHeight		�e�N�X�`���̃T�C�Y

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY,MofS32 TexWidth,MofS32 TexHeight);
		/*************************************************************************//*!
				@brief			�ڂ����̃p�����[�^�̐ݒ�
				@param[in]		SampleStepX		�T���v�����O����s�N�Z���̉��Ԋu
				@param[in]		SampleStepY		�T���v�����O����s�N�Z���̏c�Ԋu

				@return			None
		*//**************************************************************************/
		virtual void SetBlurParam(MofFloat SampleStepX,MofFloat SampleStepY);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CShaderEffect_SimpleBlur,MOF_SHADEREFFECTSIMPLEBLURCLASS_ID);
	};

	// �u������
	typedef CShaderEffect_SimpleBlur*			LPShaderEffect_SimpleBlur;

#include	"ShaderEffect_SimpleBlur.inl"

}

#endif

//[EOF]