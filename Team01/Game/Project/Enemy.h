#pragma once


#include "Character.h"

class CEnemy : public CCharacter {
	using super = CCharacter;
private:
	/// <summary>
	/// ˆÚ“®
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void) override;
public:
	CEnemy();
	virtual bool Update(std::array<CBullet, 256>& bullet_container);
};