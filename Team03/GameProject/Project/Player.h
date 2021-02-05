#pragma once
#include	"Mof.h"
#include	"PlayerBullet.h"
#include	"Item.h"

class CPlayer
{
private:
	CTexture*		m_TexturePlayer;
	CTexture*		m_TextureArrow;
	//���W
	CVector2		m_Position;
	float			m_Radius;
	//���x
	CVector2		m_MoveVelocity;

	//�v���C���[����}�E�X�̒P�ʃx�N�g��
	CVector2		m_MouseVector;
	//�e�̔z��
	std::vector<CPlayerBullet> m_BulletList;
	//�U���̃N�[���_�E���^�C��
	float			m_AttackCooldown;
	//�c�e��
	int				m_BulletRemain;

	//�c�@��
	int				m_Life;
	//���G����
	int				m_DamageWait;

	bool			m_bShow;

	CSoundBuffer* m_pSEShot;

	//���x�X�V����
	void VelocityUpdate();
	//�ړ�����
	void PositionUpdate();

public:
	CPlayer();
	~CPlayer();
	
	//bool Load();
	void Initialize(const CVector2& pos);
	void Update();
	void Render();
	void RenderDebug(float top, float left);
	//void Release();

	void TakeDamage();
	
	bool IsShow() { return m_bShow; }
	bool IsInvincible() { return m_DamageWait > 0; }
	//�����蔻�菈�������邩���Ȃ���
	bool IsDamageableable() { return m_bShow && m_DamageWait == 0; }

	CVector2 GetPostion() { return m_Position; }
	CCircle GetCircle() { return CCircle(m_Position, m_Radius); }
	CRectangle GetRectangle() { return CRectangle(m_Position.x - m_Radius, m_Position.y - m_Radius, m_Position.x + m_Radius, m_Position.y + m_Radius); }

	std::vector<CPlayerBullet> GetBullet() { return m_BulletList; }

	int GetLife() { return m_Life; }

	int  GetBulletRemain() { return m_BulletRemain; }
	void SetBulletRemain(int num) { m_BulletRemain = num; }

	bool ItemCollisionCheck(const CItem& item);
};

