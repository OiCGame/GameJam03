#include "Title.h"
#include "Periodic.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="data">共通データ</param>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CTitle::CTitle(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CTitle::~CTitle(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// 初期化
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CTitle::Initialize(void)
{
    // ボタン座標の設定
    Vector2 pos;
    int w = g_pGraphics->GetTargetWidth();
    int h = g_pGraphics->GetTargetHeight();
    pos.x = (w - m_PlateTexture.GetWidth()) * 0.5f;
    pos.y = h * 0.5f;

    // 各ボタンの設定
    m_btnStart.Initialize(pos, &m_PlateTexture, &m_StartTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.1f;
    m_btnOption.Initialize(pos, &m_PlateTexture, &m_OptionTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.1f;
    m_btnEnd.Initialize(pos, &m_PlateTexture, &m_EndTexture);

    // 選択の初期化
    m_SelectNo = 0;

    m_OptionWindow.Initialize(&m_SelectTexture);

    // タイトルに戻ると1ステージから
    GetData().StageNo = 0;
}

// ********************************************************************************
/// <summary>
/// 読み込み
/// </summary>
/// <returns>true : 成功, false : 失敗</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CTitle::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/タイトル画面");
    MofBool b[] =
    {
        m_StartTexture.Load("はじめる.png"),
        m_EndTexture.Load("おわる.png"),
        m_OptionTexture.Load("オプション.png"),
        m_PlateTexture.Load("プレート5.png"),
        m_SelectTexture.Load("選択.png"),
        m_TitleTexture.Load("透明.png"),
        m_GuideTexture.Load("ガイド.png"),
    };
    CUtilities::SetCurrentDirectory("../../");

    for (const auto& it : b)
    {
        if (!it)
        {
            return false;
        }
    }
    m_OptionWindow.Load();

    return true;
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CTitle::Update(void)
{

    // オプションを開いているか否か
    if (m_OptionWindow.IsShow())
    {
        if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
        {
            m_OptionWindow.Hide();
        }
        m_OptionWindow.Update();
    }
    else
    {
        // 選択やつ移動処理
        if (g_pInput->IsKeyPush(MOFKEY_UP))
        {
            m_SelectNo = (m_SelectNo - 1 < 0) ? (2) : (m_SelectNo - 1);
        }
        if (g_pInput->IsKeyPush(MOFKEY_DOWN))
        {
            m_SelectNo = (m_SelectNo + 1 > 2) ? (0) : (m_SelectNo + 1);
        }

        // Enterキーで決定
        if (g_pInput->IsKeyPull(MOFKEY_RETURN))
        {
            switch (m_SelectNo)
            {
            case 0: // 始める
                ChangeScene(SceneName::Game);
                break;
            case 1: // オプション開く
                m_OptionWindow.Show();
                break;
            case 2: // 終わる
                PostQuitMessage(0);
                break;
            default:
                break;
            }
        }
    }
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CTitle::Render(void)
{
    if (m_OptionWindow.IsShow())
    {
        // オプション画面の描画
        m_OptionWindow.Render();
    }
    else
    {
        // タイトルロゴの描画位置計算
        int px = (g_pGraphics->GetTargetWidth() - m_TitleTexture.GetWidth()) * 0.5f;
        int py = g_pGraphics->GetTargetHeight() * 0.5f - m_TitleTexture.GetHeight();

        // タイトルロゴ描画
        m_TitleTexture.Render(px, py);

        // 各ボタン描画
        m_btnStart.Render();
        m_btnOption.Render();
        m_btnEnd.Render();

        // 選択位置の計算
        float th = m_PlateTexture.GetHeight();
        px = m_btnStart.GetRect().Left - (m_SelectTexture.GetWidth() * 1.1f);
        //px = m_SelectMotionX.GetValue();
        py = m_btnStart.GetRect().Top +
            ((th - m_SelectTexture.GetHeight()) * 0.5f) + (th * 1.1f * m_SelectNo);
        
        MofS32 alpha = 255 * sip::CPeriodic::Sine0_1(0.8f);
        MofU32 color = MOF_ALPHA_WHITE(alpha);
        m_SelectTexture.Render(px, py, color);

        // 操作方法の描画
        m_GuideTexture.Render(g_pGraphics->GetTargetWidth() * 0.98f, g_pGraphics->GetTargetHeight() * 0.97f, TEXALIGN_BOTTOMRIGHT);
    }
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CTitle::Release(void)
{
    m_StartTexture.Release();
    m_EndTexture.Release();
    m_OptionTexture.Release();
    m_PlateTexture.Release();
    m_SelectTexture.Release();
    m_TitleTexture.Release();
    m_GuideTexture.Release();

    m_OptionWindow.Save();
    m_OptionWindow.Release();
}
