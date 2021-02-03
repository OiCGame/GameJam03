/*************************************************************************//*!
					
					@file	Sphere.h
					@brief	�����Z�֘A

															@author	CDW
															@date	2014.05.14
*//**************************************************************************/

//ONCE
#ifndef		__SPHERE__H__

#define		__SPHERE__H__

//INCLUDE
#include	"CollisionCommon.h"

namespace Mof {

	/*******************************//*!
	@brief	3D���\����

			3D�����������߂̍\���́B

	@author	CDW
	*//********************************/
	typedef struct MOFLIBRARY_API Sphere {
		union {
			struct {
				MofFloat		x;						//!<X�ʒu
				MofFloat		y;						//!<Y�ʒu
				MofFloat		z;						//!<Z�ʒu
			};
			struct {
				Vector3Impl		Position;				//!<�ʒu
			};
		};
		MofFloat			r;							//!<���a
		
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		Sphere();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		cx			�w���W
				@param[in]		cy			�x���W
				@param[in]		cz			�y���W
				@param[in]		cr			���a

				@return			None
		*//**************************************************************************/
		Sphere(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pos			���W
				@param[in]		r			���a

				@return			None
		*//**************************************************************************/
		Sphere(const Vector3& pos,MofFloat cr);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pv			���W

				@return			None
		*//**************************************************************************/
		Sphere(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[��

				@return			None
		*//**************************************************************************/
		Sphere(const Sphere& pObj);
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------

		/*************************************************************************//*!
				@brief			float�L���X�g<br>
								�����̍��W��float�|�C���^�Ƃ��Ă��̂܂ܕԂ��B
		*//**************************************************************************/
		operator LPMofFloat ();
		/*************************************************************************//*!
				@brief			+=���Z
		*//**************************************************************************/
		Sphere& operator += ( const Vector3& v );
		/*************************************************************************//*!
				@brief			+=���Z
		*//**************************************************************************/
		Sphere& operator += ( const Sphere& v );
		/*************************************************************************//*!
				@brief			-=���Z
		*//**************************************************************************/
		Sphere& operator -= ( const Vector3& v );
		/*************************************************************************//*!
				@brief			-=���Z
		*//**************************************************************************/
		Sphere& operator -= ( const Sphere& v );
		/*************************************************************************//*!
				@brief			float�Ƃ�*=���Z
		*//**************************************************************************/
		Sphere& operator *= ( const MofFloat v );
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�*=���Z
		*//**************************************************************************/
		Sphere& operator *= ( const Vector3& v );
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�*=���Z
		*//**************************************************************************/
		Sphere& operator *= ( const Sphere& v );
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�*=���Z
		*//**************************************************************************/
		Sphere& operator *= ( const Matrix44& v );
		/*************************************************************************//*!
				@brief			float�Ƃ�/=���Z
		*//**************************************************************************/
		Sphere& operator /= ( const MofFloat v );
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�/=���Z
		*//**************************************************************************/
		Sphere& operator /= ( const Vector3& v );
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�/=���Z
		*//**************************************************************************/
		Sphere& operator /= ( const Sphere& v );
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�+���Z
		*//**************************************************************************/
		Sphere operator + ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�+���Z
		*//**************************************************************************/
		Sphere operator + ( const Sphere& v ) const;
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�+���Z
		*//**************************************************************************/
		Sphere operator - ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�-���Z
		*//**************************************************************************/
		Sphere operator - ( const Sphere& v ) const;
		/*************************************************************************//*!
				@brief			float�Ƃ�*���Z
		*//**************************************************************************/
		Sphere operator * ( const MofFloat v ) const;
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�*���Z
		*//**************************************************************************/
		Sphere operator * ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Matrix44�Ƃ�*���Z
		*//**************************************************************************/
		Sphere operator * ( const Matrix44& v ) const;
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�*���Z
		*//**************************************************************************/
		Sphere operator * ( const Sphere& v ) const;
		/*************************************************************************//*!
				@brief			float�Ƃ�/���Z
		*//**************************************************************************/
		Sphere operator / ( const MofFloat v ) const;
		/*************************************************************************//*!
				@brief			Vector3�Ƃ�/���Z
		*//**************************************************************************/
		Sphere operator / ( const Vector3& v ) const;
		/*************************************************************************//*!
				@brief			Sphere�Ƃ�/���Z
		*//**************************************************************************/
		Sphere operator / ( const Sphere& v ) const;
		/*************************************************************************//*!
				@brief			�z��w��ɂ��Sphere�����o�ւ̃A�N�Z�X
		*//**************************************************************************/
		MofFloat& operator [] ( int i );
		/*************************************************************************//*!
				@brief			�z��w��ɂ��Sphere�����o�ւ̃A�N�Z�X
		*//**************************************************************************/
		const MofFloat& operator [] ( int i ) const;
		/*************************************************************************//*!
				@brief			==���f
		*//**************************************************************************/
		bool operator == ( const Sphere& v ) const;
		/*************************************************************************//*!
				@brief			!=���f
		*//**************************************************************************/
		bool operator != ( const Sphere& v ) const;
		
	}Sphere;
	
	/*******************************//*!
	@brief	3D�����Z�N���X

			Sphere�\���̂��������߂̃X�^�e�B�b�N�N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSphereUtilities {
	public:
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
				@param[in]		r			���苅
				@param[in]		px			����X�ʒu
				@param[in]		py			����Y�ʒu
				@param[in]		pz			����Z�ʒu

				@return			TRUE		���̒��ɓ_������
								FALSE		���͈̔͊O
		*//**************************************************************************/
		static MofBool CollisionPoint(const Sphere& r,const MofFloat px,const MofFloat py,const MofFloat pz);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
				@param[in]		r			���苅
				@param[in]		p			����ʒu

				@return			TRUE		���̒��ɓ_������
								FALSE		���͈̔͊O
		*//**************************************************************************/
		static MofBool CollisionPoint(const Sphere& r,const Vector3& p);
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����Sphere�i���j���ڐG���Ă��邩�𔻒肷��
				@param[in]		r1			���苅
				@param[in]		r2			���苅
				
				@return			TRUE		�ڐG
								FALSE		�͈͊O
		*//**************************************************************************/
		static MofBool CollisionSphere(const Sphere& r1,const Sphere& r2);

	private:
		//�쐬���֎~����
		CSphereUtilities(){};
		CSphereUtilities(const CSphereUtilities& pObj){};
	};


	/*******************************//*!
	@brief	3D���N���X

			3D�����������߂̃N���X�B

	@author	CDW
	*//********************************/
	class MOFLIBRARY_API CSphere : public Sphere , public IMofBase {
	public:
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param			None

				@return			None
		*//**************************************************************************/
		CSphere();
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		cx			�w���W
				@param[in]		cy			�x���W
				@param[in]		cz			�y���W
				@param[in]		cr			���a

				@return			None
		*//**************************************************************************/
		CSphere(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pos			���W
				@param[in]		cr			���a

				@return			None
		*//**************************************************************************/
		CSphere(const Vector3& pos,MofFloat cr);
		/*************************************************************************//*!
				@brief			�R���X�g���N�^
				@param[in]		pv			���W

				@return			None
		*//**************************************************************************/
		CSphere(LPMofFloat pv);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[��

				@return			None
		*//**************************************************************************/
		CSphere(const Sphere& pObj);
		/*************************************************************************//*!
				@brief			�R�s�[�R���X�g���N�^
				@param[in]		pObj		�R�s�[��

				@return			None
		*//**************************************************************************/
		CSphere(const CSphere& pObj);
		
		/*************************************************************************//*!
				@brief			�ړ�<br>
								m�ړ�����B
				@param[in]		m			�ړ���
				
				@return			None
		*//**************************************************************************/
		void Translation(const Vector3& m);
		/*************************************************************************//*!
				@brief			�ړ�<br>
								pos�̈ʒu�Ɉړ�����B
				@param[in]		pos			�ʒu
				
				@return			None
		*//**************************************************************************/
		void SetPosition(const Vector3& pos);

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
				@param[in]		px			����X�ʒu
				@param[in]		py			����Y�ʒu
				@param[in]		pz			����Z�ʒu

				@return			TRUE		���̒��ɓ_������
								FALSE		���͈̔͊O
		*//**************************************************************************/
		MofBool CollisionPoint(const MofFloat px,const MofFloat py,const MofFloat pz) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��Vector3�i�|�C���g�j�����̒��ɓ����Ă��邩�𔻒肷��
				@param[in]		p			����ʒu

				@return			TRUE		���̒��ɓ_������
								FALSE		���͈̔͊O
		*//**************************************************************************/
		MofBool CollisionPoint(const Vector3& p) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��Sphere�i���j���ڐG���Ă��邩�𔻒肷��
				@param[in]		cx			����w�ʒu
				@param[in]		cy			����x�ʒu
				@param[in]		cz			����y�ʒu
				@param[in]		cr			���蔼�a
				
				@return			TRUE		�ڐG
								FALSE		�͈͊O
		*//**************************************************************************/
		MofBool CollisionSphere(const MofFloat cx,const MofFloat cy,const MofFloat cz,const MofFloat cr) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵��Sphere�i���j���ڐG���Ă��邩�𔻒肷��
				@param[in]		c			���苅
				
				@return			TRUE		�ڐG
								FALSE		�͈͊O
		*//**************************************************************************/
		MofBool CollisionSphere(const Sphere& c) const;
		
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		����W�I���g��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵���W�I���g���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�|���S���̏���out�Ɋi�[����
				@param[in]		pGeom		����W�I���g��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionGeometry(LPGeometry pGeom, COLLISIONOUTGEOMETRY& out) const;

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		���胁�b�V��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pGeom		���胁�b�V��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMesh pMesh, COLLISIONOUTMESH& out) const;

		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B
				@param[in]		pGeom		���胁�b�V��

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pGeom		���胁�b�V��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, COLLISIONOUTGEOMETRY& out) const;
		/*************************************************************************//*!
				@brief			�����蔻��<br>
								�w�肵�����b�V���ƌ������邩�𔻒肷��B<br>
								��������ꍇ�A�ڐG�W�I���g���̏���out�Ɋi�[����
				@param[in]		pGeom		���胁�b�V��
				@param[out]		out			�o�͐ڐG�|���S�����

				@return			TRUE		�ڐG����
								FALSE		�ڐG�Ȃ�
		*//**************************************************************************/
		MofBool CollisionMesh(LPMeshContainer pMesh, COLLISIONOUTMESHCONTAINER& out) const;

		/*************************************************************************//*!
				@brief			���l�̐ݒ�
				@param[in]		cx			�w���W
				@param[in]		cy			�x���W
				@param[in]		cz			�y���W
				@param[in]		cr			���a

				@return			None
		*//**************************************************************************/
		void SetValue(MofFloat cx,MofFloat cy,MofFloat cz,MofFloat cr);

		//----------------------------------------------------------------------------
		////Get
		//----------------------------------------------------------------------------
		
		//----------------------------------------------------------------------------
		////Operator
		//----------------------------------------------------------------------------

		/*************************************************************************//*!
				@brief			���
		*//**************************************************************************/
		CSphere& operator = ( const Sphere& v );

		//�N���X��{��`
		MOF_LIBRARYCLASS_NOTEQUAL(CSphere,MOF_SPHERECLASS_ID);
	};

	//�|�C���^�u������
	typedef CSphere*			LPSphere;

	//INLINE INCLUDE
	#include	"Sphere.inl"

}

#endif

//[EOF]