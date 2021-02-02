#include "Bullet.h"


CBullet::CBullet() :
    _position(),
    _move(0.0f, -5.0f),
    _texture(),
    _show(false),
    _team_type() {
}

CBullet::~CBullet() {
}

void CBullet::SetTexture(Mof::CTexture* ptr) {
    this->_texture = ptr;
}

void CBullet::Hide(void) {
	this->_show = false;
}

Mof::CVector2 CBullet::GetTextureSize(void) const {
    auto tex = _texture;
    if (tex) {
        return Mof::CVector2(tex->GetWidth(), tex->GetHeight());
    } // if
    return Mof::CVector2();
}

Mof::CRectangle CBullet::GetCollisionRectangle(void) const {
	auto rect = Mof::CRectangle(0.0f, 0.0f,
		_texture->GetWidth(), _texture->GetHeight());
	rect.Translation(_position);
	return rect;
}

bool CBullet::IsShow(void) const {
	return this->_show;
}

bool CBullet::Update(void) {
	_position += _move;
	return true;
}

bool CBullet::Render(void) {
#ifdef _DEBUG
	::CGraphicsUtilities::RenderRect(
		this->GetCollisionRectangle(),
		MOF_ARGB(100, 100, 100, 100)
	);
#endif // _DEBUG

	auto tex = _texture;
	if (tex) {
		tex->Render(_position.x, _position.y);
	} // if
	return true;
}

bool CBullet::Shot(Mof::CVector2 init_pos, CBullet::TeamType type) {
	_show = true;
	_position = init_pos;
	_team_type = type;
	return true;
}