#pragma once

#include "Item.h"

#include "Character.h"


class CItemBulletPowerUp3 : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CItemBulletPowerUp3();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CItemBulletPowerUp3();
	/// <summary>
	/// �g�p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};