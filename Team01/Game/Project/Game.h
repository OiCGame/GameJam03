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
	UICanvas m_UICanvas;
	CShop m_Shop;
	float m_ElapsedTime;
	
	std::unordered_map<std::string, Mof::CTexture> m_Textures;
	std::string m_PlayerTexturePath;
	std::string m_BulletTexturePath;
	std::string m_EffectTexturePath;
	std::string m_StageTexturePath;
	SpriteMotionData m_EffectMotionData;


	std::vector<CEnemy::InitParam> m_EnemyDatas;
	CCharacter m_Player;
	std::vector<CEnemy> m_Enemies;
	std::array<CBullet, 256>m_PlayerBullets;
	std::vector<std::shared_ptr<CEffect>> m_Effects;
	//! 出現中
	bool m_bBossExist;
	
	std::vector<std::string> m_StagePaths;
	uint32_t m_StagePhaseIndex;
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
};