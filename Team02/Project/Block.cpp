
#include	"Block.h"

CBlock::CBlock() :
    m_pBlockTexture(nullptr) {
}

CBlock::~CBlock() {
}

void CBlock::SetTexture(CTexture* pTexture) {
    m_pBlockTexture = pTexture;
}

void CBlock::Initialize(void) {
	m_Pos   = Vector2(0, 0);
	m_Timer = 0;
	m_bShow = false;
}

void CBlock::FallStart(CTexture* pTexture, int bullettype) {
    SetTexture(pTexture);
    m_BulletType = (BulletType)bullettype;
	m_bShow = true;
	m_Pos.y = -1 * static_cast<float>(m_pBlockTexture->GetHeight());
	m_Pos.x = CUtilities::Random(RANDOM_RANGE);
	m_DegreeAngle = CUtilities::Random(RADIAN_RANGE);
}

void CBlock::Update(void) {
	if (!m_bShow) {
        return;
	}
    // 落下処理
	m_DegreeAngle++;
	m_Pos.y += BLOCK_FALLSPEED * CUtilities::GetFrameSecond();
    // 画面外いった場合表示フラグを折る
	if (m_Pos.y > BOTTOM_LIMIT) {
		m_bShow = false;
	}
}

void CBlock::Render(void) {
    if (!m_bShow) {
        return;
    }
    m_pBlockTexture->RenderRotate(m_Pos.x, m_Pos.y, MOF_ToRadian(m_DegreeAngle), TEXALIGN_CENTERCENTER);
}

void CBlock::RenderDebug() {
    if(m_bShow)
        CGraphicsUtilities::RenderCircle(GetCollisionCircle(), MOF_COLOR_GREEN);
}

void CBlock::Release(void) {
	m_pBlockTexture = nullptr;
}

bool CBlock::IsShow(void) const {
    return m_bShow;
}

CCircle CBlock::GetCollisionCircle(void) const {
    if (!m_bShow) return CCircle();
    return CCircle(m_Pos, m_pBlockTexture->GetWidth() * 0.4f);
}

int CBlock::GetBulletType(void) const {
    return m_BulletType;
}
