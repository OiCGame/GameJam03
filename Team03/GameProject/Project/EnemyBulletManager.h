#pragma once

#include	"Bullet.h"

// ����
struct LauncherInit_Line {
	// �ʒu 
	CVector2 position;
	// ���˃x�N�g��
	CVector2 vector;
	// �e�N�X�`���[�^�C�v
	BulletType type{ BulletType::red };
	//���ˉ�
	int count{ 1 };
	// ���ˊԊu [s]
	float interval{ 0.5f };
};

// ���p�`
struct LauncherInit_Polygon {
	// �ʒu 
	CVector2 position;
	// ���˃x�N�g��
	CVector2 vector;
	// �e�N�X�`���[�^�C�v
	BulletType type{ BulletType::yellow };
	//���ˉ�
	int count{ 1 };
	// ���ˊԊu [s]
	float interval{ 0.5f };
	// ���_��
	int vertex{ 8 };
};

// ���p�`�@��]�t��
struct LauncherInit_PolygonRotation {
	// �ʒu 
	CVector2 position;
	// ���˃x�N�g��
	CVector2 vector;
	// �e�N�X�`���[�^�C�v
	BulletType type{ BulletType::yellow };
	//���ˉ�
	int count{ 1 };
	// ���ˊԊu [s]
	float interval{ 0.5f };
	// ���_��
	int vertex{ 8 };
	// ���Z�p�x
	int addAngle{ 10 };
	// ���] 0�̏ꍇ���� 
	int reverseCount{ 0 };
};


class CEnemyBulletManager
{
private:
	// �e�̊Ǘ��z��
	std::vector<CBullet> m_BulletList;

public:
	// �V���O���g��
	static CEnemyBulletManager& Singleton();

	// �e�̒P�̒ǉ�
	void addBullet(const CBullet & bullet);
	// �e�̕����ǉ�
	void addBulletList(const std::vector<CBullet> & bullets);

	// �e�̔��˃p�^�[��
	// �w��x�N�g���֒P�̔���
	void SetLauncher(const LauncherInit_Line & init);
	// ���p�`��ɔ���
	void SetLauncher(const LauncherInit_Polygon & init);
	// ���p�`��ɉ�]���Ȃ��甭��
	void SetLauncher(const LauncherInit_PolygonRotation & init);

	// �����Ă���e�̎擾 (�R�X�g�������וۗ�)
	// std::vector<CBullet> GetAliveBulletList();

	std::vector<CBullet>* GetBulletList();

	// �X�V
	void Update();

	// �`��
	void Render();

};

