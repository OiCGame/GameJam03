#pragma once

#include "Item.h"

#include "Character.h"


class CItemBulletPowerUp2 : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CItemBulletPowerUp2();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CItemBulletPowerUp2();
	/// <summary>
	/// �g�p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};