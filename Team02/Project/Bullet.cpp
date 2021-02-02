#include "Bullet.h"



CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Create(CTexture * texturePointer, float posx, float posy)
{
	Texture = texturePointer;
	Position = CVector2(posx, posy);
	IsShow = true;
}

void CBullet::Update()
{
	if (Position.y >  -10 )
	{
		Position.y -= BULLET_SPEED;
	}
	else
	{
		IsShow = false;
	}

}

void CBullet::Render()
{
	Texture->Render(Position.x,Position.y);
}
