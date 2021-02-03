/*************************************************************************//*!
					
					@file	IndexBufferBase.h
					@brief	�C���f�b�N�X�o�b�t�@���N���X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__INDEXBUFFERBASE__H__

#define		__INDEXBUFFERBASE__H__

//INCLUDE
#include	"IndexBuffer.h"

namespace Mof {
	
	/*******************************//*!
	@brief	�C���f�b�N�X�o�b�t�@���N���X

			�C���f�b�N�X�o�b�t�@�̍쐬�A�ݒ���s�����߂̊��N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CIndexBufferBase : public IIndexBuffer {
	protected:
		/*******************//*!
		�C���f�b�N�X�f�[�^
		*//********************/
		LPMofVoid					m_pIndex;
		/*******************//*!
		�C���f�b�N�X�T�C�Y
		*//********************/
		MofU32						m_Size;
		/*******************//*!
		�C���f�b�N�X��
		*//********************/
		MofU32						m_Count;
		/*******************//*!
		�o�b�t�@�Ǘ����@
		*//********************/
		BufferAccess				m_Usage;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CIndexBufferBase();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�o�b�t�@

				@return			None
		*//**************************************************************************/
		CIndexBufferBase(const CIndexBufferBase& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CIndexBufferBase();
		
		/*************************************************************************//*!
				@brief			�o�b�t�@�̍쐬
				@param			None
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CreateBuffer(void) = 0;
		/*************************************************************************//*!
				@brief			�o�b�t�@�̍쐬
				@param[in]		s				�T�C�Y
				@param[in]		c				��
				@param[in]		pInd			�C���f�b�N�X�f�[�^
				@param[in]		Usage			���p���@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool CreateBuffer(const MofU32 s, const MofU32 c, LPCMofVoid pInd, const BufferAccess Usage);

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
				@param[in]		s				�T�C�Y
				@param[in]		c				��
				@param[in]		pInd			�C���f�b�N�X�f�[�^
				@param[in]		Usage			���p���@
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool SetBufferData(const MofU32 s, const MofU32 c, LPCMofVoid pInd, const BufferAccess Usage);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�擾
				@param			None

				@return			�C���f�b�N�X�̎擾
		*//**************************************************************************/
		virtual LPMofVoid GetIndex(void) const;
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�擾
				@param			None

				@return			�C���f�b�N�X�̎擾<br>
								�T�C�Y��16bit�C���f�b�N�X�ł͂Ȃ��ꍇNULL
		*//**************************************************************************/
		virtual LPMofU16 GetIndexU16(void);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�擾
				@param			None

				@return			�C���f�b�N�X�̎擾<br>
								�T�C�Y��32bit�C���f�b�N�X�ł͂Ȃ��ꍇNULL
		*//**************************************************************************/
		virtual LPMofU32 GetIndexU32(void);
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�T�C�Y�擾
				@param			None

				@return			�C���f�b�N�X�T�C�Y�̎擾
		*//**************************************************************************/
		virtual MofU32 GetIndexSize(void) const;
		/*************************************************************************//*!
				@brief			�C���f�b�N�X���擾
				@param			None

				@return			�C���f�b�N�X���̎擾
		*//**************************************************************************/
		virtual MofU32 GetIndexCount(void) const;
	};

	#include	"IndexBufferBase.inl"
}

#endif

//[EOF]