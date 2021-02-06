#include "ItemBulletPowerUp2.h"


CItemBulletPowerUp2::CItemBulletPowerUp2() :
	super() {
}

CItemBulletPowerUp2::~CItemBulletPowerUp2() {
}

bool CItemBulletPowerUp2::Use(CCharacter & out) {
	out.BulletPowerUp(2.0f);
	return true;
}