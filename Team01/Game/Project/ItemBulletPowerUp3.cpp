#include "ItemBulletPowerUp3.h"


CItemBulletPowerUp3::CItemBulletPowerUp3() :
	super() {
}

CItemBulletPowerUp3::~CItemBulletPowerUp3() {
}

bool CItemBulletPowerUp3::Use(CCharacter & out) {
	out.BulletPowerUp(8);
	return true;
}