#pragma once

#include <Mof.h>

enum class BulletTeamType {
	Player,
	Enemy,
};

class Bullet {
private:
	//! �ʒu
	Mof::CVector2 _position;
	//! �X�V���ɑ������܂��ړ���
	Mof::CVector2 _move;
	//! �\���摜
	Mof::CTexture* _texture;
	//! �\���t���O
	bool _show;
	//! ����
	BulletTeamType _team_type;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Bullet();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Bullet();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    void SetTexture(Mof::CTexture* ptr);
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