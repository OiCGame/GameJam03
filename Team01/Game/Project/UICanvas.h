#pragma once


#include <Mof.h>

#include <unordered_map>
#include <string>


struct FontMap{
	//! �����e�N�X�`��
	Mof::CTexture texture;
	//! �t�H���g��UV���W�z��
	std::unordered_map<std::string, Mof::CRectangle> uvs;
};
class UILabel {
private:
	//! �e�L�X�g
	std::string text;
	//! �\���ʒu
	Mof::CVector2 position;
	//! �\���J�E���g
	int existance;
	//! �t�H���g  reference only
//	Mof::CFont* font;
	FontMap* font;
//	Mof::CTexture* font;
	//std::unordered_map<std::string, Mof::CRectangle>* m_FontMap;
public:
	UILabel(const std::string& str, Mof::CVector2 pos, int exist, FontMap* ptr) :
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

		auto pos = position;
		for (int i = 0; i < text.size() ; i++) {
			auto key = text.substr(i, 1);
			font->texture.Render(pos.x, pos.y, font->uvs.at(key));
			pos.x += 40.0f;
		} // for
		return true;
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
	//! �t�H���g��UV���W�z��
//	std::unordered_map<std::string, Mof::CRectangle> m_FontMap;
	//! �t�H���g�e�N�X�`��
//	Mof::CTexture m_FontTexture;

	FontMap m_FontMap;
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
	/// �Q�b�^�[
	/// </summary>
	uint32_t GetScore(void) const;
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
	/// ���
	/// </summary>
	bool Release(void);
	/// <summary>
	/// �X�R�A�ǉ�
	/// </summary>
	void AddScore(uint32_t value);
	void SubtractScore(uint32_t value);
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