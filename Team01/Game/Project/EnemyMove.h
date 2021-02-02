#pragma once


#include <Mof.h>


class CEnemy;
class EnemyMove {
private:
public:
	EnemyMove();
	virtual ~EnemyMove();
	/// <summary>
	/// ˆÚ“®
	/// </summary>
	/// <param name=""></param>
	virtual Mof::CVector2 ConputeSpeedValue(CEnemy* ptr);
};