#include "EnemyBulletManager.h"

CEnemyBulletManager & CEnemyBulletManager::Singleton()
{
	static CEnemyBulletManager obj;
	return obj;
}

// �e�̒P�̒ǉ�
void CEnemyBulletManager::addBullet(const CBullet & bullet)
{
	m_BulletList.push_back(bullet);
}

// �e�̕����ǉ�
void CEnemyBulletManager::addBulletList(const std::vector<CBullet>& bullets)
{
	std::copy(bullets.begin(), bullets.end(), std::back_inserter(m_BulletList));
}

// �w��x�N�g���֒P�̔���
void CEnemyBulletManager::SetLauncher(const LauncherInit_Line & init)
{
	float sumWiat = 0.0f;
	for (int i = 0; i < init.count; i++)
	{
		m_BulletList.push_back(CBullet());
		m_BulletList.back().Initialize(
			init.position,
			init.vector,
			sumWiat
		);
		sumWiat += init.interval;
	}
}

// ���p�`��ɔ���
void CEnemyBulletManager::SetLauncher(const LauncherInit_Polygon & init)
{
	// ���p�����߂� rad�p
	auto InternalAngle = (2 * MOF_MATH_PI) / init.vertex;

	auto work = 0.0f;
	if (init.vertex % 2 == 0) { // ����
		work = InternalAngle / 2.0f;
	}

	float sumWiat = 0.0f;
	for (int i = 0; i < init.count; i++) {
		for (int v = 0; v < init.vertex; v++)
		{
			m_BulletList.push_back(CBullet());
			m_BulletList.back().Initialize(
				init.position,
				CVector2(init.vector.x * sin(InternalAngle * v + work), -(init.vector.y * cos(InternalAngle * v + work))),
				sumWiat
			);
		}
		sumWiat += init.interval;
	}
}

// �X�V
void CEnemyBulletManager::Update()
{
	// �����m�F
	auto it = std::remove_if(
		m_BulletList.begin(),
		m_BulletList.end(),
		[](CBullet bullet) { return bullet.IsSurvival() == false; }
	);
	m_BulletList.erase(it, m_BulletList.end());

	// �X�V
	for (auto & bullet : m_BulletList) {
		bullet.Update();
	}
}

// �`��
void CEnemyBulletManager::Render()
{
	for (auto & bullet : m_BulletList) {
		bullet.Render();
	}
}
