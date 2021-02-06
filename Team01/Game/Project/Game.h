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
	//! �Q�[����Ԃ̃A�C�e��
	std::vector<std::shared_ptr<CItem>> m_Items;
	//! �A�C�e���������Ă��Ă����
	CShopShip m_ShopShip;
	//! �V���b�v
	CShop m_Shop;
	//! �Q�[�����o�ߎ���
	float m_ElapsedTime;
	//! �e�N�X�`���ꌳ�Ǘ�����z��
	std::unordered_map<std::string, Mof::CTexture> m_Textures;
	std::string m_PlayerTexturePath; // �e�p�X
	std::string m_BulletTexturePath; // �e�p�X
	std::string m_EffectTexturePath; // �e�p�X
	std::string m_StageTexturePath;	 // �e�p�X
	//! �����G�t�F�N�g���[�V�����f�[�^
	SpriteMotionData m_EffectMotionData;
	//! �G�l�~�[�������ɓn���������p�����[�^
	std::vector<CEnemy::InitParam> m_EnemyDatas;
	//! ���삷��v���C���[
	CCharacter m_Player;
	//! �G
	std::vector<CEnemy> m_Enemies;
	//! �Q�[����Ԃ𓮂������ꂽ�e
	std::array<CBullet, 256>m_PlayerBullets;
	//! �������������G�t�F�N�g
	std::vector<std::shared_ptr<CEffect>> m_Effects;
	std::vector<std::shared_ptr<CEffect>> m_CollisionedEffects;
	//! �{�X�o�����t���O
	bool m_bBossExist;
	bool m_bBossDead;

	
	int m_EnemyCount;
	//! �X�e�[�W�̃t�F�C�Y�f�[�^�̃p�X�z��
	std::vector<std::string> m_StagePaths;
	//! ���݂̉��Ԗڂ̃t�F�C�Y���̃C���f�b�N�X
	uint32_t m_StagePhaseIndex;
	
	
	int m_bPhaseNo;

	int m_EffectStartFrame;

	//! �v���C���[���S �Q�[���I�[�o�[����p
	bool m_bPlayerDead;
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
	void CollisionItem(void);
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
	bool BossDead(void) const;
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

	int GetPhaseNo() { return m_bPhaseNo; }
};