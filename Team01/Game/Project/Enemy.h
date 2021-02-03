#pragma once


#include "Character.h"

#include <random>

#include "EnemyBullet.h"
#include "Effect.h"

static int GenerateRandom(const int min, const int max) {
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<> random(min, max);
	return random(engine);
}


class CEnemy {
    using super = CCharacter;
public:
    struct InitParam {
        Mof::CVector2 position;
        int move_type;
        int move_type_on_pinch;
        float pinch_hp_ratio;
        float spawn_time;
        int bullet_column;
        int bullet_amount;
        int amount_set;
        int hp_max;
		std::string texture_path;
        InitParam(Mof::CVector2 pos, int move, int pinch_move, float ratio, float time, int column, int amount, int set, int hp, std::string tex_path) :
            position(pos), move_type(move), move_type_on_pinch(pinch_move), pinch_hp_ratio(ratio), spawn_time(time), bullet_column(column), bullet_amount(amount), amount_set(set), hp_max(hp), texture_path(tex_path){
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
    //! 移動タイプ
    int m_MoveType;
    int m_MoveTypeOnPinch;
    float m_PinchHPRatio;
	//! 突撃位置
	Mof::CVector2 m_Target;
	//! 当たったEffect
	std::vector<std::weak_ptr<CEffect>> m_CollisionedEffects;
	/// <summary>
	/// 移動
	/// </summary>
	/// <param name=""></param>
	void Chase(Mof::CVector2 pos);
    /// <summary>
    /// 移動
    /// </summary>
    /// <param name=""></param>
    virtual void Move(void);
    void Move(int type);
    void MoveOutOfWindow(void);
	void MoveAssault(void);

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

	int m_BulletShowCount;


public:
    CEnemy();
    ~CEnemy();

    Mof::CVector2 GetPosition(void) const;
	std::vector<std::weak_ptr<CEffect>> & GetCollisionedEffects(void);
	void AddCollisionedEffect(const std::shared_ptr<CEffect>& ptr);

    bool IsShow() { return m_bDrow; }

    void Initialize(const InitParam& param);
    void Initialize(Vector2 pos, int move_type, int pinch_move, float ratio, int column, int amount, int set, int hp);
    void SetTexture(Mof::CTexture* ptr);
    void SetTarget(Mof::CVector2 pos);
    void Update();
    int CollisionBullet(CRectangle prec);
    void Render();
    void Release();

    /// <summary>
    /// 死亡したらtrueを返す
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Damage(int damage_value);
    int GetFastBulletNo() { return m_FastBulletNo; }
    void SetFastBulletNo(int no) { m_FastBulletNo = no; }
    Mof::CRectangle GetCollisionRectangle(void) const;
	int GetBulletShow() { return m_BulletShowCount; }
};