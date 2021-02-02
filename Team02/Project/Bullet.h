#pragma once

#include "Mof.h"

#define		BULLET_SPEED	6

class CBullet
{
private:
	CTexture*			Texture;
	CVector2			Position;
	bool				IsShow;
public:
	CBullet();
	~CBullet();

	void	Create(CTexture* texturePointer , float posx , float posy);
	void	Update();
	void	Render();
	void	RenderDebug(int i);

	bool	GetShow() { return IsShow; }
};
