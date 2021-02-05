#pragma once


#include <unordered_map>
#include <string>

#include <Mof.h>

#include "Item.h"
#include "Character.h"


class CShopShip {
private:
	//! �ʒu
	Mof::CVector2 m_Position;
	//! �e�N�X�`��
	Mof::CTexture* m_pTexture;
	//! �\��
	bool m_bShow;
	//! �e�N�X�`��
	std::unordered_map<std::string, Mof::CTexture>* m_pTextures;
	//! �A����
	CCharacter* m_pPlayer;
	//! �A����
	std::vector<std::shared_ptr<CItem>> m_Items;
	//! ���̋�����i�ނ��Ƃɉו����P�o��
	float m_TransportDistance;
	//! �i�񂾋����@m_TransportDistance�𒴂����0�ɂ���
	float m_TransportDistanceCount;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CShopShip();
	/// <summary>	
	/// �f�X�g���N�^
	/// </summary>
	~CShopShip();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void SetTexutre(Mof::CTexture* ptr);
	void SetResources(std::unordered_map<std::string, Mof::CTexture>* ptr);
	void SetPlayer(CCharacter* ptr);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool IsShow(void) const;
	/// <summary>
	/// �ǉ�
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void AddItem(const std::shared_ptr<CItem>& ptr);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	void Start(void);
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Update(std::vector<std::shared_ptr<CItem>>& out);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Render(void);
};