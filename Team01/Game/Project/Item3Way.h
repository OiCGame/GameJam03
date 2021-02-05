#pragma once

#include "Item.h"

#include "Character.h"


class CItem3Way : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CItem3Way();
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~CItem3Way();
	/// <summary>
	/// 使用
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};