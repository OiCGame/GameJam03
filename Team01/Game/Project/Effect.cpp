#include "Effect.h"


CEffect::CEffect() :
	m_pTexture(),
    m_Motion(),
	m_bShow(false) {
}

CEffect::~CEffect() {
	m_Motion.Release();
}

Mof::CRectangle CEffect::GetCollisionRectangle(void) const {
    auto rect = m_Motion.GetSrcRect();
    rect.Translation(m_Position);
    return rect;
}

bool CEffect::IsShow(void) const {
    return this->m_bShow;
}

bool CEffect::Load(Mof::CTexture* texture, SpriteMotionData& anim) {
    m_pTexture = texture;    
    m_Motion.Create(anim.anims.data(),
                   anim.anims.size());
    return true;
}

bool CEffect::Update(void) {
    if (m_Motion.IsEndMotion()) {
        m_bShow = false;
    } // if

    m_Motion.AddTimer(::CUtilities::GetFrameSecond());
    return true;
}

bool CEffect::Render(void) {
    if (!m_pTexture) {
        return false;
    } // if

    auto pos = m_Position;
    m_pTexture->Render(pos.x, pos.y, m_Motion.GetSrcRect());
    return true;
}

bool CEffect::Start(Mof::CVector2 pos) {
    m_bShow = true;
	m_Position = pos;
    return true;
}