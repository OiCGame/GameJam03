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
	bool m_bDraw;


public:
	CEnemyBullet();
	~CEnemyBullet();

	void Initialize(float dir);
	void Generation(Vector2 pos);
	int Collition(CRectangle prec);
	void Update();
	void Render();
	void Release();

	CRectangle GetRec() { return CRectangle(m_Pos.x - 10, m_Pos.y - 10, m_Pos.x + 10, m_Pos.y + 10); }
};

