#pragma once


#include "Character.h"

#include "EnemyMove.h"

#include "EnemyBullet.h"

#include "EnemyMoveEscape.h"

class CEnemy{
	using super = CCharacter;
private:
	int m_HP;
	Vector2 m_Pos;
	Vector2 m_Move;
	float m_Dir;
	float m_Speed;
	CTexture* m_Texture;
	bool m_bDrow;

	//! ˆÚ“®‹@”\
	EnemyMove* _move_controller;
	/// <summary>
	/// ˆÚ“®
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void);


	CEnemyBullet* m_Bullet;
	int m_BulletColumn;
	int m_BulletAmount;
	int m_BulletSetAmount;
	int m_BulletCount;

	int m_BulletNo;
	int m_BulletSetNo;

	int m_BulletGap = 10;
	int m_BulletRemGap;
	int m_BulletSetGap = 60;
	int m_BulletSetRemGap;

public:

	CEnemy();
	~CEnemy();

	bool IsShow() { return m_bDrow; }

	void Initialize(Vector2 pos);
	void SetTexture(Mof::CTexture* ptr);
	void Update();
	void Render();
	void Release();

	void Damage();
	Mof::CRectangle GetCollisionRectangle(void) const;
};