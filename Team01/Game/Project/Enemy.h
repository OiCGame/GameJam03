#pragma once


#include "Character.h"

#include "EnemyBullet.h"


class CEnemy{
	using super = CCharacter;
private:
	int m_HP;
	Vector2 m_Pos;
	Vector2 m_Move;
	float m_Dir;
	float m_Speed;
	CTexture* m_pTexture;
	bool m_bDrow;
	int m_FastBulletNo;

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

	Mof::CVector2 GetPosition(void) const;
	bool IsShow() { return m_bDrow; }

	void Initialize(Vector2 pos);
	void SetTexture(Mof::CTexture* ptr);
	void Update();
	int CollitionBullet(CRectangle prec);
	void Render();
	void Release();

	void Damage();
	int GetFastBulletNo() { return m_FastBulletNo; }
	void SetFastBulletNo(int no) { m_FastBulletNo = no; }
	Mof::CRectangle GetCollisionRectangle(void) const;
};