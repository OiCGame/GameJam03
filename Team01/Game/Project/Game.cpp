#include "Game.h"

#include "Helper.h"


void CGame::SpawnEnemy(void) {
	for (auto& spawn_data : m_EnemyDatas) {
		if (m_ElapsedTime <= spawn_data.spawn_time) {
			break;
		} // if
		auto enemy = CEnemy();
		enemy.Initialize(spawn_data);
		enemy.SetTexture(&m_Textures.at(spawn_data.texture_path));
		enemy.SetTarget(m_Player.GetPosition());

		m_Enemies.push_back(std::move(enemy));
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
	auto& effect_tex = m_Textures.at(m_EffectTexturePath);
	auto pos = position;
	auto effect = std::make_shared<CEffect>();
	effect->Generate(&effect_tex, m_EffectMotionData);
	effect->Start(pos);
	m_Effects.push_back(effect);

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
	for (auto& enemy : m_Enemies) {
		if (!enemy.IsShow()) { continue; }
		for (auto effect : m_Effects) {
			auto& collitioned_effects = enemy.GetCollisionedEffects();
			if (std::find_if(collitioned_effects.begin(), collitioned_effects.end(), [&](std::weak_ptr<CEffect> weak) {
				if (auto e = weak.lock()) {
					return e == effect;
				} // if
				return false;
			}) != collitioned_effects.end()) {
				continue;
			} // if
			auto enemy_rect = enemy.GetCollisionRectangle();
			if (enemy_rect.CollisionRect(effect->GetCollisionRectangle())) {
				enemy.AddCollisionedEffect(effect);

				int damage_value = effect->GetDamageValue(m_bBossExist);
				if (enemy.Damage(damage_value)) {
					effect->Chain();
					effect_param.push_back(EffectParam(enemy.GetPosition(), effect->GetChainCount()));
				} // if
			} // if
		} // for
	} // for
	auto& effect_tex = m_Textures.at(m_EffectTexturePath);
	for (auto& param : effect_param) {
		auto pos = param.position;
		auto effect = std::make_shared<CEffect>();
		effect->Generate(&effect_tex, m_EffectMotionData, param.chain);
		effect->Start(pos);
		m_Effects.push_back(effect);

		int score = std::pow(2, param.chain) * 100;
		m_UICanvas.AddScore(score);
		m_UICanvas.AddText(std::to_string(score), pos, 60);
	} // for

	for (auto& enemy : m_Enemies) {
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
				int damage_value = 1;

				if (enemy.Damage(damage_value)) {
					this->EffectStart(enemy.GetPosition());
				} // if
			} // if
		} // for
		if (m_Player.IsShow()) {
			for (int i = 0; i < enemy.CollisionBullet(m_Player.GetCollisionRectangle()); i++) {
				break;

				if (m_Player.Damage()) {
					auto name = std::string("image");
					name += std::to_string(m_Player.GetRevivalCount());
					m_UICanvas.RemoveImage(name);
				} // if
			} // for
		}
	} // for
}

void CGame::CollisionPlayerEnemies(void) {
	if (m_Player.IsShow()) {
		auto player_rect = m_Player.GetCollisionRectangle();
		for (auto& enemy : m_Enemies) {
			if (player_rect.CollisionRect(enemy.GetCollisionRectangle())) {
				m_Player.Damage();
				this->EffectStart(m_Player.GetPosition());
				break;
			} // if
		} // for
	} // if
}

CGame::CGame() :
	m_UICanvas(),
	m_ElapsedTime(0.0f),
	m_Textures(),
	m_PlayerTexturePath("player/Plane1Up.png"),
	m_BulletTexturePath("bullet/01Bullets.png"),
	m_EffectTexturePath("effect/effect00.png"),
	m_StageTexturePath("pipo-bg001.jpg"),
	m_EffectMotionData(),

	m_EnemyDatas(),
	m_Player(),
	m_Enemies(),
	m_PlayerBullets(),
	m_Effects(),
	m_bBossExist(false),
	m_StagePaths({ "stage/test_stage.json", "stage/test_stage1.json" }),
	m_StagePhaseIndex(0) {
}

CGame::~CGame() {
}

bool CGame::IsPlayerDead(void) const {
	return !m_Player.IsShow();
}

bool CGame::IsAllPhaseEnd(void) const {
	if (!m_EnemyDatas.empty()) {
		return false;
	} // if

	bool exist = false;
	for (auto& enemy : m_Enemies) {
		if (enemy.IsShow()) {
			return false;
		} // if
	} // for
	return m_StagePaths.size() - 1 == m_StagePhaseIndex;
}

