#pragma once

#include "Item.h"

#include "Character.h"


class CItemBulletPowerUp2 : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItemBulletPowerUp2();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItemBulletPowerUp2();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};