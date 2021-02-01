#include "Character.h"

void Character::Move(void) {
    if (::g_pInput->IsKeyHold(MOFKEY_LEFT)) {
        _position.x--;
    } // if
    else if (::g_pInput->IsKeyHold(MOFKEY_RIGHT)) {
        _position.x++;
    } // else if
}

Character::Character() :
    _position(),
    _texture(nullptr) {
}

Character::~Character() {
}

void Character::SetTexture(Mof::CTexture* ptr) {
    this->_texture = ptr;
}

bool Character::Initialize(Mof::CVector2 init_pos) {
    _position = init_pos;
    return true;
}

bool Character::Update(void) {
    this->Move();
    return true;
}

bool Character::Render(void) {
    _texture->Render(_position.x, _position.y);
    return true;
}

bool Character::Release(void) {
    return true;
}
