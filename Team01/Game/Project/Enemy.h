#pragma once


#include "Character.h"

#include "EnemyMove.h"


class CEnemy : public CCharacter {
	using super = CCharacter;
private:
	//! ˆÚ“®‹@”\
	EnemyMove _move_controller;
	/// <summary>
	/// ˆÚ“®
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void);
public:

	CEnemy();
};