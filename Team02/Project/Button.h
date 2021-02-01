#pragma once
#include "Mof.h"

// ********************************************************************************
/// <summary>
/// ボタンクラス
/// </summary>
// ********************************************************************************
class CButton
{
private:

    CTexture* m_pBtnTexture;            //! ボタン本体画像
    CTexture* m_pFontTexture;           //! ボタン文字画像
    Vector2   m_Pos;                    //! 描画座標
    Vector2   m_Scale{ 1.0f, 1.0f };    //! 画像表示倍率

public:

    // ********************************************************************************
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    CButton(void);

    // ********************************************************************************
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    ~CButton(void);

    // ********************************************************************************
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name="pos">描画座標</param>
    /// <param name="pBase">本体ボタンテクスチャポインタ</param>
    /// <param name="pFont">フォントテクスチャポインタ</param>
    /// <param name="scale">表示倍率</param>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Initialize(const Vector2& pos, CTexture* pBase, CTexture* pFont, const Vector2& scale = Vector2(1, 1));

    // ********************************************************************************
    /// <summary>
    /// 描画
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Render(void);

    // ********************************************************************************
    /// <summary>
    /// 解放
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Release(void);

    // ********************************************************************************
    /// <summary>
    /// ボタンの矩形取得
    /// </summary>
    /// <returns>ボタン矩形, もしくはNoneRect</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    CRectangle GetRect(void) const;

    // ********************************************************************************
    /// <summary>
    /// マウスが重なっているかのフラグ取得
    /// </summary>
    /// <returns>true : 重なっている, false : 重なっていない</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool IsMouseOver(void) const;

    // ********************************************************************************
    /// <summary>
    /// ボタンが押された瞬間のフラグ取得
    /// </summary>
    /// <returns>true : 押された瞬間, false : それ以外</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool IsPush(void) const;

    // ********************************************************************************
    /// <summary>
    /// ボタンが押されている間のフラグ取得
    /// </summary>
    /// <returns>true : 押されている, false : 押されていない</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool IsHold(void) const;

    // ********************************************************************************
    /// <summary>
    /// ボタンから離れた瞬間のフラグ取得
    /// </summary>
    /// <returns>true : 離れた瞬間, false : それ以外</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool IsPull(void) const;
};

