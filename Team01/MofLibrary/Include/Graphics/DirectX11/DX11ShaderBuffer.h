/*************************************************************************//*!
					
					@file	DX11ShaderBufferBase.h
					@brief	DirectX11�V�F�[�_�[�o�b�t�@�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__DX11SHADERBUFFER__H__

#define		__DX11SHADERBUFFER__H__

//INCLUDE
#include	"../ShaderBufferBase.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�ւ̃p�����[�^�[�ݒ�������Ȃ����߂̃o�b�t�@�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CDX11ShaderBuffer : public CShaderBufferBase {
	protected:
		/*******************//*!
		�R���X�^���g�o�b�t�@
		*//********************/
		ID3D11Buffer*							m_pConstBuffer;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CDX11ShaderBuffer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CDX11ShaderBuffer(const CDX11ShaderBuffer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CDX11ShaderBuffer();
		
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐���
				@param[in]		pShader		�V�F�[�_�[
				@param[in]		pName		�o�b�t�@��
				@param[in]		size		�o�b�t�@�T�C�Y
				
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool Create(LPShader pShader, LPCMofChar pName,const MofU32 size);
		
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
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		pData		�f�[�^
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(LPMofVoid pData);
		/*************************************************************************//*!
				@brief			�o�b�t�@�̐ݒ�
				@param[in]		pData		�f�[�^
				@param[in]		off			�I�t�Z�b�g
				@param[in]		s			�T�C�Y
					
				@return			TRUE		����<br>
								����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
		*//**************************************************************************/
		virtual MofBool SetBuffer(LPMofVoid pData,MofU32 off,MofU32 s);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------

		//�N���X��{��`
		MOF_LIBRARYCLASS(CDX11ShaderBuffer, MOF_DX11SHADERBUFFERCLASS_ID);
	};

	#include	"DX11ShaderBuffer.inl"

	//�u������
	typedef CDX11ShaderBuffer		CShaderBuffer;
}

#endif

//[EOF]