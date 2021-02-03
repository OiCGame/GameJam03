#pragma once


#include "Character.h"

#include "EnemyBullet.h"


class CEnemy {
	using super = CCharacter;
public:
	struct InitParam {
		Mof::CVector2 position;
		int move_type;
		float spawn_time;
		int bullet_column;
		int bullet_amount;
		int amount_set;
		InitParam(Mof::CVector2 pos, int move, float time, int column, int amount, int set) :
			position(pos), move_type(move), spawn_time(time), bullet_column(column), bullet_amount(amount),amount_set(set){
		}
	};
private:
	int m_HP;
	int m_MaxHP;
	Vector2 m_Pos;
	Vector2 m_Move;
	float m_Dir;
	float m_Speed;
	CTexture* m_pTexture;
	bool m_bDrow;
	int m_FastBulletNo;
	//! ˆÚ“®ƒ^ƒCƒv
	int m_MoveType;

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

	void Initialize(const InitParam& param);
	void Initialize(Vector2 pos, int move_type, int column, int amount, int set);
	void SetTexture(Mof::CTexture* ptr);
	void Update();
	int CollitionBullet(CRectangle prec);
	void Render();
	void Release();

	/// <summary>
	/// Ž€–S‚µ‚½‚çtrue‚ð•Ô‚·
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Damage();
	int GetFastBulletNo() { return m_FastBulletNo; }
	void SetFastBulletNo(int no) { m_FastBulletNo = no; }
	Mof::CRectangle GetCollisionRectangle(void) const;
};