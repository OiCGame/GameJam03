#include "GameClear.h"

// ********************************************************************************
/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="data">シーン共通データ</param>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CGameClear::CGameClear(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
}

// ********************************************************************************
/// <summary>
/// デストラクタ
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
CGameClear::~CGameClear(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// 初期化
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Initialize(void)
{
    m_SelectNo = 0;

    const float w = g_pGraphics->GetTargetWidth();
    const float h = g_pGraphics->GetTargetHeight();

    const float tw = (m_PlateTexture.GetWidth() + m_SelectTexture.GetWidth() * 1.1f);
    const float x = (w - tw) * 0.5f + m_SelectTexture.GetWidth() * 1.1f;
    const float y = h * 0.45f;
    Vector2 pos(x, y);
    const Vector2 scale(0.8f, 0.8f);
    m_btnNextStage.Initialize(pos, &m_PlateTexture, &m_NextStageTexture, scale);
    pos.y += m_PlateTexture.GetHeight() * 1.1f * scale.y;
    m_btnGoToTitle.Initialize(pos, &m_PlateTexture, &m_GoToTitleTexture, scale);
}

// ********************************************************************************
/// <summary>
/// 読み込み
/// </summary>
/// <returns>true : 成功, false : 失敗</returns>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
bool CGameClear::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/ゲームクリア");
    MofBool b[] = 
    {
         m_PlateTexture.Load("プレート3.png"),
         m_BackPlateTexture.Load("プレート4.png"),
         m_NextStageTexture.Load("次のステージへ.png"),
         m_ClearTexture.Load("文字.png"),
         m_SelectTexture.Load("選択.png"),
         m_GoToTitleTexture.Load("タイトルへ.png"),
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
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Update(void)
{
    // 選択やつ移動処理
    if (g_pInput->IsKeyPush(MOFKEY_UP))
    {
        m_SelectNo = (m_SelectNo == 0) ? (1) : (0);
    }
    if (g_pInput->IsKeyPush(MOFKEY_DOWN))
    {
        m_SelectNo = (m_SelectNo == 1) ? (0) : (1);
    }

    if (g_pInput->IsKeyPush(MOFKEY_RETURN))
    {
        switch (m_SelectNo)
        {
        case 0:
            ChangeScene(SceneName::Game);
            break;
        case 1:
            ChangeScene(SceneName::Title);
            break;
        }
    }
}

// ********************************************************************************
/// <summary>
/// 描画
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Render(void)
{
    const float w = g_pGraphics->GetTargetWidth();
    const float h = g_pGraphics->GetTargetHeight();
    CRectangle rect(0, 0, w, h);
    CGraphicsUtilities::RenderFillRect(rect, MOF_COLOR_CWHITE);

    Vector2 size(m_BackPlateTexture.GetWidth(), m_BackPlateTexture.GetHeight());
    const float sx = g_pGraphics->GetTargetWidth() / size.x;
    const float sy = g_pGraphics->GetTargetHeight() / size.y;
    m_BackPlateTexture.RenderScale(0, 0, sx, sy);

    m_ClearTexture.Render((w - m_ClearTexture.GetWidth()) * 0.5f, h * 0.2f);

    const Vector2 scale(0.8f, 0.8f);
    const float px = m_btnNextStage.GetRect().Left - m_SelectTexture.GetWidth() * 1.1f;
    const float py = m_btnNextStage.GetRect().Top -
        (m_btnNextStage.GetRect().GetHeight() - m_SelectTexture.GetHeight()) * 0.5f +
        m_SelectNo * m_PlateTexture.GetHeight() * 1.1f * scale.y;
    m_SelectTexture.Render(px, py);

    m_btnNextStage.Render();
    m_btnGoToTitle.Render();
}

// ********************************************************************************
/// <summary>
/// 解放
/// </summary>
/// <created>いのうえ,2021/02/02</created>
/// <changed>いのうえ,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Release(void)
{
    m_PlateTexture    .Release();
    m_BackPlateTexture.Release();
    m_NextStageTexture.Release();
    m_ClearTexture    .Release();
    m_SelectTexture   .Release();
    m_GoToTitleTexture.Release();
}
