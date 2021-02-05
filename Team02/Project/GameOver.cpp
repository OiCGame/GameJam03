#include "GameOver.h"
#include "Periodic.h"
#include "SoundManager.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="data">�V�[�����ʃf�[�^</param>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CGameOver::CGameOver(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
    g_SoundManager.GetBGM(BGM_Name::BGM_GameOver)->Play();
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CGameOver::~CGameOver(void)
{
    g_SoundManager.GetBGM(BGM_Name::BGM_GameOver)->Stop();
    Release();
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Initialize(void)
{
    m_SelectNo = 0;

    const float w = g_pGraphics->GetTargetWidth();
    const float h = g_pGraphics->GetTargetHeight();

    const float tw = (m_PlateTexture.GetWidth() + m_SelectTexture.GetWidth() * 1.1f);
    const float x = (w - tw) * 0.5f + m_SelectTexture.GetWidth() * 1.05f;
    const float y = h * 0.37f;
    Vector2 pos(x, y);
    m_btnRetry.Initialize(pos, &m_PlateTexture, &m_RetryTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.07f;
    m_btnGoToTitle.Initialize(pos, &m_PlateTexture, &m_GoToTitleTexture);
}

// ********************************************************************************
/// <summary>
/// �ǂݍ���
/// </summary>
/// <returns>true : ����, false : ���s</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CGameOver::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/�Q�[���I�[�o�[");
    MofBool b[] = 
    {
        m_GoToTitleTexture.Load("�^�C�g����.png"),
        m_RetryTexture.Load("���g���C.png"),
        m_PlateTexture.Load("�v���[�g2.png"),
        m_BackPlateTexture.Load("�v���[�g.png"),
        m_SelectTexture.Load("�I��.png"),
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
/// �X�V
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Update(void)
{
    // �I����ړ�����
    if (g_pInput->IsKeyPush(MOFKEY_UP))
    {
        m_SelectNo = (m_SelectNo == 0) ? (1) : (0);
    }
    if (g_pInput->IsKeyPush(MOFKEY_DOWN))
    {
        m_SelectNo = (m_SelectNo == 1) ? (0) : (1);
    }

    if (g_pInput->IsKeyPush(MOFKEY_SPACE))
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
/// �`��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Render(void)
{
    const float w  = g_pGraphics->GetTargetWidth();
    const float h  = g_pGraphics->GetTargetHeight();
    CRectangle rect(0, 0, w, h);

    Vector2 size(m_BackPlateTexture.GetWidth(), m_BackPlateTexture.GetHeight());
    const float sx = (g_pGraphics->GetTargetWidth()  - size.x) * 0.5f;
    const float sy = (g_pGraphics->GetTargetHeight() - size.y) * 0.5f;
    m_BackPlateTexture.Render(sx, sy);

    const float px = m_btnRetry.GetRect().Left - m_SelectTexture.GetWidth() * 1.05f;
    const float py = m_btnRetry.GetRect().Top - 
        (m_btnRetry.GetRect().GetHeight() - m_SelectTexture.GetHeight()) * 0.5f +
        m_SelectNo * m_PlateTexture.GetHeight() * 1.07f + m_PlateTexture.GetHeight() * 0.45f;

    MofS32 alpha = 255 * sip::CPeriodic::Sine0_1(0.8f);
    MofU32 color = MOF_ALPHA_WHITE(alpha);
    m_SelectTexture.Render(px, py, color);

    m_btnRetry.Render();
    m_btnGoToTitle.Render();
}

// ********************************************************************************
/// <summary>
/// ���
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CGameOver::Release(void)
{
    m_GoToTitleTexture.Release();
    m_RetryTexture    .Release();
    m_PlateTexture    .Release();
    m_BackPlateTexture.Release();
    m_SelectTexture   .Release();
}
