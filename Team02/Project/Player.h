#pragma once
#include	"Mof.h"
#include	"Bullet.h"

class CPlayer
{
private:
	CTexture				Texture;
	CTexture				BulletTexture[BULLET_CATEGORY];
	CVector2				position;
	CCircle					Collision;
	float					CollisionRadius;
	CVector2				CollisionPosCorrection;

	/*enum BulletType		//Bullet.h�ɂčċL�q .... Panel.h�ł��g�������ł�
	{
		Triangle,
		Square,
		Empty
	};*/

	int						BulletBuffer;
	CDynamicArray<CBullet>	Bullets;
	//�g�p�ӏ�������������Bullet.h�ɂčċL�q
	/*enum RotateType
	{
		Up,
		Right,
		Down,
		Left
	};*/
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
	void		SetBullet(int bullettype) { BulletBuffer = bullettype; }
    CTexture*   GetBulletTexture(int bullettype) { return &BulletTexture[bullettype]; }
	bool		CheckHitCollision(CCircle hitcollision) { return Collision.CollisionCircle(hitcollision); }
	bool		IsBulletBuffer() { return BulletBuffer < Empty ? true : false; }
    int         GetBulletBuffer() { return BulletBuffer; }
    int         GetBulletRotate() { return BulletRotate; }

	CDynamicArray<CBullet>*	GetBulletArray() { return &Bullets; }
};
