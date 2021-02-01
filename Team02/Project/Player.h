#pragma once
#include	"Mof.h"

class CPlayer
{
private:
	CTexture		PlayerTexture;
	CVector2		PlayerPosition;
	CRectangle		PlayerRectangle;

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
