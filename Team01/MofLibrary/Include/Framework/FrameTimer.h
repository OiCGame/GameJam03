/*************************************************************************//*!
					
					@file	FrameTimer.h
					@brief	�t���[�����Ԃ��v���A�������邽�߂̊��C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__FRAMETIMER__H__

#define		__FRAMETIMER__H__

//INCLUDE
#include	"../Common/DynamicArray.h"

//!�~���b���b�ϊ�
#define		MOF_MSecToSec(x)						((x) * 0.001f)
//!�b���~���b�ϊ�
#define		MOF_SecToMSec(x)						((x) * 1000)

namespace Mof {
	
	/*******************************//*!
	@brief	�t���[���^�C�}�[���C���^�[�t�F�C�X

			�t���[�����Ԃ��v���A�������邽�߂̃C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IFrameTimer : public IMofBase {
	protected:
	public:
		/*************************************************************************//*!
				@brief			�^�C�}�[�̍X�V<br>
								�^�C�}�[�̍X�V���s���B<br>
								�O�񂱂̊֐����Ăяo����Ă���A������s�����܂ł̎��Ԃ��v�����t���[�����Ԃɐݒ肷��B<br>
								bWait��TRUE�Ȃ�ݒ肳��Ă���FPS�܂ł̗]�莞�ԕ���sleep�ɂ��ҋ@����B<br>
								FPS���ݒ肳��Ă��Ȃ��ꍇ��bWait��FALSE�̏ꍇ�͑ҋ@�����͍s���Ȃ��B
				@param[in]		bWait		FPS�E�F�C�g�t���O
			
				@return			None
		*//**************************************************************************/
		virtual void Update(MofBool bWait) = 0;
		
		/*************************************************************************//*!
				@brief			�w��~���b�̊Ԓ�~�������Ȃ�
				@param[in]		s			�X���[�v����
			
				@return			None
		*//**************************************************************************/
		static void Sleep(MofU32 s);

		//----------------------------------------------------------------------------
		////Set
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			FPS�̐ݒ�<br>
								FPS�̌Œ������ꍇ�ɐݒ���s���B<br>
								������FPS��0��ݒ肷��ƌŒ�Ȃ��̎��Ԍv���݂̂̏����ɂȂ�B
				@param[in]		s			FPS
			
				@return			TRUE		����ɐݒ肳�ꂽ<br>
								FALSE		�ݒ�̎��s
		*//**************************************************************************/
		virtual MofBool SetFPS(MofU32 s) = 0;
		/*************************************************************************//*!
				@brief			�t���[�����Ԃ̐ݒ�<br>
								���̃^�C�}�[�Ōo�߂����t���[�����Ԃ�������msec�ɍ����ւ���B
				@param[in]		s			�t���[������(msec)
			
				@return			TRUE		����ɐݒ肳�ꂽ<br>
								FALSE		�ݒ�̎��s
		*//**************************************************************************/
		virtual MofBool SetFrameMSecond(MofU32 s) = 0;

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			����FPS�擾
				@param			None

				@return			FPS�̐����l
		*//**************************************************************************/
		virtual MofU32 GetRestrictFPS(void) const = 0;
		/*************************************************************************//*!
				@brief			�����t���[�����Ԏ擾
				@param			None

				@return			�t���[�����Ԃ̐����l
		*//**************************************************************************/
		virtual MofU32 GetRestrictFrameTime(void) const = 0;
		/*************************************************************************//*!
				@brief			FPS�擾
				@param			None

				@return			�v�����ꂽFPS
		*//**************************************************************************/
		virtual MofU32 GetFPS(void) const = 0;
		/*************************************************************************//*!
				@brief			�t���[�����Ԏ擾<br>
								�擾����t���[�����Ԃ̒P�ʂ̓~���b
				@param			None

				@return			�t���[������(msec)
		*//**************************************************************************/
		virtual MofU32 GetUpdateFrameTime(void) const = 0;
		/*************************************************************************//*!
				@brief			�t���[�����Ԏ擾<br>
								�擾����t���[�����Ԃ̒P�ʂ̓~���b
				@param			None

				@return			�t���[������(msec)
		*//**************************************************************************/
		virtual MofU32 GetFrameMSecond(void) const = 0;
		/*************************************************************************//*!
				@brief			�t���[�����Ԏ擾<br>
								�擾����t���[�����Ԃ̒P�ʂ͕b
				@param			None

				@return			�t���[������(sec)
		*//**************************************************************************/
		virtual MofFloat GetFrameSecond(void) const = 0;
		/*************************************************************************//*!
				@brief			���ݎ��Ԃ��~���b�ŕԂ�
				@param			None

				@return			�~���b�ł̎���
		*//**************************************************************************/
		static MofU32 GetTimeMS(void);
	};
	
	//�|�C���^�u������
	typedef IFrameTimer*		LPFrameTimer;
}

#endif

//[EOF]