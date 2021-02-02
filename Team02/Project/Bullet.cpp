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
	if (Position.y >  - (int)Texture->GetHeight())
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

void CBullet::RenderDebug(int i)
{
	CGraphicsUtilities::RenderString(0,250 + (50 * i),"íeç¿ïW X %1f : Y  %2f" , Position.x , Position.y);
}
