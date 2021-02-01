#pragma once


#include "Character.h"

class CEnemy : public CCharacter {
	using super = CCharacter;
public:
	CEnemy();
	virtual bool Update(std::array<CBullet, 256>& bullet_container);
};