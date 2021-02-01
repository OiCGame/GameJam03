#include "Title.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="data">���ʃf�[�^</param>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CTitle::CTitle(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CTitle::~CTitle(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CTitle::Initialize(void)
{
    // �{�^�����W�̐ݒ�
    Vector2 pos;
    int w = g_pGraphics->GetTargetWidth();
    int h = g_pGraphics->GetTargetHeight();
    pos.x = (w - m_PlateTexture.GetWidth()) * 0.5f;
    pos.y = h * 0.5f;

    // �e�{�^���̐ݒ�
    m_btnStart.Initialize(pos, &m_PlateTexture, &m_StartTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.1f;
    m_btnOption.Initialize(pos, &m_PlateTexture, &m_OptionTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.1f;
    m_btnEnd.Initialize(pos, &m_PlateTexture, &m_EndTexture);

    // �I���̏�����
    m_SelectNo = 0;
}

// ********************************************************************************
/// <summary>
/// �ǂݍ���
/// </summary>
/// <returns>true : ����, false : ���s</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CTitle::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/�^�C�g�����");
    bool b[] =
    {
        m_StartTexture.Load("�͂��߂�.png"),
        m_EndTexture.Load("�����.png"),
        m_OptionTexture.Load("�I�v�V����.png"),
        m_PlateTexture.Load("�v���[�g5.png"),
        m_SelectTexture.Load("�I��.png"),
        m_TitleTexture.Load("����.png"),
        m_BackTexture.Load("�w�i.png"),
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
void CTitle::Update(void)
{
    // �I�v�V�������J���Ă��邩�ۂ�
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
        if (g_pInput->IsKeyPush(MOFKEY_ESCAPE))
        {
            PostQuitMessage(0);
        }
        if (g_pInput->IsKeyPush(MOFKEY_UP))
        {
            m_SelectNo = (m_SelectNo - 1 < 0) ? (2) : (m_SelectNo - 1);
        }
        if (g_pInput->IsKeyPush(MOFKEY_DOWN))
        {
            m_SelectNo = (m_SelectNo + 1 > 2) ? (0) : (m_SelectNo + 1);
        }

        if (g_pInput->IsKeyPull(MOFKEY_RETURN))
        {
            switch (m_SelectNo)
            {
            case 0: // �n�߂�
                ChangeScene(SceneName::Game);
                break;
            case 1: // �I�v�V�����J��
                m_OptionWindow.Show();
                break;
            case 2: // �I���
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
/// �`��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CTitle::Render(void)
{
    // �w�i�̕`��
    m_BackTexture.Render(0, 0);

    // �^�C�g�����S�̕`��ʒu�v�Z
    int px = (g_pGraphics->GetTargetWidth() - m_TitleTexture.GetWidth()) * 0.5f;
    int py = g_pGraphics->GetTargetHeight() * 0.5f - m_TitleTexture.GetHeight();

    // �^�C�g�����S�`��
    m_TitleTexture.Render(px, py);

    // �e�{�^���`��
    m_btnStart.Render();
    m_btnOption.Render();
    m_btnEnd.Render();

    // �I���ʒu�̌v�Z
    float th = m_PlateTexture.GetHeight();
    px = m_btnStart.GetRect().Left - (m_SelectTexture.GetWidth() * 1.1f);
    py = m_btnStart.GetRect().Top + 
        ((th - m_SelectTexture.GetHeight()) * 0.5f) + (th * 1.1f * m_SelectNo);
    m_SelectTexture.Render(px, py);

    // �I�v�V������ʂ̕`��
    m_OptionWindow.Render();
}

// ********************************************************************************
/// <summary>
/// ���
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CTitle::Release(void)
{
    m_StartTexture.Release();
    m_EndTexture.Release();
    m_OptionTexture.Release();
    m_PlateTexture.Release();
    m_SelectTexture.Release();
    m_TitleTexture.Release();
    m_BackTexture.Release();
}
