#pragma once


#include <Mof.h>


class UILabel {
private:
	//! テキスト
	std::string text;
	//! 表示位置
	Mof::CVector2 position;
	//! 表示カウント
	int existance;
	//! フォント  reference only
	Mof::CFont* font;
public:
	UILabel(const std::string& str, Mof::CVector2 pos, int exist, Mof::CFont* ptr) :
		text(str), position(pos), existance(exist), font(ptr) {
	}
	~UILabel() {
		font = nullptr;
	}
	/// <summary>
	/// 判定
	/// </summary>
	bool IsExist(void) const {
		return 0 < existance;
	}
	/// <summary>
	/// 更新
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
	/// 描画
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
	//! 名前
	std::string name;
	//! テクスチャ reference only
	Mof::CTexture* texture;
	//! 表示位置
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
	/// 描画
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
	//! フォント
	Mof::CFont m_Font;
	//! スコア
	int m_Score;
	//! 表示用スコア
	int m_RenderedScore;
	//! ラベル
	std::vector<UILabel> m_Labels;
	//! 画像
	std::vector<UIImage> m_Images;
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	UICanvas();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~UICanvas();
	/// <summary>
	/// 初期化
	/// </summary>
	bool Initialize(void);
	/// <summary>
	/// 更新
	/// </summary>
	bool Update(void);
	/// <summary>
	/// 描画
	/// </summary>
	bool Render(void);
	/// <summary>
	/// スコア追加
	/// </summary>
	void AddScore(uint32_t value);
	/// <summary>
	/// 表示テキスト追加
	/// <summary>
	void AddText(const std::string& text, Mof::CVector2 pos, int exist);
	/// <summary>
	/// 表示画像追加
	/// <summary>
	void AddImage(const char* name, Mof::CTexture* texture, Mof::CVector2 pos);
	/// <summary>
	/// 表示画像削除
	/// <summary>
	void RemoveImage(const std::string& name);
};