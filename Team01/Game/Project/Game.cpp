#include "Game.h"

#include "rapidjson/document.h"

#include <fstream>
#include <sstream>


static bool ParseJsonDocument(const char* path, rapidjson::Document& document) {
	std::ifstream file(path);
	// ファイルを開けないならfalseを返す
	if (!file.is_open()) {
		return false;
	} // if
	// 読み込み
	std::stringstream stream;
	stream << file.rdbuf();
	std::string temp = stream.str();
	rapidjson::StringStream str(temp.c_str());
	document.ParseStream(str);
	return true;
}

void CGame::Collision(void) {
	auto player_rect = _player.GetCollisionRectangle();
	if (_player.IsShow()) {

	} // if

	for (auto& enemy : _enemies) {
		for (auto& bullet : _bullet_container) {
			if (!enemy.IsShow() || !bullet.IsShow()) {
				continue;
			} //
			if (enemy.GetCollisionRectangle().CollisionRect(bullet.GetCollisionRectangle())) {
				enemy.Damege();
				bullet.Hide();
			} // if
		} // for
	} // for
}

CGame::CGame() :
	_player_texture(),
	_enemy_texture(),
	_bullet_texture(),
	_player(),
	_enemies(),
	_bullet_container() {
}

CGame::~CGame() {
}

bool CGame::Initialize(void) {
	rapidjson::Document document;
	if (!ParseJsonDocument("stage/enemies.json", document)) {
		return false;
	} // if

	_player_texture.Load("player/Plane1Up.png");
	_enemy_texture.Load("enemy/Enemy01.png");
	_bullet_texture.Load("bullet/01Bullets.png");
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

		auto enemy = CEnemy();
		enemy.Initialize(Mof::CVector2(x, y));
		enemy.SetTexture(&_enemy_texture);
		_enemies.push_back(std::move(enemy));
	} // for

	for (auto& bullet : _bullet_container) {
		bullet.SetTexture(&_bullet_texture);
	} // for
	return true;
}

bool CGame::Update(void) {
	if (_player.IsShow()) {
		_player.Update(_bullet_container);
	} // if
	for (auto& enemy : _enemies) {
		if (enemy.IsShow()) {
			enemy.Update(_bullet_container);
		} // if
	} // for

	for (auto& bullet : _bullet_container) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Update();
	} // for


	this->Collision();
	return true;
}


bool CGame::Render(void) {
	if (_player.IsShow()) {
		_player.Render();
	} // if

	for (auto& enemy : _enemies) {
		if (enemy.IsShow()) {
			enemy.Render();
		} // if
	} // for

	for (auto& bullet : _bullet_container) {
		if (!bullet.IsShow()) {
			continue;
		} // if
		bullet.Render();
	} // for
	return true;
}

bool CGame::Release(void) {
	_player_texture.Release();
	_enemy_texture.Release();
	_bullet_texture.Release();
	return true;
}