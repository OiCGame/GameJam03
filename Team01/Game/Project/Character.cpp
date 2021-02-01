#include "Character.h"


void Character::Move(void) {
    if (::g_pInput->IsKeyHold(MOFKEY_LEFT)) {
        _position.x--;
    } // if
    else if (::g_pInput->IsKeyHold(MOFKEY_RIGHT)) {
        _position.x++;
    } // else if
}

bool Character::Shot(std::array<Bullet, 256>& bullet_container) {
    auto bullet_size = bullet_container.at(0).GetTextureSize();    
    auto offset = Mof::CVector2(2.0f, 10.0f);
    auto size = Mof::CVector2(_texture->GetWidth(), _texture->GetHeight());
    auto pos = Mof::CVector2(_position.x + size.x * 0.5f - bullet_size.x * 0.5f,
                             _position.y);

    for (auto& bullet : bullet_container) {
        if (bullet.IsShow()) {
            continue;
        } // if
        bullet.Shot(pos + offset, Bullet::TeamType::Player);
        return true;
    } // for
    return false;
}

Character::Character() :
    _position(),
    _texture(nullptr),
    _bullet_texture(nullptr) {
}

Character::~Character() {
}

void Character::SetTexture(Mof::CTexture* ptr) {
    this->_texture = ptr;
}

void Character::SetBulletTexture(Mof::CTexture* ptr) {
    _bullet_texture = ptr;
}

bool Character::Initialize(Mof::CVector2 init_pos) {
    _position = init_pos;
    return true;
}

bool Character::Update(std::array<Bullet, 256>& bullet_container) {
    this->Move();
    if (::g_pInput->IsKeyPush(MOFKEY_SPACE)) {
        this->Shot(bullet_container);
    } // if

    return true;
}

bool Character::Render(void) {
    _texture->Render(_position.x, _position.y);
    return true;
}

bool Character::Release(void) {
    return true;
}
