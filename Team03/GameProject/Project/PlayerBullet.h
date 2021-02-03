#pragma once
#include	"Mof.h"

class CPlayerBullet
{
private:
	CTexture*		m_Texture;
	//���W
	CVector2		m_Position;
	//���x
	CVector2		m_MoveVelocity;

	float			m_Angle;

	bool			m_bShow;

	//�e�����X�ɕ\�����邽�߂̕ϐ�
	float			m_MoveDistance;

public:
	CPlayerBullet();
	~CPlayerBullet();
	void Initialize(const CVector2& pos, const CVector2& vec);
	void Update();
	void Render();
	void RenderDebug(float top, float left);

	bool IsShow() { return m_bShow; }

	CCircle GetCircle() { return CCircle(m_Position.x, m_Position.y, 20); }

};

