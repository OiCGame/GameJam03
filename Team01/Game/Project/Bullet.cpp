#include "Bullet.h"


Bullet::Bullet() :
    _position(),
    _move(0.0f, -5.0f),
    _texture(),
    _show(false),
    _team_type() {
}

Bullet::~Bullet() {
}

void Bullet::SetTexture(Mof::CTexture* ptr) {
    this->_texture = ptr;
}

Mof::CVector2 Bullet::GetTextureSize(void) const {
    auto tex = _texture;
    if (tex) {
        return Mof::CVector2(tex->GetWidth(), tex->GetHeight());
    } // if
    return Mof::CVector2();
}

bool Bullet::IsShow(void) const {
    return this->_show;
}

bool Bullet::Update(void) {
    if (!this->_show) {
        return false;
    } // if

    _position += _move;
    return true;
}

bool Bullet::Render(void) {
    if (!this->_show) {
        return false;
    } // if

    auto tex = _texture;
    if (tex) {
        tex->Render(_position.x, _position.y);
    } // if
    return true;
}

bool Bullet::Shot(Mof::CVector2 init_pos, Bullet::TeamType type) {
    _show = true;
    _position = init_pos;
    _team_type = type;
    return true;
}