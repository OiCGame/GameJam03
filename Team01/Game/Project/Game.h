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
	//! �o����
	bool m_bBossExist;
	
	std::vector<std::string> m_StagePaths;
	uint32_t m_StagePhaseIndex;
	/// <summary>
	/// �G�l�~�[�o��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SpawnEnemy(void);
	/// <summary>
	/// �����G�t�F�N�g����
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void EffectStart(Mof::CVector2 position);
	/// <summary>
	/// �Փ�
	/// </summary>
	/// <param name=""></param>
    /// <returns></returns>
	void Collision(void);
	void CollisionPlayerEnemies(void);
public:
	CGame();
	~CGame();
	/// <summary>
	/// �Q�[���I�[�o�[����p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsPlayerDead(void) const;
	/// <summary>
	/// �Q�[���N���A����p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsAllPhaseEnd(void) const;
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(void);
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(void);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
	/// <summary>
	/// ���
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Release(void);
};