#pragma once

#include "Item.h"

#include "Character.h"


class CItem1Up : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CItem1Up();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CItem1Up();
	/// <summary>
	/// �g�p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};