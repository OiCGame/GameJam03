#include "SceneBase.h"

CSceneBase::CSceneBase() :
	m_SelectNo(0),
	m_bEnd(false),
	m_NextSceneNo(0) {
}


void CSceneBase::SelectVertical(int& no, int count, bool loop) {
	if (CInputManager::GetInstance().GetVertical < 0.25 && CInputManager::GetInstance().GetVertical > -0.25)
	{
		m_Select.m_RemainVerticalGap = 0;
		m_Select.m_ContinuousVerticalCount = 0;
	}
	if (m_Select.m_RemainVerticalGap > 0)
	{
		m_Select.m_RemainVerticalGap--;
		return;
	}
	if (CInputManager::GetInstance().GetVertical > 0.75)
	{
		m_Select.m_RemainVerticalGap = m_SelectGap[m_Select.m_ContinuousVerticalCount];
		m_Select.m_ContinuousVerticalCount++;
		if (m_Select.m_ContinuousVerticalCount >= 2)
			m_Select.m_ContinuousVerticalCount = 2;

		no--;
		if (no < 0)
		{
			if (loop)
				no = (count - 1 < 0) ? 0 : count - 1;
			else
				no = 0;
		}
	}
	if (CInputManager::GetInstance().GetVertical < -0.75)
	{
		m_Select.m_RemainVerticalGap = m_SelectGap[m_Select.m_ContinuousVerticalCount];
		m_Select.m_ContinuousVerticalCount++;
		if (m_Select.m_ContinuousVerticalCount >= 2)
			m_Select.m_ContinuousVerticalCount = 2;

		no++;
		if (no > count - 1)
		{
			if (loop)
				no = 0;
			else
				no = count - 1;
		}
	}
}

void CSceneBase::SelectHorizontal(int& no, int count, bool loop) {
	if (CInputManager::GetInstance().GetHorizontal < 0.25 && CInputManager::GetInstance().GetHorizontal > -0.25)
	{
		m_Select.m_RemainHorizontalGap = 0;
		m_Select.m_ContinuousHorizontalCount = 0;
	}
	if (m_Select.m_RemainHorizontalGap > 0)
	{
		m_Select.m_RemainHorizontalGap--;
		return;
	}
	if (CInputManager::GetInstance().GetHorizontal > 0.75)
	{
		m_Select.m_RemainHorizontalGap = m_SelectGap[m_Select.m_ContinuousHorizontalCount];
		m_Select.m_ContinuousHorizontalCount++;
		if (m_Select.m_ContinuousHorizontalCount >= 2)
			m_Select.m_ContinuousHorizontalCount = 2;

		no++;
		if (no > count - 1)
		{
			if (loop)
				no = 0;
			else
				no = count - 1;
		}
	}
	if (CInputManager::GetInstance().GetHorizontal < -0.75)
	{
		m_Select.m_RemainHorizontalGap = m_SelectGap[m_Select.m_ContinuousHorizontalCount];
		m_Select.m_ContinuousHorizontalCount++;
		if (m_Select.m_ContinuousHorizontalCount >= 2)
			m_Select.m_ContinuousHorizontalCount = 2;

		no--;
		if (no < 0)
		{
			if (loop)
				no = (count - 1 < 0) ? 0 : count - 1;
			else
				no = 0;
		}
	}
}