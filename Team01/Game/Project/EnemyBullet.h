#pragma once
#include <Mof.h>

class CEnemyBullet
{
private:
	Vector2 m_Pos;
	Vector2 m_Move;
	float m_Radius;
	float m_Speed;
	float m_Dir;
	bool m_bDrow;


public:
	CEnemyBullet();
	~CEnemyBullet();

	void Initialize(float dir);
	void Generation(Vector2 pos);
	void Update();
	void Render();
	void Release();
};

