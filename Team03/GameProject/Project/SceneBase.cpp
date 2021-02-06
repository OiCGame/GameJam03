#include "SceneBase.h"

void CSceneBase::Initialize()
{
	m_bSceneEnd = false;
	m_FadeAlpha = 255;
}

void CSceneBase::Update()
{
	if (m_bSceneEnd)
	{
		m_FadeAlpha += 5;
		if (m_FadeAlpha >= 255)
		{
			m_EndFlag = true;
		}
	}
	else
	{
		if (m_FadeAlpha > 0)
		{
			m_FadeAlpha -= 5;
		}
	}
}

void CSceneBase::Render()
{
	CGraphicsUtilities::RenderFillRect(0, 0, g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(), MOF_ARGB(m_FadeAlpha, 0, 0, 0));
}
