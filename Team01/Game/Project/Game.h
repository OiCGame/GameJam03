#pragma once


#include <memory>
#include <array>
#include <vector>
#include <unordered_map>
#include <string>

#include <Mof.h>

#include "UICanvas.h"
#include "Character.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Effect.h"
#include "Shop.h"


class CGame {
private:
	//! UI
	UICanvas m_UICanvas;
	//! ゲーム空間のアイテム
	std::vector<std::shared_ptr<CItem>> m_Items;
	//! アイテムを持ってきてくれる
	CShopShip m_ShopShip;
	//! ショップ
	CShop m_Shop;
	//! ゲーム内経過時間
	float m_ElapsedTime;
	//! テクスチャ一元管理する配列
	std::unordered_map<std::string, Mof::CTexture> m_Textures;
	std::string m_PlayerTexturePath; // 各パス
	std::string m_BulletTexturePath; // 各パス
	std::string m_EffectTexturePath; // 各パス
	std::string m_StageTexturePath;	 // 各パス
	//! 爆発エフェクトモーションデータ
	SpriteMotionData m_EffectMotionData;
	//! エネミー生成時に渡す初期化パラメータ
	std::vector<CEnemy::InitParam> m_EnemyDatas;
	//! 操作するプレイヤー
	CCharacter m_Player;
	//! 敵
	std::vector<CEnemy> m_Enemies;
	//! ゲーム空間を動く撃たれた弾
	std::array<CBullet, 256>m_PlayerBullets;
	//! 発生した爆発エフェクト
	std::vector<std::shared_ptr<CEffect>> m_Effects;
	std::vector<std::shared_ptr<CEffect>> m_CollisionedEffects;
	//! ボス出現中フラグ
	bool m_bBossExist;
	bool m_bBossDead;

	
	int m_EnemyCount;
	//! ステージのフェイズデータのパス配列
	std::vector<std::string> m_StagePaths;
	//! 現在の何番目のフェイズかのインデックス
	uint32_t m_StagePhaseIndex;
	
	
	int m_bPhaseNo;

	int m_EffectStartFrame;

	//! プレイヤー死亡 ゲームオーバー判定用
	bool m_bPlayerDead;
	/// <summary>
	/// エネミー出現
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SpawnEnemy(void);
	/// <summary>
	/// 爆発エフェクト発生
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void EffectStart(Mof::CVector2 position);
	/// <summary>
	/// 衝突
	/// </summary>
	/// <param name=""></param>
    /// <returns></returns>
	void Collision(void);
	void CollisionPlayerEnemies(void);
	void CollisionItem(void);
public:
	CGame();
	~CGame();
	/// <summary>
	/// ゲームオーバー判定用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsPlayerDead(void) const;
	/// <summary>
	/// ゲームクリア判定用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsAllPhaseEnd(void) const;
	bool BossDead(void) const;
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(void);
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
	/// <summary>
	/// 解放
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Release(void);

	int GetPhaseNo() { return m_bPhaseNo; }
};