#pragma once

#include "Item.h"

#include "Character.h"


class CItemBulletPowerUp4 : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItemBulletPowerUp4();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItemBulletPowerUp4();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};