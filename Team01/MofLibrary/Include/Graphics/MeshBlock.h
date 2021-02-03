/*************************************************************************//*!
					
					@file	MeshBlock.h
					@brief	���b�V�����C���^�[�t�F�C�X�B

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__MESHBLOCK__H__

#define		__MESHBLOCK__H__

//INCLUDE
#include	"Geometry.h"

namespace Mof {
	
	/*******************************//*!
	@brief	���b�V���C���^�[�t�F�C�X

			���b�V���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IGeometryBlock : public IMofNamedObject, public IMofCopyObject< IGeometryBlock > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�C���f�b�N�X�o�b�t�@�擾
				@param			None

				@return			�C���f�b�N�X�o�b�t�@�̎擾
		*//**************************************************************************/
		virtual LPIndexBuffer GetIndexBuffer(void) = 0;
		
	};

	//�|�C���^�u������
	typedef IGeometryBlock*				LPGeometryBlock;
	typedef CDynamicArray< LPGeometryBlock >		CGeometryBlockArray, *LPGeometryBlockArray;
	
	/*******************************//*!
	@brief	���b�V���N���X

			���b�V���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CGeometryBlock : public IGeometryBlock {
	private:
		/*******************//*!
		�Ή��W�I���g��
		*//********************/
		LPGeometry			m_pGeometry;
		/*******************//*!
		�C���f�b�N�X�o�b�t�@
		*//********************/
		LPIndexBuffer		m_pIndexBuffer;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		box				�͈͗pAABB
				@param[in]		pGeom			�Ή��W�I���g��

				@return			None
		*//**************************************************************************/
		CGeometryBlock(CBoxAABB& box, LPGeometry pGeom);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CGeometryBlock(const CGeometryBlock& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CGeometryBlock();
		
		/*************************************************************************//*!
				@brief			�R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		IGeometryBlock* CreateCopyObject(void) const;

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
				@brief			�C���f�b�N�X�o�b�t�@�擾
				@param			None

				@return			�C���f�b�N�X�o�b�t�@�̎擾
		*//**************************************************************************/
		virtual LPIndexBuffer GetIndexBuffer(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CGeometryBlock, MOF_TEMPORARYCLASS_ID);
	};

	/*******************************//*!
	@brief	���b�V���C���^�[�t�F�C�X

			���b�V���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IMeshBlock : public IMofNamedObject, public IMofCopyObject< IMeshBlock > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�u���b�N�z��擾
				@param			None

				@return			�u���b�N�z��̎擾
		*//**************************************************************************/
		virtual LPGeometryBlockArray GetBlockArray(void) = 0;
	};

	//�|�C���^�u������
	typedef IMeshBlock*				LPMeshBlock;
	typedef CDynamicArray< LPMeshBlock >		CMeshBlockArray, *LPMeshBlockArray;
	
	/*******************************//*!
	@brief	���b�V���N���X

			���b�V���N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CMeshBlock : public IMeshBlock {
	private:
		/*******************//*!
		���O
		*//********************/
		CString						m_Name;
		/*******************//*!
		�Ή��{�b�N�X
		*//********************/
		CBoxAABB					m_BlockAABB;
		/*******************//*!
		�Ή��W�I���g��
		*//********************/
		LPGeometryBlockArray		m_pGeometryArray;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		box				�͈͗pAABB
				@param[in]		pName			���O
				@param[in]		pGeom			�Ή��W�I���g��

				@return			None
		*//**************************************************************************/
		CMeshBlock(CBoxAABB& box, LPCMofChar pName, LPGeometryArray pGeom);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CMeshBlock(const CMeshBlock& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CMeshBlock();
		
		/*************************************************************************//*!
				@brief			�R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		IMeshBlock* CreateCopyObject(void) const;

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
				@brief			�u���b�N�z��擾
				@param			None

				@return			�u���b�N�z��̎擾
		*//**************************************************************************/
		virtual LPGeometryBlockArray GetBlockArray(void);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CMeshBlock, MOF_TEMPORARYCLASS_ID);
	};

	/*******************************//*!
	@brief	���b�V���u���b�N���

			���b�V���u���b�N���B

	@author	CDW
	*//********************************/
	typedef struct tag_BLOCKPARAMETER {
		CBoxAABB						ModelBox;									//!<���f����
		CVector3						InverseSize;								//!<�T�C�Y�t��
		CVector3						OffsetPosition;								//!<�I�t�Z�b�g�ʒu
		MofU16							XCount;										//!<X�̐�
		MofU16							YCount;										//!<Y�̐�
		MofU16							ZCount;										//!<Z�̐�
	}BLOCKPARAMETER, *LPBLOCKPARAMETER;
	
	/*******************************//*!
	@brief	���b�V���C���^�[�t�F�C�X

			���b�V���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API IBlockContainer : public IMofObject, public IMofCopyObject< IBlockContainer > {
	private:
	public:
		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�p�����[�^�[�擾
				@param			None

				@return			�p�����[�^�[�̎擾
		*//**************************************************************************/
		virtual LPBLOCKPARAMETER GetParameter(void) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�z��擾
				@param			None

				@return			�u���b�N�z��̎擾
		*//**************************************************************************/
		virtual LPMeshBlockArray GetBlockArray(void) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�ԍ��擾
				@param[in]		v				�u���b�N���W
				@param[out]		ox				�u���b�N�w�ԍ�
				@param[out]		oy				�u���b�N�x�ԍ�
				@param[out]		oy				�u���b�N�y�ԍ�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool GetBlockPos(Vector3& v, MofU16* ox, MofU16* oy, MofU16* oz) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�ԍ��擾
				@param[in]		x				�u���b�N�w�ԍ�
				@param[in]		y				�u���b�N�x�ԍ�
				@param[in]		y				�u���b�N�y�ԍ�
				
				@return			���W�̃u���b�N�ԍ�
		*//**************************************************************************/
		virtual MofU32 GetBlockNo(MofU16 x, MofU16 y, MofU16 z) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�ԍ��擾
				@param[in]		v				�u���b�N���W
				
				@return			���W�̃u���b�N�ԍ�
		*//**************************************************************************/
		virtual MofU32 GetBlockNo(Vector3& v) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�擾
				@param[in]		No				�u���b�N�ԍ�
				
				@return			�u���b�N
		*//**************************************************************************/
		virtual LPMeshBlock GetBlock(MofU32 No) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�擾
				@param[in]		x				�u���b�N�w�ԍ�
				@param[in]		y				�u���b�N�x�ԍ�
				@param[in]		y				�u���b�N�y�ԍ�
				
				@return			���W�̃u���b�N
		*//**************************************************************************/
		virtual LPMeshBlock GetBlock(MofU16 x, MofU16 y, MofU16 z) = 0;
		/*************************************************************************//*!
				@brief			�u���b�N�擾
				@param[in]		v				�u���b�N���W
				
				@return			���W�̃u���b�N
		*//**************************************************************************/
		virtual LPMeshBlock GetBlock(Vector3& v) = 0;
	};

	//�|�C���^�u������
	typedef IBlockContainer*				LPBlockContainer;
	
	/*******************************//*!
	@brief	���b�V���C���^�[�t�F�C�X

			���b�V���C���^�[�t�F�C�X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CBlockContainer : public IBlockContainer {
	private:
		/*******************//*!
		�ݒ�p�����[�^�[
		*//********************/
		BLOCKPARAMETER				m_Parameter;
		/*******************//*!
		�쐬�u���b�N
		*//********************/
		LPMeshBlockArray			m_pMeshBlock;
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CBlockContainer();
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[�W�I���g��

				@return			None
		*//**************************************************************************/
		CBlockContainer(const CBlockContainer& pObj);
		/*************************************************************************//*!
				@brief			�f�X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		virtual ~CBlockContainer();

		/*************************************************************************//*!
				@brief			�R�s�[����
				@param			None
				
				@return			�쐬���ꂽ�R�s�[<br>
								�쐬�Ɏ��s�����ꍇNULL��Ԃ�
		*//**************************************************************************/
		IBlockContainer* CreateCopyObject(void) const;

		/*************************************************************************//*!
				@brief			���
				@param[in]		pData			����ǉ��f�[�^

				@return			TRUE			����I��<br>
								����ȊO		����G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool Release(LPMofVoid pData = NULL);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		/*************************************************************************//*!
				@brief			�p�����[�^�[�擾
				@param			None

				@return			�p�����[�^�[�̎擾
		*//**************************************************************************/
		virtual LPBLOCKPARAMETER GetParameter(void);
		/*************************************************************************//*!
				@brief			�u���b�N�z��擾
				@param			None

				@return			�u���b�N�z��̎擾
		*//**************************************************************************/
		virtual LPMeshBlockArray GetBlockArray(void);
		/*************************************************************************//*!
				@brief			�u���b�N�ԍ��擾
				@param[in]		v				�u���b�N���W
				@param[out]		ox				�u���b�N�w�ԍ�
				@param[out]		oy				�u���b�N�x�ԍ�
				@param[out]		oy				�u���b�N�y�ԍ�
				
				@return			TRUE			����I��<br>
								����ȊO		�G���[�A�G���[�R�[�h��Ԃ��B
		*//**************************************************************************/
		virtual MofBool GetBlockPos(Vector3& v, MofU16* ox, MofU16* oy, MofU16* oz);
		/*************************************************************************//*!
				@brief			�u���b�N�ԍ��擾
				@param[in]		x				�u���b�N�w�ԍ�
				@param[in]		y				�u���b�N�x�ԍ�
				@param[in]		y				�u���b�N�y�ԍ�
				
				@return			���W�̃u���b�N�ԍ�
		*//**************************************************************************/
		virtual MofU32 GetBlockNo(MofU16 x, MofU16 y, MofU16 z);
		/*************************************************************************//*!
				@brief			�u���b�N�ԍ��擾
				@param[in]		v				�u���b�N���W
				
				@return			���W�̃u���b�N�ԍ�
		*//**************************************************************************/
		virtual MofU32 GetBlockNo(Vector3& v);
		/*************************************************************************//*!
				@brief			�u���b�N�擾
				@param[in]		No				�u���b�N�ԍ�
				
				@return			�u���b�N
		*//**************************************************************************/
		virtual LPMeshBlock GetBlock(MofU32 No);
		/*************************************************************************//*!
				@brief			�u���b�N�擾
				@param[in]		x				�u���b�N�w�ԍ�
				@param[in]		y				�u���b�N�x�ԍ�
				@param[in]		y				�u���b�N�y�ԍ�
				
				@return			���W�̃u���b�N
		*//**************************************************************************/
		virtual LPMeshBlock GetBlock(MofU16 x, MofU16 y, MofU16 z);
		/*************************************************************************//*!
				@brief			�u���b�N�擾
				@param[in]		v				�u���b�N���W
				
				@return			���W�̃u���b�N
		*//**************************************************************************/
		virtual LPMeshBlock GetBlock(Vector3& v);

		//�N���X��{��`
		MOF_LIBRARYCLASS(CBlockContainer, MOF_TEMPORARYCLASS_ID);
	};

	#include	"MeshBlock.inl"
}

#endif	//__MESHBLOCK__H__

//[EOF]