#include "ItemBulletPowerUp4.h"


CItemBulletPowerUp4::CItemBulletPowerUp4() :
	super() {
}

CItemBulletPowerUp4::~CItemBulletPowerUp4() {
}

bool CItemBulletPowerUp4::Use(CCharacter & out) {
	out.BulletPowerUp(8);
	return true;
}