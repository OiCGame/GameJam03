#pragma once

#include "Item.h"

#include "Character.h"


class CItemAuto : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CItemAuto();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CItemAuto();
	/// <summary>
	/// �g�p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};