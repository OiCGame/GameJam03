#pragma once


#include <string>

#include <Mof.h>


class CShopItem {
private:
	//! �t�H���g
	Mof::CFont* m_pFont;
	//! �e�N�X�`��
	Mof::CTexture* m_pTexture;
	//! ��
	std::string m_DetailsText;
	//! �l�i
	uint32_t m_Price;
	//! �g
	const Mof::CRectangle m_Frame;
	//! �I��
	bool m_bSelect;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CShopItem();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CShopItem();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetSelectFlag(bool flag);
	/// <summary>
	/// �T�C�Y
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CVector2 GetSize(void) const;
	/// <summary>
	/// �l�i
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	uint32_t GetPrice(void) const;
	/// <summary>
	/// ������
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
//	bool Initialize(Mof::CFont* font, Mof::CTexture* tex, const std::string& text, uint32_t price);
	bool Initialize(Mof::CFont* font, Mof::CTexture* tex, uint32_t price);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(Mof::CVector2 position);
};
