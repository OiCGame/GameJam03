#include "Game.h"

#include "Helper.h"


void CGame::SpawnEnemy(void) {
	for (auto& spawn_data : m_EnemyDatas) {
		if (m_ElapsedTime <= spawn_data.spawn_time) {
			break;
		} // if
		auto enemy = CEnemy();
		enemy.Initialize(spawn_data);
		enemy.SetTexture(&_enemy_texture);
		_enemies.push_back(std::move(enemy));
	} // for

	auto it = std::remove_if(
		m_EnemyDatas.begin(),
		m_EnemyDatas.end(),
		[&](CEnemy::InitParam data) {
		return data.spawn_time <= m_ElapsedTime;
	});
	m_EnemyDatas.erase(it, m_EnemyDatas.end());
}

void CGame::EffectStart(Mof::CVector2 position) {
	auto pos = position;
	auto effect = std::make_shared<CEffect>();
	effect->Generate(&_effect_texture, _effect_motion_data);
	effect->Start(pos);
	_effect_container.push_back(effect);

	m_UICanvas.AddScore(100);
	m_UICanvas.AddText(std::to_string(100), pos, 60);
}
void CGame::Collision(void) {
	this->CollisionPlayerEnemies();

	struct EffectParam {
		Mof::CVector2 position;
		uint32_t chain;
		EffectParam(Mof::CVector2 pos, uint32_t count) : position(pos), chain(count) {
		}
	};
	std::vector<EffectParam> effect_param;
	for (auto& enemy : _enemies) {
		for (auto effect : _effect_container) {
			auto enemy_rect = enemy.GetCollisionRectangle();
			if (enemy_rect.CollisionRect(effect->GetCollisionRectangle())) {
				if (enemy.Damage()) {
					effect->Chain();
					effect_param.push_back(EffectParam(enemy.GetPosition(), effect->GetChainCount()));
				} // if
			} // if
		} // for
	} // for
	for (auto& param : effect_param) {
		auto pos = param.position;
		auto effect = std::make_shared<CEffect>();
		effect->Generate(&_effect_texture, _effect_motion_data, param.chain);
		effect->Start(pos);
		_effect_container.push_back(effect);

		int score = std::pow(2, param.chain) * 100;
		m_UICanvas.AddScore(score);
		m_UICanvas.AddText(std::to_string(score), pos, 60);
	} // for

	for (auto& enemy : _enemies) {
		for (int i = 0; i < m_PlayerBullets.size(); i++) {
			if (!enemy.IsShow() || !m_PlayerBullets[i].IsShow()) {
				continue;
			} // if
			int no = enemy.GetFastBulletNo();
			if (no == m_PlayerBullets[i].GetNo()) {
				continue;
			}
			if (enemy.GetCollisionRectangle().CollisionRect(m_PlayerBullets[i].GetCollisionRectangle())) {
				m_PlayerBullets[i].Hide();

				enemy.SetFastBulletNo(i);
				if (enemy.Damage()) {
					this->EffectStart(enemy.GetPosition());
				} // if
			} // if
		} // for
		if (_player.IsShow()) {
			for (int i = 0; i < enemy.CollitionBullet(_player.GetCollisionRectangle()); i++) {
				if (_player.Damage()) {
					auto name = std::string("image");
					name += std::to_string(_player.GetRevivalCount());
					m_UICanvas.RemoveImage(name);
				} // if
			} // for
		}
	} // for
}

void CGame::CollisionPlayerEnemies(void) {
	if (_player.IsShow()) {
		auto player_rect = _player.GetCollisionRectangle();
		for (auto& enemy : _enemies) {
			if (player_rect.CollisionRect(enemy.GetCollisionRectangle())) {
				_player.Damage();
				this->EffectStart(_player.GetPosition());
				break;
			} // if
		} // for
	} // if
}

CGame::CGame() :
	m_UICanvas(),
	m_ElapsedTime(0.0f),
	_player_texture(),
	_enemy_texture(),
	_stage_texture(),
	_bullet_texture(),
	_player(),
	_enemies(),
	m_PlayerBullets(),
	_effect_container() {
}

CGame::~CGame() {
}

