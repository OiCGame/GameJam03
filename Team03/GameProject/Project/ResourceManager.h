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
	// シングルトン
	static CResourceManager& Singleton();

	// 画像の読み込み
	CResourceManager& LoadTexture(std::string key, std::string path);

	// 音の読み込み
	CResourceManager& LoadSound(std::string key, std::string path);

	// 開放
	void Release();

	// ゲッター
	TextureList* GetTextureList() {
		return &m_Textures;
	}
	SoundList* GetSoundList() {
		return &m_Sounds;
	}

};

