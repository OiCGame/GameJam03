#include "ItemBulletPowerUp1.h"


CItemBulletPowerUp1::CItemBulletPowerUp1() :
	super() {
}

CItemBulletPowerUp1::~CItemBulletPowerUp1() {
}

bool CItemBulletPowerUp1::Use(CCharacter & out) {
	out.BulletPowerUp(2);
	return true;
}