bool CGame::Initialize(void) {
	m_UICanvas.Initialize();

	rapidjson::Document document;
	if (!ParseJsonDocument("stage/enemies.json", document)) {
		return false;
	} // if

	_player_texture.Load("player/Plane1Up.png");
	_enemy_texture.Load("enemy/Enemy01.png");
	_bullet_texture.Load("bullet/01Bullets.png");
	_effect_texture.Load("effect/effect00.png");
	_stage_texture.Load("pipo-bg001.jpg");
	_effect_motion_data.Load("motion/explode.json");

	_player.Initialize(Mof::CVector2(512.0f, 600.0f));
	_player.SetTexture(&_player_texture);

	const auto& info = document["enemies"];
	for (uint32_t i = 0; i < info.Size(); i++) {
		assert(info[i].HasMember("initPosX"));
		assert(info[i]["initPosX"].IsInt());
		assert(info[i].HasMember("initPosY"));
		assert(info[i]["initPosY"].IsInt());

		int x = info[i]["initPosX"].GetInt();
		int y = info[i]["initPosY"].GetInt();
		int move_type = info[i]["movement"].GetInt();
		float spawn_time = info[i]["spawn_time"].GetFloat();
		int bullet_column = info[i]["bullet_column"].GetInt();
		int bullet_amount = info[i]["bullet_amount"].GetInt();
		int amount_set = info[i]["amount_set"].GetInt();

		m_EnemyDatas.push_back(CEnemy::InitParam(
			Mof::CVector2(x, y), move_type, spawn_time, bullet_column, bullet_amount, amount_set));

		/*
		auto enemy = CEnemy();
		enemy.Initialize(Mof::CVector2(x, y), move_type);
		enemy.SetTexture(&_enemy_texture);
		_enemies.push_back(std::move(enemy));
		*/
	} // for



	for (auto& bullet : m_PlayerBullets) {
		bullet.SetTexture(&_bullet_texture);
	} // for


	auto pos = Mof::CVector2(0.0f, ::g_pGraphics->GetTargetHeight() - _player_texture.GetHeight());
	float width = _player_texture.GetWidth();
	for (int i = 0; i < _player.GetRevivalCount(); i++) {
		auto name = std::string("image");
		name += std::to_string(i);
		m_UICanvas.AddImage(name.c_str(), &_player_texture, pos);
		pos.x += width;
	} // for
	return true;
}

bool CGame::Update(void) {
//	m_ElapsedTime += ::CUtilities::GetFrameSecond();
	m_ElapsedTime += 0.0167f;
	this->SpawnEnemy();

	// îÒï\é¶ÇÃÇ‡ÇÃÇÕçÌèú
	{
		auto it = std::remove_if(
			_effect_container.begin(),
			_effect_container.end(),
			[](std::shared_ptr<CEffect> effect) {
			return effect->IsShow() == false;
		});
		_effect_container.erase(it, _effect_container.end());
	}
	{
		auto it = std::remove_if(
			_enemies.begin(),
			_enemies.end(),
			[](CEnemy& enemy) {
			if (enemy.IsShow() == false) {
				enemy.Release();
				return true;
			} // if
			return false;
		});
		_enemies.erase(it, _enemies.end());
	}

	if (_player.IsShow()) {
		_player.Update(m_PlayerBullets);
	} // if

	for (auto& enemy : _enemies) {
		if (enemy.IsShow()) {
			enemy.Update();
		} // if
	} // for

	for (auto& bullet : m_PlayerBullets) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Update();
	} // for
	for (auto& effect : _effect_container) {
		if (effect->IsShow()) {
			effect->Update();
		} // if
	} // for

	this->Collision();


	m_UICanvas.Update();
	return true;
}


bool CGame::Render(void) {
	_stage_texture.Render(0.0f, 0.0f);

	if (_player.IsShow()) {
		_player.Render();
	} // if

	for (auto& enemy : _enemies) {
		if (enemy.IsShow()) {
			enemy.Render();
		} // if
	} // for

	for (auto& bullet : m_PlayerBullets) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Render();
	} // for

	for (auto& effect : _effect_container) {
		if (effect->IsShow()) {
			effect->Render();
		} // if
	} // for



	m_UICanvas.Render();

	::CGraphicsUtilities::RenderString(0.0f, 0.0f, "effect contaner size = %d", _effect_container.size());
	::CGraphicsUtilities::RenderString(700.0f, 0.0f, "elapsed time = %f", m_ElapsedTime);

	if (!_player.IsShow()) {
	::CGraphicsUtilities::RenderString(500.0f, 500.0f, "GameOver");
	} // if
	return true;
}

bool CGame::Release(void) {
	for (auto &e : _enemies) {
		e.Release();
	} // for

	_player_texture.Release();
	_enemy_texture.Release();
	_bullet_texture.Release();
	_effect_texture.Release();
	_stage_texture.Release();
	return true;

}