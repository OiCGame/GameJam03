#include "ResourceManager.h"

CResourceManager & CResourceManager::Singleton()
{
	static CResourceManager obj;
	return obj;
}

CResourceManager & CResourceManager::LoadTexture(std::string key, std::string path)
{
	m_Textures[key] = CTexture();
	if (m_Textures[key].Load(path.c_str())) {
		return *this;
	}
	return *this;
}

CResourceManager & CResourceManager::LoadSound(std::string key, std::string path)
{
	m_Sounds[key] = CSoundBuffer();
	if (m_Sounds[key].Load(path.c_str())) {
		return *this;
	}
	return *this;
}

void CResourceManager::Release()
{
	for (auto it = m_Textures.begin(); it != m_Textures.end(); it++)
	{
		it->second.Release();
	}
	for (auto it = m_Sounds.begin(); it != m_Sounds.end(); it++)
	{
		it->second.Release();
	}
}
