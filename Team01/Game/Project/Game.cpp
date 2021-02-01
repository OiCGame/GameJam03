#include "Game.h"

#include "Helper.h"


void CGame::Collision(void) {
    if (_player.IsShow()) {
        auto player_rect = _player.GetCollisionRectangle();
        for (auto& enemy : _enemies) {
            if (player_rect.CollisionRect(enemy.GetCollisionRectangle())) {
                _player.Damege();
                enemy.Damege();

                auto pos = _player.GetPosition();
                auto effect = std::make_shared<CEffect>();
                effect->Load(&_effect_texture, _effect_motion_data);
                effect->Start(pos);
                _effect_container.push_back(effect);
                break;
            } // if
        } // for
    } // if

    for (auto& enemy : _enemies) {
        for (auto& bullet : _bullet_container) {
            if (!enemy.IsShow() || !bullet.IsShow()) {
                continue;
            } // if
            if (enemy.GetCollisionRectangle().CollisionRect(bullet.GetCollisionRectangle())) {
                enemy.Damege();
                bullet.Hide();

                auto pos = enemy.GetPosition();
                auto effect = std::make_shared<CEffect>();
                effect->Load(&_effect_texture, _effect_motion_data);
                effect->Start(pos);
                _effect_container.push_back(effect);
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
    _bullet_container(),
    _effect_container() {
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
    _effect_texture.Load("effect/effect00.png");
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
    // 非表示のものは削除
    auto it = std::remove_if(
        _effect_container.begin(),
        _effect_container.end(),
        [](std::shared_ptr<CEffect> effect) {
        return effect->IsShow() == false;
    });
    _effect_container.erase(it, _effect_container.end());


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


    for (auto& effect : _effect_container) {
        if (effect->IsShow()) {
            effect->Update();
        } // if
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

    for (auto& effect : _effect_container) {
        if (effect->IsShow()) {
            effect->Render();
        } // if
    } // for


    ::CGraphicsUtilities::RenderString(0.0f, 0.0f, "effect container size = %d", _effect_container.size());

    return true;
}

bool CGame::Release(void) {
    _player_texture.Release();
    _enemy_texture.Release();
    _bullet_texture.Release();
    _effect_texture.Release();
    return true;

}