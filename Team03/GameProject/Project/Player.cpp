#include	"Player.h"
#include	"ResourceManager.h"

constexpr float MAX_SPEED = 10.0f;
constexpr float ACCELERATION = 3.0f;
constexpr float DECELERATE = 0.5f;

constexpr float limit = (MAX_SPEED - ACCELERATION) / MAX_SPEED;
constexpr float limitHalf = (MAX_SPEED * 0.5f - ACCELERATION) / (MAX_SPEED * 0.5f);

constexpr int INVINCIBLE_FRAME = 60;

constexpr float ATTACK_COOLDOWN_TIME = 2.0f;

void CPlayer::VelocityUpdate()
{
	//���x�v�Z����
	CVector2 vector;
	if (g_pInput->IsKeyHold(MOFKEY_W)) {
		vector.y = -1;
	}
	else if (g_pInput->IsKeyHold(MOFKEY_S)) {
		vector.y = 1;
	}

	if (g_pInput->IsKeyHold(MOFKEY_A)) {
		vector.x = -1;
	}
	else if (g_pInput->IsKeyHold(MOFKEY_D)) {
		vector.x = 1;
	}
	if (vector.x != 0 || vector.y != 0) {
		float length = vector.Length();
		vector /= length;
		vector *= ACCELERATION;
		//���x��������
		if (g_pInput->IsKeyHold(MOFKEY_LSHIFT)) {
			m_MoveVelocity *= limitHalf;
		}
		else {
			m_MoveVelocity *= limit;
		}
		m_MoveVelocity += vector;
	}
	else {
		m_MoveVelocity *= DECELERATE;
	}
}

void CPlayer::PositionUpdate()
{
	//�ړ�����
	m_Position += m_MoveVelocity;

	//��ʊO�ɔ�яo���Ȃ��悤�ɂ��鏈��
	float widthHalf = m_TexturePlayer->GetWidth() * 0.5f;
	float heightHalf = m_TexturePlayer->GetHeight() * 0.5f;

	if (m_Position.x < widthHalf) {
		m_Position.x = widthHalf;
	}
	else if (m_Position.x > g_pGraphics->GetTargetWidth() - widthHalf) {
		m_Position.x = g_pGraphics->GetTargetWidth() - widthHalf;
	}

	if (m_Position.y < heightHalf) {
		m_Position.y = heightHalf;
	}
	else if (m_Position.y > g_pGraphics->GetTargetHeight() - heightHalf) {
		m_Position.y = g_pGraphics->GetTargetHeight() - heightHalf;
	}
}

CPlayer::CPlayer() :
	m_TexturePlayer(),
	m_Position(0, 0),
	m_Radius(20),
	m_MoveVelocity(0, 0),
	m_BulletRemain(3),
	m_Life(0),
	m_DamageWait(0),
	m_AttackCooldown(0),
	m_bShow(false) {
}

CPlayer::~CPlayer(){
}

//bool CPlayer::Load()
//{
//	m_Texture = new CTexture();
//
//	m_Texture->Load("PlayerUFO.png");
//	return true;
//}

void CPlayer::Initialize(const CVector2& pos)
{
	//Texture�̎擾
	m_TexturePlayer = &CResourceManager::Singleton().GetTextureList()->at("Player");
	m_TextureArrow = &CResourceManager::Singleton().GetTextureList()->at("PlayerArrow");
	// SE�̎擾
	m_pSEShot = &CResourceManager::Singleton().GetSoundList()->at("se_PlayerShot");
	m_pSEShot->SetVolume(0.5f);
	//�������W�̐ݒ�
	m_Position = pos;
	m_MoveVelocity.SetValue(0,0);
	//�\��
	m_bShow = true;

	m_Life = 4;
	m_DamageWait = 0;
	m_AttackCooldown = 0;

	m_Radius = m_TexturePlayer->GetHeight() * 0.25f;
}

