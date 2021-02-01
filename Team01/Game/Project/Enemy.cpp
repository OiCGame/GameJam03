#include "Enemy.h"

void CEnemy::Move(void) {
	_position.y += 1;
}

CEnemy::CEnemy() :
	super() {
}

bool CEnemy::Update(std::array<CBullet, 256>& bullet_container) {
	this->Move();
	return true;
}