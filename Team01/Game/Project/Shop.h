#pragma once


#include <unordered_map>
#include <string>

#include <Mof.h>


class CShopItem {
private:
	//! �t�H���g
	Mof::CFont* m_pFont;
	//! �ʒu
	Mof::CVector2 m_Position;
	//! �e�N�X�`��
	Mof::CTexture* m_pTexture;
	//! ��
	std::string m_DatailText;
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
	/// ������
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Initialize(Mof::CFont* font, Mof::CVector2 pos, Mof::CTexture* tex, const std::string& text);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};
class CShop {
private:
	//! �t�H���g
	Mof::CFont m_Font;
	//! ���\�[�X
	std::unordered_map<std::string, Mof::CTexture> *m_pResources;
	std::string m_PlayerTexturePath;
	std::string m_BulletTexturePath;

	CShopItem m_Item;
public:
	CShop();
	~CShop();
	bool Initialize(std::unordered_map<std::string, Mof::CTexture> * resources,
		std::string playerTexturePath,
		std::string bulletTexturePath);
	bool Render(void);
};