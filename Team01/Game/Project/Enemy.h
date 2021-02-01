#pragma once


#include "Character.h"


class CEnemy : public CCharacter {
	using super = CCharacter;
private:
protected:
public:
	CEnemy();
	virtual bool Update(std::array<CBullet, 256>& bullet_container);
};