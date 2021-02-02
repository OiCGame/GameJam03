#include "EnemyMove.h"

#include "Enemy.h"


EnemyMove::EnemyMove() {
}

EnemyMove::~EnemyMove() {
}

Mof::CVector2 EnemyMove::ConputeSpeedValue(CEnemy * ptr) {
	return Mof::CVector2(0.0, 1.0f);
}