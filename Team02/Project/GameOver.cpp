#include "GameOver.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="data">シーン共通データ</param>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
CGameOver::CGameOver(const InitData & data)
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
CGameOver::~CGameOver(void)
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
void CGameOver::Initialize(void)
{
    m_SelectNo = 0;

    const float w = g_pGraphics->GetTargetWidth();
    const float h = g_pGraphics->GetTargetHeight();

    float x = (w - (m_PlateTexture.GetWidth() + m_SelectTexture.GetWidth())) * 0.5f;
    float y = h * 0.51f;
    Vector2 pos(x, y);
    m_btnRetry.Initialize(pos, &m_PlateTexture, &m_RetryTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.2f;
    m_btnGoToTitle.Initialize(pos, &m_PlateTexture, &m_GoToTitleTexture);
}

// ********************************************************************************
/// <summary>
/// 読み込み
/// </summary>
/// <returns>true : 成功, false : 失敗</returns>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
bool CGameOver::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/ゲームオーバー");
    MofBool b[] = 
    {
        m_GoToTitleTexture.Load("タイトルへ.png"),
        m_RetryTexture.Load("リトライ.png"),
        m_PlateTexture.Load("プレート2.png"),
        m_BackPlateTexture.Load("プレート.png"),
        m_GameOverTexture.Load("文字.png"),
        m_SelectTexture.Load("選択.png"),
    };
    CUtilities::SetCurrentDirectory("../../");

    for (const auto& it : b)
    {
        if (!it)
        {
            return false;
        }
    }
    return true;
}

// ********************************************************************************
/// <summary>
/// 更新
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Update(void)
{
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Render(void)
{
    const float w  = g_pGraphics->GetTargetWidth();
    const float h  = g_pGraphics->GetTargetHeight();
    CRectangle rect(0, 0, w, h);
    CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_CWHITE);

    Vector2 size(m_BackPlateTexture.GetWidth(), m_BackPlateTexture.GetHeight());
    const float sx = g_pGraphics->GetTargetWidth()  / size.x;
    const float sy = g_pGraphics->GetTargetHeight() / size.y;
    m_BackPlateTexture.RenderScale(0, 0, sx, sy);

    m_GameOverTexture.Render((w - m_GameOverTexture.GetWidth()) * 0.5f, h * 0.2f);

    m_btnRetry.Render();
    m_btnGoToTitle.Render();
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/01</created>
/// <changed>いのうえ,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Release(void)
{
    m_GoToTitleTexture.Release();
    m_RetryTexture    .Release();
    m_PlateTexture    .Release();
    m_BackPlateTexture.Release();
    m_GameOverTexture .Release();
    m_SelectTexture   .Release();
}
