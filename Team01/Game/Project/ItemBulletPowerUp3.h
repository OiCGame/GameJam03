#pragma once

#include "Item.h"

#include "Character.h"


class CItemBulletPowerUp3 : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItemBulletPowerUp3();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItemBulletPowerUp3();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};