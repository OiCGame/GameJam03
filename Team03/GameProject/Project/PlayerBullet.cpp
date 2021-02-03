#include	"PlayerBullet.h"
#include	"ResourceManager.h"

constexpr float BULLET_SPEED = 20.0f;

CPlayerBullet::CPlayerBullet() :
	m_Texture(),
	m_Position(0, 0),
	m_MoveVelocity(0, 0),
	m_MoveDistance(0),
	m_bShow(false) {
}

CPlayerBullet::~CPlayerBullet(){
}

void CPlayerBullet::Initialize(const CVector2 & pos, const CVector2& vec)
{
	m_Texture = &CResourceManager::Singleton().GetTextureList()->at("PlayerBullet");
	m_Position = pos;
	m_MoveVelocity = vec * BULLET_SPEED;
	m_Angle = atan2(-vec.y, -vec.x);

	m_bShow = true;
}

void CPlayerBullet::Update()
{
	//表示していない時は処理しない
	if (!m_bShow) {
		return;
	}
	m_Position += m_MoveVelocity;
	m_MoveDistance += BULLET_SPEED;

	float width = m_Texture->GetWidth();


	if (m_Position.x < -width) {
		m_bShow = false;
	}
	else if (m_Position.x > g_pGraphics->GetTargetWidth() + width) {
		m_bShow = false;
	}

	if (m_Position.y < -width) {
		m_bShow = false;
	}
	else if (m_Position.y > g_pGraphics->GetTargetHeight() + width) {
		m_bShow = false;
	}
}

void CPlayerBullet::Render()
{
	m_Texture->RenderRotate(m_Position.x, m_Position.y, m_Angle,CRectangle(0, 0, min(m_MoveDistance, ((float)m_Texture->GetWidth())), m_Texture->GetHeight()), TEXTUREALIGNMENT_CENTERLEFT);
}

void CPlayerBullet::RenderDebug(float top, float left)
{
	MofU32 textColor = MOF_XRGB(255, 255, 255);
	CGraphicsUtilities::RenderString(top, left, textColor, "Bullet: 座標 x{%6.2f},y{%6.2f}{%4.2f}", m_Position.x, m_Position.y, m_MoveDistance);

	//当たり判定用円表示
	CGraphicsUtilities::RenderCircle(GetCircle(), MOF_XRGB(0, 245, 0));
}
