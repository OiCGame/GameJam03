#pragma once

#include "Item.h"

#include "Character.h"


class CItemBulletPowerUp1 : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItemBulletPowerUp1();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItemBulletPowerUp1();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};