#pragma once
#include	"Mof.h"
#include	"Bullet.h"

constexpr auto BULLET_CATEGORY = 2;

class CPlayer
{
private:
	CTexture				Texture;
	CTexture				BulletTexture[BULLET_CATEGORY];
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
	enum RotateType
	{
		Up,
		Right,
		Down,
		Left
	};
	int						BulletRotate;

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
    CTexture*   GetBulletTexture(int bulletype) { return &BulletTexture[bulletype]; }
	bool		CheckHitCollision(CCircle hitcollision) { return Collision.CollisionCircle(hitcollision); }
};
