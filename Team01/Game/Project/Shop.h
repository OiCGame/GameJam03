#pragma once


#include <vector>
#include <unordered_map>
#include <string>

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
	~CItem();
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
};
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
class CShop {
private:
	//! �t�H���g
	Mof::CFont m_Font;
	//! ���\�[�X
	std::unordered_map<std::string, Mof::CTexture>* m_pResources;
	//! �A�C�e��
	std::vector<CShopItem> m_Items;
	//! �C���f�b�N�X
	int m_SelectIndex;
	//! �I��
	CShopItem* m_pSelectItem;
	//! �ʒu
	Mof::CVector2 m_Position;
	//! �o����
	bool m_bShipShow;
	//! �A�C�e�����ˏo�����t���O
	bool m_bGive;
	//! �\��
	bool m_bShow;
	/// <summary>
	/// �A�C�e���I��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void ItemSelect(void);
public:
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	CShop();
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	~CShop();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShowFlag(bool flag);
	/// <summary>
	/// �t���O
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// ������
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(std::unordered_map<std::string, Mof::CTexture>* resources);
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(std::vector<std::shared_ptr<CItem>>& out, CCharacter& player);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};