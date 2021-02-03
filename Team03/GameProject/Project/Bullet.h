#pragma once

#include	<Mof.h>

class CBullet
{
private:
	CCircle	m_Body;
	CVector2 m_Vector;
	bool m_ShowFlag{ false };
	float	m_WaitTime{ 0.0f };
	float m_Stopwatch{ 0.0f };

public:
	
	void Initialize(const CVector2 & position, const CVector2 & vector, const float & wait);

	void Update();

	bool IsSurvival();

	void Render();

};

