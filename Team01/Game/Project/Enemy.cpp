#include "Enemy.h"


void CEnemy::Move(void) {
	 _speed =  _move_controller.ConputeSpeedValue(this);
	 _move += _speed;
}

CEnemy::CEnemy() :
	super(),
	_move_controller() {
}