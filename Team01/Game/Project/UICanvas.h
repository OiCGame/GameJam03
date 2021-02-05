#pragma once


#include <Mof.h>

#include <unordered_map>
#include <string>


struct FontMap{
	//! 文字テクスチャ
	Mof::CTexture texture;
	//! フォントのUV座標配列
	std::unordered_map<std::string, Mof::CRectangle> uvs;
};
class UILabel {
private:
	//! テキスト
	std::string text;
	//! 表示位置
	Mof::CVector2 position;
	//! 表示カウント
	int existance;
	//! フォント  reference only
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
	//! フォントのUV座標配列
//	std::unordered_map<std::string, Mof::CRectangle> m_FontMap;
	//! フォントテクスチャ
//	Mof::CTexture m_FontTexture;

	FontMap m_FontMap;
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
	/// ゲッター
	/// </summary>
	uint32_t GetScore(void) const;
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
	/// 解放
	/// </summary>
	bool Release(void);
	/// <summary>
	/// スコア追加
	/// </summary>
	void AddScore(uint32_t value);
	void SubtractScore(uint32_t value);
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