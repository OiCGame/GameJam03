#pragma once


#include "Character.h"

#include "EnemyMove.h"


class CEnemy : public CCharacter {
	using super = CCharacter;
private:
	//! �ړ��@�\
	EnemyMove _move_controller;
	/// <summary>
	/// �ړ�
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void);
public:

	CEnemy();
};