void CPlayer::Update()
{
	this->MoveUpdate();

	//�U������
	if (m_BulletRemain > 0) {
		//�U��CT
		if (m_AttackCooldown > 0) {
			m_AttackCooldown -= CUtilities::GetFrameSecond();
			if (m_AttackCooldown < 0) {
				m_AttackCooldown = 0;
			}
		}
		else {
			if (g_pInput->IsMouseKeyPush(MOFMOUSE_LBUTTON)) {
				//�U��
				m_pSEShot->Play();
				CPlayerBullet bullet;
				bullet.Initialize(m_Position + m_MouseVector * m_Radius, m_MouseVector);

				m_BulletList.push_back(bullet);
				m_AttackCooldown = ATTACK_COOLDOWN_TIME;
				m_BulletRemain--;
			}
		}
	}

	for (int i = m_BulletList.size() - 1; i >= 0; i--)
	{
		m_BulletList[i].Update();
		if (!m_BulletList[i].IsShow()) {
			m_BulletList.erase(m_BulletList.begin() + i);
		}
	}
}

void CPlayer::MoveUpdate()
{
	//���@����}�E�X�̒P�ʃx�N�g��
	float mouseX, mouseY;
	g_pInput->GetMousePos(mouseX, mouseY);
	CVector2(mouseX - m_Position.x, mouseY - m_Position.y).Normal(m_MouseVector);

	//�\�����Ă��Ȃ����͏������Ȃ�
	if (!m_bShow) {
		return;
	}
	if (m_DamageWait > 0) {
		m_DamageWait--;
	}


	//���x�v�Z����
	VelocityUpdate();
	//�ړ�����
	PositionUpdate();
}

void CPlayer::Render()
{
	//�\�����Ă��Ȃ����͏������Ȃ�
	if (!m_bShow) {
		return;
	}

	//���
	CVector2 arrowPos = m_Position + m_MouseVector * (m_Radius + 50);
	float arrowHeight = m_TextureArrow->GetHeight();
	//CT�\������
	arrowHeight *= m_AttackCooldown / ATTACK_COOLDOWN_TIME;
	CRectangle arrowRect = CRectangle(0, arrowHeight, m_TextureArrow->GetWidth(), m_TextureArrow->GetHeight());
	m_TextureArrow->RenderRotate(arrowPos.x, arrowPos.y, atan2(m_MouseVector.x, -m_MouseVector.y), arrowRect, TEXTUREALIGNMENT_BOTTOMCENTER);

	for (int i = 0; i < m_BulletList.size(); i++)
	{
		m_BulletList[i].Render();
	}

	int alpha = m_DamageWait % 8 < 4 ? 255 : 100;
	m_TexturePlayer->Render(m_Position.x, m_Position.y, MOF_ALPHA_WHITE(alpha), TEXTUREALIGNMENT_CENTERCENTER);
}

void CPlayer::RenderDebug(float top, float left)
{
	MofU32 textColor = MOF_XRGB(255, 255, 255);
	//�e�ϐ�
	CGraphicsUtilities::RenderString(top, left, textColor, "Player:");
	CGraphicsUtilities::RenderString(top + 60, left + 30 , textColor, "���W x{%6.2f},y{%6.2f}", m_Position.x, m_Position.y);
	CGraphicsUtilities::RenderString(top + 60, left + 60 , textColor, "���x�x�N�g�� x{%6.2f},y{%6.2f}", m_MoveVelocity.x, m_MoveVelocity.y);
	CGraphicsUtilities::RenderString(top + 60, left + 90 , textColor, "�\���t���O {%u}", m_bShow);
	CGraphicsUtilities::RenderString(top + 60, left + 120, textColor, "�c�e�� {%d}", m_BulletRemain);
	CGraphicsUtilities::RenderString(top + 60, left + 150, textColor, "�c�@�� {%d}", m_Life);
	
	for (int i = 0 ; i < m_BulletList.size(); i++)
	{
		m_BulletList[i].RenderDebug(top + 60, left + 180 + i * 30);
	}

	//�����蔻��p�~�\��
	CGraphicsUtilities::RenderCircle(GetCircle(), MOF_XRGB(0, 245, 0));
}

//void CPlayer::Release()
//{
//	delete m_Texture;
//	m_Texture = NULL;
//}

void CPlayer::TakeDamage()
{
	m_DamageWait = INVINCIBLE_FRAME;
	m_Life--;
}

bool CPlayer::ItemCollisionCheck(const CItem& item)
{
	bool b = item.GetCircle().CollisionCircle(GetCircle());
	if (b) {
		switch (item.GetItemType())
		{
		case ItemType::ITEM_LIFE:
			m_Life += 1;
			break;
		}
	}
	return b;
}

