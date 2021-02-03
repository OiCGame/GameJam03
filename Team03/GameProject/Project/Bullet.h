#pragma once

#include	<Mof.h>

enum class BulletType
{
	red,
	purple,
	yellow,
	orange,
};

class CBullet
{
private:
	const float  c_radius = 5;

	CTexture*	m_pTexture;
	CCircle	m_Body;
	CVector2 m_Vector;
	bool m_ShowFlag{ false };
	float	m_WaitTime{ 0.0f };
	float m_Stopwatch{ 0.0f };

public:
	
	void Initialize(const CVector2 & position, const CVector2 & vector, const float & wait, const BulletType& type);

	void Update();

	bool IsSurvival();

	void Render();

};

