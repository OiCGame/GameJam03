#pragma once

#include "Item.h"

#include "Character.h"


class CItem3Way : public CItem {
	using super = CItem;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CItem3Way();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CItem3Way();
	/// <summary>
	/// �g�p
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Use(CCharacter & out) override;
};