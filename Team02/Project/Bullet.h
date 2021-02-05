#pragma once

#include "Mof.h"

constexpr auto BULLET_SPEED = 6;

constexpr auto BULLET_CATEGORY = 3;

enum BulletType
{
	Triangle,
	Square,
	Empty
};

enum RotateType
{
	Up,
	Right,
	Down,
	Left
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

	CRectangle			BulletRect;
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
	float	GetPosX() { return Position.x; }
	CRectangle		GetRectangle() { return BulletRect; }
	int		GetRotate() { return Rotate; }
};
