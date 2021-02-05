#pragma once


#include <unordered_map>
#include <string>

#include <Mof.h>

#include "Item.h"
#include "Character.h"


class CShopShip {
private:
	//! 位置
	Mof::CVector2 m_Position;
	//! テクスチャ
	Mof::CTexture* m_pTexture;
	//! 表示
	bool m_bShow;
	//! テクスチャ
	std::unordered_map<std::string, Mof::CTexture>* m_pTextures;
	//! 輸送先
	CCharacter* m_pPlayer;
	//! 輸送物
	std::vector<std::shared_ptr<CItem>> m_Items;
	//! この距離を進むごとに荷物を１つ出す
	float m_TransportDistance;
	//! 進んだ距離　m_TransportDistanceを超えると0にする
	float m_TransportDistanceCount;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CShopShip();
	/// <summary>	
	/// デストラクタ
	/// </summary>
	~CShopShip();
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetTexutre(Mof::CTexture* ptr);
	void SetResources(std::unordered_map<std::string, Mof::CTexture>* ptr);
	void SetPlayer(CCharacter* ptr);
	/// <summary>
	/// 判定
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// 追加
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void AddItem(const std::shared_ptr<CItem>& ptr);
	/// <summary>
	/// セッター
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void Start(void);
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(std::vector<std::shared_ptr<CItem>>& out);
	/// <summary>
	/// 描画
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};