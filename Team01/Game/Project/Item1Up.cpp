#include "Item1Up.h"

CItem1Up::CItem1Up() :
	super() {
}

CItem1Up::~CItem1Up() {
}

bool CItem1Up::Use(CCharacter & out) {
	out.AddRevivalCount();
	return true;
}