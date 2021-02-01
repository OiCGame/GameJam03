#include "Character.h"


void CCharacter::Move(void) {
    if (CInputManager::GetInstance().GetHorizontal() < -0.25) {
        _position.x--;
    } // if
    else if (CInputManager::GetInstance().GetHorizontal() > 0.25) {
        _position.x++;
    } // else if
}

bool CCharacter::Shot(std::array<CBullet, 256>& bullet_container) {
    auto bullet_size = bullet_container.at(0).GetTextureSize();    
    auto offset = Mof::CVector2(2.0f, 10.0f);
    auto size = Mof::CVector2(_texture->GetWidth(), _texture->GetHeight());
    auto pos = Mof::CVector2(_position.x + size.x * 0.5f - bullet_size.x * 0.5f,
                             _position.y);

    for (auto& bullet : bullet_container) {
        if (bullet.IsShow()) {
            continue;
        } // if
        bullet.Shot(pos + offset, CBullet::TeamType::Player);
        return true;
    } // for
    return false;
}

CCharacter::CCharacter() :
    _position(),
    _texture(nullptr),
    _bullet_texture(nullptr) {
}

CCharacter::~CCharacter() {
}

void CCharacter::SetTexture(Mof::CTexture* ptr) {
    this->_texture = ptr;
}

void CCharacter::SetBulletTexture(Mof::CTexture* ptr) {
    _bullet_texture = ptr;
}

bool CCharacter::Initialize(Mof::CVector2 init_pos) {
    _position = init_pos;
    return true;
}

bool CCharacter::Update(std::array<CBullet, 256>& bullet_container) {
	if (!this->_show) {
		return false;
	} // if

	this->Move();
	if (::g_pInput->IsKeyPush(MOFKEY_SPACE)) {
		this->Shot(bullet_container);
	} // if

	return true;
}

bool CCharacter::Render(void) {
    _texture->Render(_position.x, _position.y);
    return true;
}

bool CCharacter::Release(void) {
    return true;
}

void CCharacter::Damege(void) {
	_hp--;
	if (_hp <= 0) {
		_show = false;
	} // if
}