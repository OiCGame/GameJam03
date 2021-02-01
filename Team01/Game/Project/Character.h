#pragma once


#include <Mof.h>


class Character {
private:
    //! �ʒu
    Mof::CVector2 _position;
    //! �e�N�X�`��
    Mof::CTexture* _texture;
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
    void Shot(void);
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
    bool Update(void);
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