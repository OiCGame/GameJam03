#include "Effect.h"


CEffect::CEffect() :
	m_pTexture(),
    m_Motion(),
	m_bShow(false),
	m_ChainCount(0){
}

CEffect::~CEffect() {
	m_Motion.Release();
}

Mof::CRectangle CEffect::GetCollisionRectangle(void) const {
    auto rect = m_Motion.GetSrcRect();
	rect = Mof::CRectangle(
		0.0f, 0.0f,
		rect.GetWidth(), rect.GetHeight());
	rect.Translation(m_Position);
    return rect;
}

uint32_t CEffect::GetChainCount(void) const{
	return this->m_ChainCount;
}

int CEffect::GetDamageValue(bool exist_boss) const{
	return exist_boss ? 10 : 3;
}

bool CEffect::IsShow(void) const {
    return this->m_bShow;
}

bool CEffect::Generate(Mof::CTexture* texture, SpriteMotionData& anim, uint32_t chain_count) {
    m_pTexture = texture;    
    m_Motion.Create(anim.anims.data(),
                   anim.anims.size());
	m_ChainCount = chain_count;
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

#ifdef _DEBUG
	::CGraphicsUtilities::RenderFillRect(
		this->GetCollisionRectangle(),
		MOF_ARGB(100, 100, 100, 100)
	);
#endif // _DEBUG
    auto pos = m_Position;
    m_pTexture->Render(pos.x, pos.y, m_Motion.GetSrcRect());
    return true;
}

bool CEffect::Start(Mof::CVector2 pos) {
    m_bShow = true;
	m_Position = pos;
    return true;
}

bool CEffect::Chain(void) {
	if (!this->IsShow()) {
		return false;
	} // if
	m_ChainCount++;
	return true;
}