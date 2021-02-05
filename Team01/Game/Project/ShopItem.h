#pragma once


#include <string>

#include <Mof.h>


class CShopItem {
private:
	//! フォント
	Mof::CFont* m_pFont;
	//! テクスチャ
	Mof::CTexture* m_pTexture;
	//! 文
	std::string m_DetailsText;
	//! 値段
	uint32_t m_Price;
	//! 枠
	const Mof::CRectangle m_Frame;
	//! 選択中
	bool m_bSelect;
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
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetSelectFlag(bool flag);
	/// <summary>
	/// サイズ
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CVector2 GetSize(void) const;
	/// <summary>
	/// 値段
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	uint32_t GetPrice(void) const;
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
//	bool Initialize(Mof::CFont* font, Mof::CTexture* tex, const std::string& text, uint32_t price);
	bool Initialize(Mof::CFont* font, Mof::CTexture* tex, uint32_t price);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(Mof::CVector2 position);
};
