#pragma once


#include <array>

#include <Mof.h>

#include "Bullet.h"


class Character {
private:
    //! �ʒu
    Mof::CVector2 _position;
    //! �e�N�X�`��
    Mof::CTexture* _texture;
    //! Bullet�e�N�X�`��
    Mof::CTexture* _bullet_texture;
protected:
    /// <summary>
    /// �ړ�
    /// </summary>
    /// <param name=""></param>
    void Move(void);
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    bool Shot(std::array<Bullet, 256>& bullet_container);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Character();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Character();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    void SetTexture(Mof::CTexture* ptr);
    void SetBulletTexture(Mof::CTexture* ptr);
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(Mof::CVector2 init_pos);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Update(std::array<Bullet, 256>& bullet_container);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Render(void);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};