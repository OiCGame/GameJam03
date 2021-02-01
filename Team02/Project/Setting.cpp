#include "Setting.h"
#include "RoundRect.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CSetting::CSetting(void)
    : m_bShow(false)
{
    m_VolumeBarTexture.Load("UI(山岡)/サウンドUI/サウンドUI バー.png");
    m_VolumeButtonTexture.Load("UI(山岡)/サウンドUI/サウンドUI　ボタン.png");
    m_BackTexture.Load("UI(山岡)/サウンドUI/戻るアイコン.png");
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CSetting::~CSetting(void)
{
}

// ********************************************************************************
/// <summary>
/// 設定データの保存
/// </summary>
/// <returns>true : 成功, false : 失敗</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CSetting::Save(void)
{
    // ファイルをこじ開ける
    FILE* fp = fopen("Setting.config", "wb");

    // ファイルオープン失敗
    if (fp == NULL)
    {
        return false;
    }

    // 設定データをそのままバイナリで書き出し
    fwrite(&m_SettingData, 1, sizeof(m_SettingData), fp);

    // 開けたらしめようホトトギス
    fclose(fp);
    return true;
}

// ********************************************************************************
/// <summary>
/// 設定データの読み込み
/// </summary>
/// <returns>true : 成功, false : 失敗</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CSetting::Load(void)
{
    // ファイルをこじ開ける
    FILE* fp = fopen("Setting.config", "rb");

    // ファイルオープン失敗
    if (fp == NULL)
    {
        return false;
    }

    // 設定データをそのままバイナリで読み込み
    fread(&m_SettingData, 1, sizeof(m_SettingData), fp);

    // 開けたらしめようホトトギス
    fclose(fp);
    return true;
}

// ********************************************************************************
/// <summary>
/// 表示
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CSetting::Show(void)
{
    m_bShow = true;
}

// ********************************************************************************
/// <summary>
/// 非表示
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CSetting::Hide(void)
{
    m_bShow = false;
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CSetting::Update(void)
{
    // 表示フラグが折れている場合更新しない
    if (!m_bShow)
    {
        return;
    }
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CSetting::Render(void)
{
    // 表示フラグが折れている場合描画しない
    if (!m_bShow)
    {
        return;
    }

    // 設定画面でよくあるうすい灰色背景やつ
    int w = g_pGraphics->GetTargetWidth();
    int h = g_pGraphics->GetTargetHeight();
    CRectangle windowRect( 0, 0, w, h );
    CGraphicsUtilities::RenderFillRect(windowRect, MOF_ALPHA_CBLACK(128));

    // 設定画面のボード
    const float backBoard_r = w * 0.05f;
    sip::CRoundRect backBoard{ windowRect, backBoard_r };
    backBoard.Expansion(-w * 0.05f, -h * 0.05f, 0.0f);
    backBoard.Render(MOF_COLOR_BLACK);
    backBoard.Expansion(-w * 0.01f, -w * 0.01f, -w * 0.01f);
    backBoard.Render(MOF_COLOR_HBLACK);

    // SEVolume

    // BGMVolume

    // 戻るボタン

}

// ********************************************************************************
/// <summary>
/// 表示フラグの取得
/// </summary>
/// <returns>true : 表示, false : 非表示</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CSetting::IsShow(void) const
{
    return m_bShow;
}
