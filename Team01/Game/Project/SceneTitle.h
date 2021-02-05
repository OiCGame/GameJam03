#pragma once
#include "SceneBase.h"

//#include <Mof.h>
class CSceneTitle : public CSceneBase {
private:
	//! テクスチャ
	Mof::CTexture m_Texture;
	Mof::CTexture m_ShopTexture;
	//! 文字
	Mof::CFont m_Font;

	static const int m_MessageCount = 3;
//	std::string		m_Message[m_MessageCount] = { "連鎖するシューティング","ゲームスタート", "ランキング" };
	std::string		m_Message[m_MessageCount] = { "","ゲームスタート", "ランキング" };
public:
	CSceneTitle();
	~CSceneTitle();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);
};