#pragma once
#include "Mof.h"

struct Cloud
{
	CVector2 Pos;
	bool Right;
};

struct WaveData
{
	std::vector<Cloud> CloudPositions;
	int   EnemyAmount;
	float EnemySpeed;
};

typedef std::vector<WaveData> StageData;

