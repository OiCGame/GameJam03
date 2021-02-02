#pragma once


#include <array>

#include "GameDefine.h"

#include "Bullet.h"


class CCharacter {
protected:
	//! �ʒu
	Mof::CVector2 _position;
	//! �ړ�
	Mof::CVector2 _move;
	//! �ړ�
	Mof::CVector2 _speed;
	//! �e�N�X�`��
	Mof::CTexture* _texture;
	//! Bullet�e�N�X�`��
	Mof::CTexture* _bullet_texture;
	//! HP
	int _hp;
	//! �\��
	bool _show;
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
	void Damege(void);
};