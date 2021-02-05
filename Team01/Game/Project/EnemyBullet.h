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

	int		m_ReflectionCount;				// Å‘å”½Ë‰ñ”
	int		m_ReflectionNo;				// Œ»İ‚Ìc‚è”½Ë‰ñ”

	float m_PopRad;
	float m_PopLen;
	int m_PopDirCnt;

public:
	CEnemyBullet();
	~CEnemyBullet();

	void Initialize(float dir, int reflect = 0);
	void Generation(Vector2 pos);
	int Collision(CRectangle prec);
	void Update();
	void PopUpdate();
	void Render();
	void PopRender();
	void Release();

	bool IsShow() { return m_bDraw; }
	CRectangle GetRec() { return CRectangle(m_Pos.x - 10, m_Pos.y - 10, m_Pos.x + 10, m_Pos.y + 10); }
};

