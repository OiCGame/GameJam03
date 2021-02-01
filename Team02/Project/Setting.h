#pragma once
#include "Mof.h"
#include "Button.h"

// ********************************************************************************
/// <summary>
/// 設定項目構造体
/// </summary>
// ********************************************************************************
struct Setting
{
    float SE_Volume  = 0.5f;
    float BGM_Volume = 0.5f;
};

// ********************************************************************************
/// <summary>
/// 設定画面クラス
/// </summary>
// ********************************************************************************
class CSetting
{
private:

    bool      m_bShow{ false };       //! 表示フラグ

    Setting   m_SettingData;          //! 設定データ

    CTexture  m_ZeroTexture;          //! 0.png
    CTexture  m_HyakuTexture;         //! 100.png
    CTexture  m_BGMTexture;           //! BGM.png
    CTexture  m_SETexture;            //! SE.png
    CTexture  m_OptionTexture;        //! オプション.png
    CTexture  m_SoundTexture;         //! サウンド.png
    CTexture  m_BackPlateTexture;     //! プレート6.png
    CTexture  m_VolumeButtonTexture;  //! 調整キー.png
    CTexture  m_VolumeBarTexture;     //! 調整バー.png
    CTexture  m_BackTexture;          //! 戻る.png
    CTexture* m_pSelectTexture;       //! 選択画像ポインタ

    CButton   m_BtnBack;              //! 戻るボタン

    int       m_SelectNo;             //! 選択番号 0:戻る 1:BGM 2:SE

    float     m_BGMPosX;              //! BGMボリュームのつまみ位置
    float     m_SEPosX;               //! SEボリュームのつまみ位置

public:

    // ********************************************************************************
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    CSetting(void);

    // ********************************************************************************
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    ~CSetting(void);

    // ********************************************************************************
    /// <summary>
    /// 設定データの保存
    /// </summary>
    /// <returns>true : 成功, false : 失敗</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool Save(void);

    // ********************************************************************************
    /// <summary>
    /// 設定データの読み込み
    /// </summary>
    /// <returns>true : 成功, false : 失敗</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool Load(void);

    // ********************************************************************************
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name="pSelectTex">選択画像ポインタ</param>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Initialize(CTexture* pSelectTex);

    // ********************************************************************************
    /// <summary>
    /// 表示
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Show(void);

    // ********************************************************************************
    /// <summary>
    /// 非表示
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Hide(void);

    // ********************************************************************************
    /// <summary>
    /// 更新
    /// </summary>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    void Update(void);

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
    /// 表示フラグの取得
    /// </summary>
    /// <returns>true : 表示, false : 非表示</returns>
    /// <created>いのうえ,2021/02/01</created>
    /// <changed>いのうえ,2021/02/01</changed>
    // ********************************************************************************
    bool IsShow(void) const;
};