bool CGame::Initialize(void) {
	m_UICanvas.Initialize();
	m_ElapsedTime = 0.0f;
	m_bBossExist = false;

	rapidjson::Document document;
	if (!ParseJsonDocument(m_StagePaths.at(m_StagePhaseIndex).c_str(), document)) {
		return false;
	} // if
	m_StageTexturePath = document["texture"]["uri"].GetString();


	m_Textures = {
		{m_PlayerTexturePath, Mof::CTexture()},
		{"enemy/Enemy01.png", Mof::CTexture()},
		{"enemy/Enemy02.png", Mof::CTexture()},
		{"enemy/Enemy03.png", Mof::CTexture()},
		{"enemy/Enemy04.png", Mof::CTexture()},
		{"enemy/Enemy05.png", Mof::CTexture()},
		{"enemy/Enemy06.png", Mof::CTexture()},
		{m_BulletTexturePath, Mof::CTexture()},
		{m_StageTexturePath, Mof::CTexture()},
		{m_EffectTexturePath, Mof::CTexture()}
	};
	for (auto & pair : m_Textures) {
		pair.second.Load(pair.first.c_str());
	} // for

	m_EffectMotionData.Load("motion/explode.json");

	m_Player.Initialize(Mof::CVector2(512.0f, 600.0f));
	m_Player.SetTexture(&m_Textures.at(m_PlayerTexturePath));

	const auto& info = document["enemies"];
	for (uint32_t i = 0; i < info.Size(); i++) {
		assert(info[i].HasMember("initPosX"));
		assert(info[i]["initPosX"].IsInt());
		assert(info[i].HasMember("initPosY"));
		assert(info[i]["initPosY"].IsInt());

		int x = info[i]["initPosX"].GetInt();
		int y = info[i]["initPosY"].GetInt();
		auto& move_info = info[i]["movement"];
		int move_type = move_info["default"].GetInt();
		int move_type_on_pinch = move_info["pinch"].GetInt();
		float pinch_hp_ratio = move_info["pinch_hp_ratio"].GetFloat();
		float spawn_time = info[i]["spawn_time"].GetFloat();
		int bullet_column = info[i]["bullet_column"].GetInt();
		int bullet_amount = info[i]["bullet_amount"].GetInt();
		int amount_set = info[i]["amount_set"].GetInt();
		int hp = info[i]["hp"].GetInt();
		std::string tex_path = info[i]["texture_uri"].GetString();

		m_EnemyDatas.push_back(CEnemy::InitParam(
			Mof::CVector2(x, y), move_type, move_type_on_pinch, pinch_hp_ratio, spawn_time, bullet_column, bullet_amount, amount_set, hp, tex_path));
	} // for



	auto& bullet_tex = m_Textures.at(m_BulletTexturePath);
	for (auto& bullet : m_PlayerBullets) {
		bullet.SetTexture(&bullet_tex);
	} // for


	auto& player_tex = m_Textures.at(m_PlayerTexturePath);
	auto pos = Mof::CVector2(0.0f, ::g_pGraphics->GetTargetHeight() - player_tex.GetHeight());
	float width = player_tex.GetWidth();
	for (int i = 0; i < m_Player.GetRevivalCount(); i++) {
		auto name = std::string("image");
		name += std::to_string(i);
		m_UICanvas.AddImage(name.c_str(), &player_tex, pos);
		pos.x += width;
	} // for
	return true;
}

bool CGame::Update(void) {
	if (::g_pInput->IsKeyPush(MOFKEY_RETURN)) {
		m_StagePhaseIndex++;
		if (m_StagePaths.size() - 1 < m_StagePhaseIndex) {
			m_StagePhaseIndex = m_StagePaths.size() - 1;
		} // if

		this->Release();
		this->Initialize();
	} // if

	m_ElapsedTime += 0.0167f;
	this->SpawnEnemy();

	// îÒï\é¶ÇÃÇ‡ÇÃÇÕçÌèú
	{
		auto it = std::remove_if(
			m_Effects.begin(),
			m_Effects.end(),
			[](std::shared_ptr<CEffect> effect) {
			return effect->IsShow() == false;
		});
		m_Effects.erase(it, m_Effects.end());
	}
	{
		auto it = std::remove_if(
			m_Enemies.begin(),
			m_Enemies.end(),
			[](CEnemy& enemy) {
			if (!enemy.IsShow() && enemy.GetBulletShow() == 0) {
				enemy.Release();
				return true;
			} // if
			return false;
		});
		m_Enemies.erase(it, m_Enemies.end());
	}

	if (m_Player.IsShow()) {
		m_Player.Update(m_PlayerBullets);
	} // if

	for (auto& enemy : m_Enemies) {
		enemy.Update();
	} // for

	for (auto& bullet : m_PlayerBullets) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Update();
	} // for
	for (auto& effect : m_Effects) {
		if (effect->IsShow()) {
			effect->Update();
		} // if
	} // for

	this->Collision();


	m_UICanvas.Update();
	return true;
}


bool CGame::Render(void) {
	auto& stage_tex = m_Textures.at(m_StageTexturePath);
	stage_tex.Render(0.0f, 0.0f);

	if (m_Player.IsShow()) {
		m_Player.Render();
	} // if

	for (auto& enemy : m_Enemies) {
		enemy.Render();
	} // for

	for (auto& bullet : m_PlayerBullets) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Render();
	} // for

	for (auto& effect : m_Effects) {
		if (effect->IsShow()) {
			effect->Render();
		} // if
	} // for



	m_UICanvas.Render();

	::CGraphicsUtilities::RenderString(700.0f, 0.0f, "elapsed time = %f", m_ElapsedTime);
	::CGraphicsUtilities::RenderString(700.0f, 30.0f, "stage phase = %d", m_StagePhaseIndex);

	if (!m_Player.IsShow()) {
		::CGraphicsUtilities::RenderString(500.0f, 500.0f, "GameOver");
	} // if
	return true;
}

bool CGame::Release(void) {
	m_UICanvas.Release();
	m_EnemyDatas.clear();

	m_Player.Release();

	for (auto &e : m_Enemies) {
		e.Release();
	} // for	
	m_Enemies.clear();

	m_Effects.clear();
	for (auto& pair : m_Textures) {
		pair.second.Release();
	} // for
	return true;
}