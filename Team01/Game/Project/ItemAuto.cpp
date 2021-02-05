#include "ItemAuto.h"

CItemAuto::CItemAuto() :
	super() {
}

CItemAuto::~CItemAuto() {
}

bool CItemAuto::Use(CCharacter & out) {
	out.AttachAutoShot();
	return true;
}