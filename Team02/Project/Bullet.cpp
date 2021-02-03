#include "Bullet.h"



CBullet::CBullet()
{
}

CBullet::~CBullet()
{
}

void CBullet::Create(CTexture * texturePointer, float posx, float posy ,int type , int rotate)
{
	Texture = texturePointer;
	Position = CVector2(posx, posy);
	Collision = CCircle(posx , posy , (float)Texture->GetWidth() * 0.4);
	IsShow = true;
	BulletType = type;
	Rotate = rotate;
}

void CBullet::Update()
{
	if (!IsShow) { return; }

	if (Position.y >  - (int)Texture->GetHeight())
	{
		Position.y -= BULLET_SPEED;
		Collision.x = Position.x;
		Collision.y = Position.y;
		GetBulletRect[0].Left = Position.x - 590 / 2;
		GetBulletRect[0].Right = GetBulletRect[0].Left + 590;
		GetBulletRect[0].Top = Position.y - 580 / 2;
		GetBulletRect[0].Bottom = GetBulletRect[0].Top + 580;
	}
	else
	{
		IsShow = false;
	}

}

void CBullet::Render()
{

	Texture->RenderRotate(Position.x,Position.y, 
		MOF_ToRadian(90 * Rotate),TEXTUREALIGNMENT_CENTERCENTER);
}

void CBullet::RenderDebug(int i)
{
	CGraphicsUtilities::RenderString(0, 300 + (50 * i), "íeç¿ïW X %1f : Y  %2f", Position.x, Position.y);
	CGraphicsUtilities::RenderCircle(Collision, MOF_COLOR_GREEN);
	CGraphicsUtilities::RenderRect(GetBulletRect[0], MOF_COLOR_GREEN);
}
