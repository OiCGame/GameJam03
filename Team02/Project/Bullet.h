#pragma once

#include "Mof.h"

constexpr auto BULLET_SPEED = 6;

constexpr auto BULLET_CATEGORY = 2;

enum BulletType
{
	Triangle,
	Square,
	Empty
};

class CBullet
{
private:
	CTexture*			Texture;
	CVector2			Position;
	CCircle				Collision;
	bool				IsShow;
	int					BulletType;
	int					Rotate;

	CRectangle			SquRect;
	CRectangle			TriRect;
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

	float		GetXPos() { return Position.x; }
	CRectangle GetBulletRect[2] = {
		SquRect,		//ŽlŠp‚Ì‹éŒ`
		TriRect			//ŽOŠp‚Ì‹éŒ` ???
	};
};
