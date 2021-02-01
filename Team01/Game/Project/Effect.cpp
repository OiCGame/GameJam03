#include "Effect.h"


CEffect::CEffect() :
    _texture(),
    _motion(),
    _show(false) {
}

CEffect::~CEffect() {
}

Mof::CRectangle CEffect::GetCollisionRectangle(void) const {
    auto rect = _motion.GetSrcRect();
    rect.Translation(_position);
    return rect;
}

bool CEffect::IsShow(void) const {
    return this->_show;
}

bool CEffect::Load(Mof::CTexture* texture, SpriteMotionData& anim) {
    _texture = texture;    
    _motion.Create(anim.anims.data(),
                   anim.anims.size());
    return true;
}

bool CEffect::Update(void) {
    if (_motion.IsEndMotion()) {
        _show = false;
    } // if

    _motion.AddTimer(::CUtilities::GetFrameSecond());
    return true;
}

bool CEffect::Render(void) {
    if (!_texture) {
        return false;
    } // if

    auto pos = _position;
    _texture->Render(pos.x, pos.y, _motion.GetSrcRect());
    return true;
}

bool CEffect::Start(Mof::CVector2 pos) {
    _show = true;
    _position = pos;
    return true;
}