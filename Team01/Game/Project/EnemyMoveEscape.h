#pragma once


#include "EnemyMove.h"


class EnemyMoveEscape : public EnemyMove {
private:
public:
	EnemyMoveEscape();
	~EnemyMoveEscape();

	virtual Mof::CVector2 ConputeSpeedValue(CEnemy* ptr) override;
};