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


class CGame {
private:
	UICanvas m_UICanvas;
	float m_ElapsedTime;
	std::vector<CEnemy::InitParam> m_EnemyDatas;
	std::unordered_map<std::string, Mof::CTexture> m_Textures;

	std::string m_PlayerTexturePath;
	std::string m_EnemyTexturePath1;
	std::string m_EnemyTexturePath2;
	std::string m_EnemyTexturePath3;
	std::string m_BulletTexturePath;
	std::string m_EffectTexturePath;
	std::string m_StageTexturePath;

	SpriteMotionData _effect_motion_data;

	CCharacter _player;
	std::vector<CEnemy> _enemies;
	std::array<CBullet, 256>m_PlayerBullets;
	std::vector<std::shared_ptr<CEffect>>_effect_container;

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