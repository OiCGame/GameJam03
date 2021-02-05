#pragma once
#include "Mof.h"
#include "EnemyBulletManager.h"

#define		AFTERIMAGE_INTERVAL		5

enum EnemyType
{
	TYPE_TELEPORT,
	TYPE_MOVE,
	TYPE_ALL,
};
enum EnemyPhase
{
	PHASE_MOVE,
	PHASE_ATTACK,
};

class CEnemy
{
private:
	CVector2 m_Position;	// �ʒu
	CVector2 m_MoveSpeed;		// �ړ���
	CVector2 m_MovePos;		// �ړ���̈ʒu
	CVector2 m_OldPos[5];	// �ړ������ʒu�̕ۑ�
	CTexture* m_EnemyTexture;// �e�N�X�`��
	int m_Type;
	bool m_bShow;
	int m_AfterimageInterval;
	bool m_MoveEnd;
	float m_TeleportInterval;
public:
	// �R���X�g���N�^
	CEnemy();

	// �f�X�g���N�^
	~CEnemy();

	// ������
	bool Initialize();

	// �X�V
	void Update(void);

	// �`��
	void Render(void);
	
	// ���
	void Release(void);

	// �ړ��̍X�V
	void UpdateMove(void);

	// �e�̔���
	void Shot(const LauncherInit_Line & init);
	void Shot(const LauncherInit_Polygon & init);
	void Shot(const LauncherInit_PolygonRotation & init);
	

	// �ړ��ɕK�v�ȃp�����[�^�[��ݒ�
	void SetMoveParameter(CVector2 mPos, int type, CVector2 speed);

	// ��`�̎擾
	CRectangle GetRectangle(void);

	// �~�̎擾
	CCircle GetCircle(void);
	
	// ���S���W�̎擾
	CVector2 GetCenterPos(void);

	bool IsShow(void);
	void SetShow(bool b) { m_bShow = b; }

	bool IsMoveEnd(void);
};

