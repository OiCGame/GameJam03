#pragma once


#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

#include <Mof.h>

#include "Character.h"
#include "UICanvas.h"
#include "ShopItem.h"
#include "Item.h"
#include "ShopShip.h"


class CShop {
private:
	//! �t�H���g
	Mof::CFont m_Font;
	//! ���\�[�X
	std::unordered_map<std::string, Mof::CTexture>* m_pResources;
	//! �A�C�e��
	//std::vector<CShopItem> m_Items;
	std::vector<std::shared_ptr<CShopItem>> m_Items;
	//! �C���f�b�N�X
	int m_SelectIndex;
	//! �I��
	std::weak_ptr<CShopItem> m_pSelectItem;
	//! �\��
	bool m_bShow;
	//! �X�R�A��ێ�
	UICanvas* m_pCanvas;
	//! �A�˔���؂�
	bool m_bAutoShotSoldout;
	//! 3Way����؂�
	bool m_b3WayShotSoldout;
	//! �e���x��
	int m_BulletLevel;
	//! �e���x���ő�l
	int m_BulletLevelMax;

	/// <summary>
	/// �A�C�e���I��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void ItemSelect(void);
	/// <summary>
	/// �A�C�e���쐬
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::shared_ptr<CItem> CreateItem(int index);
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CShop();
	/// <summary>	
	/// �f�X�g���N�^
	/// </summary>
	~CShop();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetShowFlag(bool flag);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetCanvasPtr(UICanvas* ptr);
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
	bool Update(CShopShip& out);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};