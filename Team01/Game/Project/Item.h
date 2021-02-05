#pragma once


#include <Mof.h>

#include "Character.h"


class CItem {
private:
	//! �ʒu
	Mof::CVector2 m_Position;
	//! �e�N�X�`��
	Mof::CTexture* m_pTexture;
	//! �\��
	bool m_bShow;
	//! �s��
	CCharacter* m_pTarget;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CItem();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~CItem();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetPosition(Mof::CVector2 pos);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetTexture(Mof::CTexture* ptr);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShow(bool flag);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetPlayer(CCharacter* ptr);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CRectangle GetRectangle(void) const;
	/// <summary>
	/// ����
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(void);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
	/// <summary>
	/// �g�p
	/// </summary>
    /// <param name=""></param>
    /// <returns></returns>
	virtual bool Use(CCharacter& out) = 0;
};