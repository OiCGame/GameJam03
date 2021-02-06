#pragma once
#include <vector>
#include <memory>
#include "Enemy.h"
#include "EnemyBulletManager.h"

class CEnemyManager
{
private:
	std::vector<std::shared_ptr<CEnemy>> m_pEnemyArray;
	std::vector<CVector2> m_MovePosArray;
	std::vector<int> m_EnemyMovePosArray;

	float m_MoveTime;
	CVector2 m_MoveSpeed;
	int m_MoveType;
	float m_TeleportInterval;

	// �R���X�g���N�^
	CEnemyManager();

	//�f�X�g���N�^
	~CEnemyManager();
public:
	// �V���O���g��
	static CEnemyManager& Singleton(void);

	// ������
	void Initialize(void);

	// �X�V
	void Update(void);

	// �`��
	void Render(void);

	// ���
	void Release(void);

	// �ړ��̊J�n
	void StartMove(float Time,CVector2 speed,int type, float TeleportInterval);

	// �e�̔���
	void StartShot(const LauncherInit_Line & init);
	void StartShot(const LauncherInit_Polygon & init);
	void StartShot(const LauncherInit_PolygonRotation & init);

	// �o�^
	void AddEnemy(const std::shared_ptr<CEnemy> & penemy);

	// �ړ��ʒu�̓o�^
	void AddMovePos(CVector2 mPos);

	// �擾
	std::shared_ptr<CEnemy> GetEnemy(int i) const;

	// �G���̎擾
	int GetEnemyCount(void);

	bool IsMoveEnd(void);

	bool IsShotEnd(void);
};

