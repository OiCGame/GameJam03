#pragma once

#include "Mof.h"

constexpr auto BULLET_SPEED = 6;

class CBullet
{
private:
	CTexture*			Texture;
	CVector2			Position;
	CCircle				Collision;
	bool				IsShow;
	int					BulletType;
	int					Rotate;
public:
	CBullet();
	~CBullet();

	void	Create(CTexture* texturePointer , float posx , float posy , int type , int rotate);
	void	Update();
	void	Render();
	void	RenderDebug(int i);

	bool	GetShow() { return IsShow; }
	void	SetShow(bool isShow) { IsShow = isShow; }
	int		GetBulletType() { return BulletType; }
};
