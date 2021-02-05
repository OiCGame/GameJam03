#pragma once


#include <array>

#include "GameDefine.h"
#include "Bullet.h"


class CCharacter {
protected:
	//! �ʒu
	Mof::CVector2 m_Position;
	//! �ړ�
	Mof::CVector2 m_Move;
	//! �ړ�
	Mof::CVector2 m_Speed;
	//! �e�N�X�`��
	Mof::CTexture* m_pTexture;
	//! Bullet�e�N�X�`��
	Mof::CTexture* m_pBulletTexture;
	//! HP
	int m_HP;
	//! �\��
	bool m_bShow;
	//! �c�@
	uint32_t m_RevivalCount;
	//! �A��
	bool m_bAutoShot;
	//! ���ˊԊu �A�C�e���擾���ɃC���^�[�o����Z������
	int m_ShotInterval;
	//! ���ˊԊu�J�E���g
	int m_ShotIntervalCount;
	//! 3Way
	bool m_b3WayShot;

	int m_BulletNo;
	/// <summary>
	/// �ړ�
	/// </summary>
	/// <param name=""></param>
	virtual void Move(void);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name=""></param>
	virtual bool Shot(std::array<CBullet, 256>& bullet_container);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CCharacter();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~CCharacter();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    void SetTexture(Mof::CTexture* ptr);
    void SetBulletTexture(Mof::CTexture* ptr);
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Mof::CVector2 GetPosition(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
	Mof::CRectangle GetCollisionRectangle(void) const;
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	uint32_t GetRevivalCount(void) const;
	/// <summary>
    /// �Q�b�^�[
    /// </summary>
	bool IsShow(void) const;
	/// <summary>
	/// ������
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Initialize(Mof::CVector2 init_pos);
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Update(std::array<CBullet, 256>& bullet_container);
	/// <summary>
	/// �`��
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Render(void);
	/// <summary>
	/// ���
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	virtual bool Release(void);
	/// <summary>
	/// �_���[�W
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool Damage(void);
};