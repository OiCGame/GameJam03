#pragma once
#include	"Mof.h"

class CPlayer
{
private:
	CTexture		Texture;
	CVector2		position;
	CCircle			Collision;
	float			CollisionRadius;
	CVector2		CollisionPosCorrection;

	enum BulletType
	{
		Empty,
		Triangle,
		Square
	};

	int				BulletBuffer;

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
