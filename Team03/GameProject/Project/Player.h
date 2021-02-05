#pragma once
#include	"Mof.h"
#include	"PlayerBullet.h"
#include	"Item.h"

class CPlayer
{
private:
	CTexture*		m_TexturePlayer;
	CTexture*		m_TextureArrow;
	//座標
	CVector2		m_Position;
	float			m_Radius;
	//速度
	CVector2		m_MoveVelocity;

	//プレイヤーからマウスの単位ベクトル
	CVector2		m_MouseVector;
	//弾の配列
	std::vector<CPlayerBullet> m_BulletList;
	//攻撃のクールダウンタイム
	float			m_AttackCooldown;
	//残弾数
	int				m_BulletRemain;

	//残機数
	int				m_Life;
	//無敵時間
	int				m_DamageWait;

	bool			m_bShow;

	CSoundBuffer* m_pSEShot;

	//速度更新処理
	void VelocityUpdate();
	//移動処理
	void PositionUpdate();

public:
	CPlayer();
	~CPlayer();
	
	//bool Load();
	void Initialize(const CVector2& pos);
	void Update();
	void Render();
	void RenderDebug(float top, float left);
	//void Release();

	void TakeDamage();
	
	bool IsShow() { return m_bShow; }
	bool IsInvincible() { return m_DamageWait > 0; }
	//当たり判定処理をするかしないか
	bool IsDamageableable() { return m_bShow && m_DamageWait == 0; }

	CVector2 GetPostion() { return m_Position; }
	CCircle GetCircle() { return CCircle(m_Position, m_Radius); }
	CRectangle GetRectangle() { return CRectangle(m_Position.x - m_Radius, m_Position.y - m_Radius, m_Position.x + m_Radius, m_Position.y + m_Radius); }

	std::vector<CPlayerBullet> GetBullet() { return m_BulletList; }

	int GetLife() { return m_Life; }

	int  GetBulletRemain() { return m_BulletRemain; }
	void SetBulletRemain(int num) { m_BulletRemain = num; }

	bool ItemCollisionCheck(const CItem& item);
};

