#pragma once


#include <vector>
#include <unordered_map>
#include <string>

#include <Mof.h>

#include "Character.h"


class CItem {
private:
	//! 位置
	Mof::CVector2 m_Position;
	//! テクスチャ
	Mof::CTexture* m_pTexture;
	//! 表示
	bool m_bShow;
	//! 行先
	CCharacter* m_pTarget;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItem();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~CItem();
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetPosition(Mof::CVector2 pos);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetTexture(Mof::CTexture* ptr);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShow(bool flag);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetPlayer(CCharacter* ptr);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CRectangle GetRectangle(void) const;
	/// <summary>
	/// 判定
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};
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
class CShop {
private:
	//! フォント
	Mof::CFont m_Font;
	//! リソース
	std::unordered_map<std::string, Mof::CTexture>* m_pResources;
	//! アイテム
	std::vector<CShopItem> m_Items;
	//! インデックス
	int m_SelectIndex;
	//! 選択中
	CShopItem* m_pSelectItem;
	//! 位置
	Mof::CVector2 m_Position;
	//! 出現中
	bool m_bShipShow;
	//! アイテムを射出したフラグ
	bool m_bGive;
	//! 表示
	bool m_bShow;
	/// <summary>
	/// アイテム選択
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void ItemSelect(void);
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	CShop();
	/// <summary>
	/// コンストラクタ
	/// </summary>
	~CShop();
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShowFlag(bool flag);
	/// <summary>
	/// フラグ
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(std::unordered_map<std::string, Mof::CTexture>* resources);
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(std::vector<std::shared_ptr<CItem>>& out, CCharacter& player);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};