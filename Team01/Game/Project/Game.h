#pragma once


#include <memory>
#include <array>
#include <vector>

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

	Mof::CTexture _player_texture;
	Mof::CTexture _enemy_texture;
	Mof::CTexture _bullet_texture;
	Mof::CTexture _effect_texture;
	Mof::CTexture _stage_texture;
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