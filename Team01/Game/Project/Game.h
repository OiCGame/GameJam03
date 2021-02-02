#pragma once


#include <memory>
#include <array>
#include <vector>

#include <Mof.h>

#include "Character.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Effect.h"


class CGame {
private:
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
	/// ï`âÊ
	/// </summary>
	/// <param name=""></param>
    /// <returns></returns>
	void Collision(void);
public:
	CGame();
	~CGame();
	/// <summary>
	/// ï`âÊ
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(void);
	/// <summary>
	/// çXêV
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(void);
	/// <summary>
	/// ï`âÊ
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
	/// <summary>
	/// âï˙
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Release(void);
};