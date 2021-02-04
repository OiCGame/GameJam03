#pragma once


#include <unordered_map>
#include <string>

#include <Mof.h>


class CShopItem {
private:
	//! フォント
	Mof::CFont* m_pFont;
	//! 位置
	Mof::CVector2 m_Position;
	//! テクスチャ
	Mof::CTexture* m_pTexture;
	//! 文
	std::string m_DatailText;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CShopItem();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CShopItem();
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(Mof::CFont* font, Mof::CVector2 pos, Mof::CTexture* tex, const std::string& text);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};
class CShop {
private:
	//! フォント
	Mof::CFont m_Font;
	//! リソース
	std::unordered_map<std::string, Mof::CTexture> *m_pResources;
	std::string m_PlayerTexturePath;
	std::string m_BulletTexturePath;

	CShopItem m_Item;
public:
	CShop();
	~CShop();
	bool Initialize(std::unordered_map<std::string, Mof::CTexture> * resources,
		std::string playerTexturePath,
		std::string bulletTexturePath);
	bool Render(void);
};