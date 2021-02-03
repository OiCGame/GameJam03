#include "EnemyManager.h"

CEnemyManager::CEnemyManager() :
	m_pEnemyArray() ,
	m_MovePosArray(),
	m_MoveTime(0.0f)
{
}

CEnemyManager::~CEnemyManager()
{
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
	// €–S‚µ‚½“G‚Ìíœ
	auto it =std::remove_if(
		m_pEnemyArray.begin(),
		m_pEnemyArray.end(),
		[](std::shared_ptr<CEnemy> enemy) { return !enemy->IsShow(); });
	m_pEnemyArray.erase(it, m_pEnemyArray.end());

	m_MoveTime -= CUtilities::GetFrameSecond();

	// XV
	for (auto enemy : m_pEnemyArray)
	{
		if (enemy->IsMoveEnd() && m_MoveTime > 0)
		{
			enemy->SetMoveParameter(m_MovePosArray[CUtilities::Random(m_MovePosArray.size())], m_MoveType, m_MoveSpeed);
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

void CEnemyManager::StartMove(float Time, CVector2 speed, int type)
{
	m_MoveTime = Time;
	m_MoveSpeed = speed;
	m_MoveType = type;
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
	return m_MoveTime <= 0;
}
