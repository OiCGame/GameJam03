#pragma once


#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include <Mof.h>

#include "Character.h"
#include "UICanvas.h"
#include "ShopItem.h"
#include "Item.h"
#include "ShopShip.h"


class CShop {
private:
	//! フォント
	Mof::CFont m_Font;
	//! リソース
	std::unordered_map<std::string, Mof::CTexture>* m_pResources;
	//! アイテム
	//std::vector<CShopItem> m_Items;
	std::vector<std::shared_ptr<CShopItem>> m_Items;
	//! インデックス
	int m_SelectIndex;
	//! 選択中
	std::weak_ptr<CShopItem> m_pSelectItem;
	//! 表示
	bool m_bShow;
	//! スコアを保持
	UICanvas* m_pCanvas;
	//! 連射売り切れ
	bool m_bAutoShotSoldout;
	//! 3Way売り切れ
	bool m_b3WayShotSoldout;
	//! 弾レベル
	int m_BulletLevel;
	//! 弾レベル最大値
	int m_BulletLevelMax;

	/// <summary>
	/// アイテム選択
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void ItemSelect(void);
	/// <summary>
	/// アイテム作成
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::shared_ptr<CItem> CreateItem(int index);
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CShop();
	/// <summary>	
	/// デストラクタ
	/// </summary>
	~CShop();
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShowFlag(bool flag);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetCanvasPtr(UICanvas* ptr);
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
	bool Update(CShopShip& out);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};