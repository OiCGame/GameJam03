#include "Item3Way.h"

CItem3Way::CItem3Way() :
super(){
}

CItem3Way::~CItem3Way() {
}

bool CItem3Way::Use(CCharacter & out) {
	out.Attach3WayShot();
	return true;
}
