#pragma once

#include <Mof.h>


class CBullet {
public:
	enum class TeamType {
		Player,
		Enemy,
	};
private:
	//! �ʒu
	Mof::CVector2 m_Position;
	//! �X�V���ɑ������܂��ړ���
	Mof::CVector2 m_Move;
	//! �\���摜
	Mof::CTexture* m_pTexture;
	//! �\���t���O
	bool m_bShow;
	//! ����
	TeamType m_TeamType;

	int m_BulletNo;
	bool m_bUnDisappear;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	CBullet();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~CBullet();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	void SetTexture(Mof::CTexture* ptr);
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	void Hide(void);
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	Mof::CVector2 GetTextureSize(void) const;
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	Mof::CRectangle GetCollisionRectangle(void) const;
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
	/// ����
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Shot(Mof::CVector2 init_pos, TeamType type);

	void SetNo(int no) { m_BulletNo = no; }
	int GetNo() { return m_BulletNo; }
};