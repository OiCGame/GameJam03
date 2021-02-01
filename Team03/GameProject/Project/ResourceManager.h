#pragma once

#include <Mof.h>
#include	<unordered_map>

class CResourceManager
{
public:
	using TextureList =  std::unordered_map<std::string, CTexture>;
	using SoundList = std::unordered_map<std::string, CSoundBuffer>;

private:
	TextureList m_Textures;
	SoundList m_Sounds;

public:
	// �V���O���g��
	static CResourceManager& Singleton();

	// �摜�̓ǂݍ���
	CResourceManager& LoadTexture(std::string key, std::string path);

	// ���̓ǂݍ���
	CResourceManager& LoadSound(std::string key, std::string path);

	// �J��
	void Release();

	// �Q�b�^�[
	TextureList* GetTextureList() {
		return &m_Textures;
	}
	SoundList* GetSoundList() {
		return &m_Sounds;
	}

};

