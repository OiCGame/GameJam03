#pragma once
#include	"Mof.h"

class CPlayer
{
private:
	CTexture		PlayerTexture;
	CVector2		PlayerPosition;
	CCircle			PlayerCollision;
	float			PlayerCollisionRadius;
	CVector2		PlayerCollisionPosCorrection;

public:
	CPlayer();
	~CPlayer();
	void		Load();
	void		Initialize();
	void		Update();
	void		Render();
	void		RenderDebug();
	void		Release();

	CVector2	GetPosition() { return PlayerPosition; }
};
