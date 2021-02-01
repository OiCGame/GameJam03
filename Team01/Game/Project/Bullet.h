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
	Mof::CVector2 _position;
	//! �X�V���ɑ������܂��ړ���
	Mof::CVector2 _move;
	//! �\���摜
	Mof::CTexture* _texture;
	//! �\���t���O
	bool _show;
	//! ����
	TeamType _team_type;
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
	/// �Q�b�^�[
	/// </summary>
	Mof::CVector2 GetTextureSize(void) const;
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
};