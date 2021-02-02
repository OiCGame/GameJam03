#pragma once


#include <Mof.h>


class UILabel {
private:
	//! �e�L�X�g
	std::string text;
	//! �\���ʒu
	Mof::CVector2 position;
	//! �\���J�E���g
	int existance;
	//! �t�H���g  reference only
	Mof::CFont* font;
public:
	UILabel(const std::string& str, Mof::CVector2 pos, int exist, Mof::CFont* ptr) :
		text(str), position(pos), existance(exist), font(ptr) {
	}
	~UILabel() {
		font = nullptr;
	}
	/// <summary>
	/// ����
	/// </summary>
	bool IsExist(void) const {
		return 0 < existance;
	}
	/// <summary>
	/// �X�V
	/// </summary>
	bool Update(void) {
		if (!font) {
			return false;
		} // if

		existance--;
		if (existance <= 0) {
			existance = 0;
		} // if
		return true;
	}
	/// <summary>
	/// �`��
	/// </summary>
	bool Render(void) {
		if (!font) {
			return false;
		} // if

		return font->RenderString(position.x, position.y,
			MOF_ARGB(255, 255, 0, 0),
			text.c_str());
	}

};
class UIImage {
private:
	//! ���O
	std::string name;
	//! �e�N�X�`�� reference only
	Mof::CTexture* texture;
	//! �\���ʒu
	Mof::CVector2 position;
public:
	UIImage(const char* str, Mof::CTexture*tex, Mof::CVector2 pos) :
		name(str), texture(tex), position(pos) {
	}
	~UIImage() {
		texture = nullptr;
	}
	std::string GetName(void) const {
		return this->name;
	}
	/// <summary>
	/// �`��
	/// </summary>
	bool Render(void) {
		if (!texture) {
			return false;
		} // if
		return texture->Render(position.x, position.y);
	}
};
class UICanvas {
private:
	//! �t�H���g
	Mof::CFont m_Font;
	//! �X�R�A
	int m_Score;
	//! �\���p�X�R�A
	int m_RenderedScore;
	//! ���x��
	std::vector<UILabel> m_Labels;
	//! �摜
	std::vector<UIImage> m_Images;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	UICanvas();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~UICanvas();
	/// <summary>
	/// ������
	/// </summary>
	bool Initialize(void);
	/// <summary>
	/// �X�V
	/// </summary>
	bool Update(void);
	/// <summary>
	/// �`��
	/// </summary>
	bool Render(void);
	/// <summary>
	/// �X�R�A�ǉ�
	/// </summary>
	void AddScore(uint32_t value);
	/// <summary>
	/// �\���e�L�X�g�ǉ�
	/// <summary>
	void AddText(const std::string& text, Mof::CVector2 pos, int exist);
	/// <summary>
	/// �\���摜�ǉ�
	/// <summary>
	void AddImage(const char* name, Mof::CTexture* texture, Mof::CVector2 pos);
	/// <summary>
	/// �\���摜�폜
	/// <summary>
	void RemoveImage(const std::string& name);
};