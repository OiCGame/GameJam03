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
		int reflect_count;
		float central_dir;
		float dir_range;
		float dir_rotation;
		int bullet_gap;
		int bullet_setgap;
		int hp_max;
		std::string texture_path;
		InitParam(Mof::CVector2 pos, int move, int pinch_move, float ratio, float time, int column, int amount, int set, int reflect, float cdir, float dirrange, float dirrotat, int bgap, int bsetgap, int hp, std::string tex_path) :
			position(pos), move_type(move), move_type_on_pinch(pinch_move), pinch_hp_ratio(ratio), spawn_time(time), bullet_column(column), bullet_amount(amount), amount_set(set), reflect_count(reflect), central_dir(cdir), dir_range(dirrange), dir_rotation(dirrotat), bullet_gap(bgap), bullet_setgap(bsetgap), hp_max(hp), texture_path(tex_path) {
		}
	};
private:
	int m_HP;
	int m_MaxHP;
	Vector2 m_InitPos;
	Vector2 m_Pos;
	Vector2 m_Move;
	float m_Dir;
	float m_WaveDir;
	float m_Speed;
	CTexture* m_pTexture;
	bool m_bDrow;
	bool m_bEnter;
	int m_EnterCount;
	int m_FastBulletNo;
	//! 移動タイプ
	int m_MoveType;
	int m_MoveTypeOnPinch;
	float m_PinchHPRatio;
	//! 突撃位置
	Mof::CVector2 m_Target;
	//! 当たったEffect
	std::vector<std::weak_ptr<CEffect>> m_CollisionedEffects;
	//! 波々移動をするし始める位置
	float m_StartPositionY;
	//! right or left
	float m_WaveDirection;


	float m_MoveWaveAmplitudeCount;
	float m_MoveWaveAmplitudeCountMax;
	float m_MoveWaveAmplitude;

	/// <summary>
	/// 移動
	/// </summary>
	/// <param name=""></param>
	void Chase(Mof::CVector2 pos);
	/// <summary>
	/// 移動
	/// </summary>
	/// <param name=""></param>
	void MainMove(int type);
	void Move(int type);
	void MoveOutOfWindow(void);
	void MoveAssault(void);
	void MoveWave(void);

	CEnemyBullet* m_Bullet;
	int m_BulletColumn;
	int m_BulletAmount;
	int m_BulletSetAmount;
	int m_BulletCount;

	int m_BulletNo;
	int m_BulletSetNo;

	int m_BulletGap;
	int m_BulletRemGap;
	int m_BulletSetGap;
	int m_BulletSetRemGap;

	int m_BulletShowCount;

	int m_EffectHitFrame;
public:
	CEnemy();
	~CEnemy();

	Mof::CVector2 GetPosition(void) const;
	std::vector<std::weak_ptr<CEffect>> & GetCollisionedEffects(void);
	void AddCollisionedEffect(const std::shared_ptr<CEffect>& ptr);

	bool IsShow(void) const { return m_bDrow; }

	void Initialize(const InitParam& param);
	void Initialize(Vector2 pos, int move_type, int pinch_move, float ratio, int column, int amount, int set, int reflect, float cdir, float dirrange, float dirrotat, int bgap, int bsetgap, int hp);
	void SetTexture(Mof::CTexture* ptr);
	void SetTarget(Mof::CVector2 pos);
	void Update(bool end);
	int CollisionBullet(CRectangle prec);
	void Render(bool end);
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
	int GetLastHitFrame() { return m_EffectHitFrame; }
};