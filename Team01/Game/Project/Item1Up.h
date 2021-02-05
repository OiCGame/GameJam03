#pragma once

#include "Item.h"

#include "Character.h"


class CItem1Up : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItem1Up();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItem1Up();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};