/*************************************************************************//*!
					
					@file	DX11ShaderResourceBase.h
					@brief	DirectX11�V�F�[�_�[���\�[�X�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERRESOURCE__H__

#define		__DX11SHADERRESOURCE__H__

//INCLUDE
#include	"../ShaderResourceBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�ւ̃p�����[�^�[�ݒ�������Ȃ����߂̃��\�[�X�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderResource : public CShaderResourceBase {
	protected:
		/*******************//*!
		�R���X�^���g���\�[�X
		*//********************/
		ID3DX11EffectShaderResourceVariable*				m_pResource;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderResource();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderResource(const CDX11ShaderResource& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderResource();
		
		/*************************************************************************//*!
				@brief			���\�[�X�̐���
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pName		���\�[�X��
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader, LPCMofChar pName);
		
		/*************************************************************************//*!
				@brief			�o�C���h�̎��s
				@param			None
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Bind(void);

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------


		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderResource, MOF_DX11SHADERRESOURCECLASS_ID);
	};

	#include	"DX11ShaderResource.inl"

	//�u������
	typedef CDX11ShaderResource		CShaderResource;
}

#endif

//[EOF]