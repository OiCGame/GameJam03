#include "EffectManager.h"

CEffectManager & CEffectManager::Singleton()
{
	static CEffectManager obj;
	return obj;
}

void CEffectManager::addEffect(CTexture * ptex, const CVector2 & pos)
{
	m_EffectList.push_back(EffectStatus{ ptex, pos });
}

bool CEffectManager::FinishedAll()
{
	return m_EffectList.size() == 0;
}

std::vector<EffectStatus>* CEffectManager::GeteffectList()
{
	return &m_EffectList;
}

void CEffectManager::Update()
{
	auto it = std::remove_if(
		m_EffectList.begin(),
		m_EffectList.end(),
		[](EffectStatus& effect) { return effect.end_flag == true;}
	);
	m_EffectList.erase(it, m_EffectList.end());

	for (auto & effect : m_EffectList) {
		effect.t += 30;
		if (effect.t >= 1000) {
			effect.t = 1000;
			effect.end_flag = true;
		}
	}
}

void CEffectManager::Render()
{
	for (const auto & effect : m_EffectList) {
		int alpha = 255 * (-abs(effect.t * 0.001f - 0.5f) * 2 + 1);
		effect.texture->RenderScale(
			effect.position.x,
			effect.position.y,
			0.9f,
			MOF_ARGB(alpha, 255, 255, 255),
			TextureAlignment::TEXALIGN_CENTERCENTER
		);
	}
}

void CEffectManager::Release()
{
	m_EffectList.clear();
}
