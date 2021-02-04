#pragma once
#include "SceneBase.h"

class CSceneGameClear : public CSceneBase
{
private:
	//! テクスチャ
	Mof::CTexture m_Texture;

	static const int m_MessageCount = 2;
	std::string		m_OptionMessage[m_MessageCount] = { "ゲームクリアー","Pless Space : タイトルに戻る" };
public:
	CSceneGameClear();
	~CSceneGameClear();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};