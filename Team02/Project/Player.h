#pragma once
#include	"Mof.h"
#include	"Bullet.h"

class CPlayer
{
private:
	CTexture				Texture;
	CTexture				BulletTexture[2];
	CVector2				position;
	CCircle					Collision;
	float					CollisionRadius;
	CVector2				CollisionPosCorrection;

	enum BulletType
	{
		Triangle,
		Square,
		Empty
	};

	int						BulletBuffer;
	CDynamicArray<CBullet>	Bullets;

public:
	CPlayer();
	~CPlayer();
	void		Load();
	void		Initialize();
	void		Update();
	void		ShotBullet(int bullettype);
	void		Render();
	void		RenderDebug();
	void		Release();

	CVector2	GetPosition() { return position; }
	void		SetBullet(int bulletype) { BulletBuffer = bulletype; }
};
