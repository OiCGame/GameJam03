#pragma once

#include "Item.h"

#include "Character.h"


class CItemAuto : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItemAuto();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItemAuto();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};