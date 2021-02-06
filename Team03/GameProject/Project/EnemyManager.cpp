#include "EnemyManager.h"

CEnemyManager::CEnemyManager() :
	m_pEnemyArray() ,
	m_MovePosArray(),
	m_MoveTime(0.0f)
{
}

CEnemyManager::~CEnemyManager()
{
	Release();
}

CEnemyManager & CEnemyManager::Singleton(void)
{
	static CEnemyManager instance;
	return instance;
}

void CEnemyManager::Initialize(void)
{
}

void CEnemyManager::Update(void)
{
	// éÄñSÇµÇΩìGÇÃçÌèú
	auto it =std::remove_if(
		m_pEnemyArray.begin(),
		m_pEnemyArray.end(),
		[](std::shared_ptr<CEnemy> enemy) { return !enemy->IsShow(); });
	m_pEnemyArray.erase(it, m_pEnemyArray.end());

	m_MoveTime -= CUtilities::GetFrameSecond();

	// çXêV
	for (auto enemy : m_pEnemyArray)
	{
		if (enemy->IsMoveEnd() && m_MoveTime > 0)
		{
			bool end = false;
			int Rnd = 0;
			while (!end)
			{
				end = true;
				Rnd = CUtilities::Random(m_MovePosArray.size());
				for (int i = 0; i < CEnemyManager::Singleton().GetEnemyCount(); i++)
				{
					if (m_EnemyMovePosArray[i] == Rnd)
					{
						end = false;
					}
				}
			}
			m_EnemyMovePosArray[enemy->GetEnemyNum()] = Rnd;
			enemy->SetMoveParameter(m_MovePosArray[Rnd], m_MoveType, m_MoveSpeed, m_TeleportInterval);
		}
		enemy->Update();
	}
}

void CEnemyManager::Render(void)
{
	for (auto enemy : m_pEnemyArray)
	{
		enemy->Render();
	}
}

void CEnemyManager::Release(void)
{
	for (auto enemy : m_pEnemyArray)
	{
		enemy->Release();
		enemy.reset();
	}
	m_pEnemyArray.clear();
	m_MovePosArray.clear();
}

void CEnemyManager::StartMove(float Time, CVector2 speed, int type, float TeleportInterval)
{
	m_EnemyMovePosArray.resize(CEnemyManager::Singleton().GetEnemyCount());
	for (int i = 0; i < CEnemyManager::Singleton().GetEnemyCount(); i++)
	{
		m_EnemyMovePosArray[i] = -1;
	}
	int num = 0;
	for (auto enemy : m_pEnemyArray)
	{
		enemy->SetEnemyNum(num);
		num++;
	}
	m_MoveTime = Time;
	m_MoveSpeed = speed;
	m_MoveType = type;
	m_TeleportInterval = TeleportInterval;
}

void CEnemyManager::StartShot(const LauncherInit_Line & init)
{
	for (auto enemy : m_pEnemyArray)
	{
		enemy->Shot(init);
	}
}

void CEnemyManager::StartShot(const LauncherInit_Polygon & init)
{
	for (auto enemy : m_pEnemyArray)
	{
		enemy->Shot(init);
	}
}

void CEnemyManager::StartShot(const LauncherInit_PolygonRotation & init)
{
	for (auto enemy : m_pEnemyArray)
	{
		enemy->Shot(init);
	}
}

void CEnemyManager::AddEnemy(const std::shared_ptr<CEnemy>& penemy)
{
	m_pEnemyArray.push_back(penemy);
}

void CEnemyManager::AddMovePos(CVector2 mPos)
{
	m_MovePosArray.push_back(mPos);
}

std::shared_ptr<CEnemy> CEnemyManager::GetEnemy(int i) const
{
	try
	{
		m_pEnemyArray.at(i);
	}
	catch (std::out_of_range&)
	{
		return nullptr;
	}
	return m_pEnemyArray[i];
}

int CEnemyManager::GetEnemyCount(void)
{
	return m_pEnemyArray.size();
}

bool CEnemyManager::IsMoveEnd(void)
{
	if (m_MoveTime > 0)
	{
		return false;
	}
	for (auto enemy : m_pEnemyArray)
	{
		if (!enemy->IsMoveEnd())
		{
			return false;
		}
	}
	return true;
}

bool CEnemyManager::IsShotEnd(void)
{
	return CEnemyBulletManager::Singleton().GetBulletList()->size() == 0;
}
