#pragma once
#include	"Mof.h"
#include	"Bullet.h"
#include	"Panel.h"

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

	/*enum BulletType		//Bullet.h�ɂčċL�q .... Panel.h�ł��g�������ł�
	{
		Triangle,
		Square,
		Empty
	};*/

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

	CPanel					Panel;
	//�v���C����UI�����̂͗ǂ��Ȃ������B��������ňړ������܂�
	CTexture				BulletUITexture[BULLET_CATEGORY];	
	CTexture				UIFrameTexture;
	CVector2				BulletUIPosition;

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
	bool		IsBulletBuffer() { return BulletBuffer < Empty ? true : false; }
};
