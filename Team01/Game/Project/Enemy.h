#pragma once


#include "Character.h"

#include "EnemyMove.h"


class CEnemy : public CCharacter {
	using super = CCharacter;
private:
	//! 移動機能
	EnemyMove _move_controller;
	/// <summary>
	/// 移動
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void);
public:

	CEnemy();
};