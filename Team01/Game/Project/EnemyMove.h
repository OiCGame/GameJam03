#pragma once


#include <Mof.h>


class CEnemy;
class EnemyMove {
private:
public:
	EnemyMove();
	virtual ~EnemyMove();
	/// <summary>
	/// �ړ�
	/// </summary>
	/// <param name=""></param>
	virtual Mof::CVector2 ConputeSpeedValue(CEnemy* ptr);
};