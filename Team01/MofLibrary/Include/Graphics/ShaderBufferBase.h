/*************************************************************************//*!
					
					@file	ShaderBufferBase.h
					@brief	�V�F�[�_�[�o�b�t�@�N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SHADERBUFFERBASE__H__

#define		__SHADERBUFFERBASE__H__

//INCLUDE
#include	"ShaderBuffer.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�V�F�[�_�[�C���^�[�t�F�C�X

			�V�F�[�_�[�ւ̃p�����[�^�[�ݒ�������Ȃ����߂̃o�b�t�@�C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CShaderBufferBase : public IShaderBuffer {
	protected:
		/*******************//*!
		���O
		*//********************/
		CString						m_Name;
		/*******************//*!
		�o�b�t�@�T�C�Y
		*//********************/
		MofU32						m_Size;
		/*******************//*!
		�o�b�t�@
		*//********************/
		LPMofVoid					m_pBuffer;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CShaderBufferBase();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�V�F�[�_�[

				@return			None
		*//**************************************************************************/
		CShaderBufferBase(const CShaderBufferBase& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CShaderBufferBase();
		
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
				@brief			���O�ݒ�
				@param[in]		pName			�ݒ肷�閼�O
				
				@return			TRUE			����I��<br>
								����ȊO		�ݒ�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetName(LPCMofChar pName);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			���O�擾
				@param			None

				@return			���O�̎擾
		*//**************************************************************************/
		virtual LPString GetName(void);
		/*************************************************************************//*!
				@brief			�o�b�t�@�T�C�Y�擾
				@param			None

				@return			�o�b�t�@�T�C�Y
		*//**************************************************************************/
		virtual MofU32 GetBufferSize(void) const;
	};

	#include	"ShaderBufferBase.inl"
}

#endif

//[EOF]