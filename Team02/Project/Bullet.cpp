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
	Collision = CCircle(posx + (Texture->GetWidth()*0.5) , posy + (Texture->GetHeight() * 0.5) , (float)Texture->GetWidth() * 0.5);
	IsShow = true;
}

void CBullet::Update()
{
	if (!IsShow) { return; }

	if (Position.y >  - (int)Texture->GetHeight())
	{
		Position.y -= BULLET_SPEED;
		Collision.x = Position.x + Texture->GetWidth() * 0.5;
		Collision.y = Position.y + Texture->GetHeight() * 0.5;
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
	CGraphicsUtilities::RenderCircle(Collision, MOF_COLOR_GREEN);
}
