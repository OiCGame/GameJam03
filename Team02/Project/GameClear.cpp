#include "GameClear.h"
#include "GameDefine.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="data">�V�[�����ʃf�[�^</param>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CGameClear::CGameClear(const InitData & data)
    : IScene(data)
{
    Load();
    Initialize();
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
CGameClear::~CGameClear(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// ������
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Initialize(void)
{
    m_SelectNo = (GetData().StageNo == MaxStage - 1) ? 1 : 0;

    const float w = g_pGraphics->GetTargetWidth();
    const float h = g_pGraphics->GetTargetHeight();

    const float tw = (m_PlateTexture.GetWidth() + m_SelectTexture.GetWidth() * 1.1f);
    const float x = (w - tw) * 0.5f + m_SelectTexture.GetWidth() * 1.05f;
    const float y = h * 0.37f;
    Vector2 pos(x, y);
    m_btnNextStage.Initialize(pos, &m_PlateTexture, &m_NextStageTexture);
    pos.y += m_PlateTexture.GetHeight() * 1.07f;
    m_btnGoToTitle.Initialize(pos, &m_PlateTexture, &m_GoToTitleTexture);
}

// ********************************************************************************
/// <summary>
/// �ǂݍ���
/// </summary>
/// <returns>true : ����, false : ���s</returns>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
bool CGameClear::Load(void)
{
    CUtilities::SetCurrentDirectory("UI/�Q�[���N���A");
    MofBool b[] = 
    {
         m_PlateTexture.Load("�v���[�g3.png"),
         m_BackPlateTexture.Load("�v���[�g4.png"),
         m_NextStageTexture.Load("���̃X�e�[�W��.png"),
         m_SelectTexture.Load("�I��.png"),
         m_GoToTitleTexture.Load("�^�C�g����.png"),
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
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Update(void)
{
    // �I����ړ�����
    if ((GetData().StageNo != MaxStage - 1))
    {
        if (g_pInput->IsKeyPush(MOFKEY_UP))
        {
            m_SelectNo = (m_SelectNo == 0) ? (1) : (0);
        }
        if (g_pInput->IsKeyPush(MOFKEY_DOWN))
        {
            m_SelectNo = (m_SelectNo == 1) ? (0) : (1);
        }
    }

    if (g_pInput->IsKeyPush(MOFKEY_RETURN))
    {
        switch (m_SelectNo)
        {
        case 0:
            GetData().StageNo++;
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
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Render(void)
{
    const float w = g_pGraphics->GetTargetWidth();
    const float h = g_pGraphics->GetTargetHeight();
    CRectangle rect(0, 0, w, h);

    Vector2 size(m_BackPlateTexture.GetWidth(), m_BackPlateTexture.GetHeight());
    const float sx = (g_pGraphics->GetTargetWidth() - size.x) * 0.5f;
    const float sy = (g_pGraphics->GetTargetHeight() - size.y) * 0.5f;
    m_BackPlateTexture.Render(sx, sy);

    const float px = m_btnNextStage.GetRect().Left - m_SelectTexture.GetWidth() * 1.05f;
    const float py = m_btnNextStage.GetRect().Top -
        (m_btnNextStage.GetRect().GetHeight() - m_SelectTexture.GetHeight()) * 0.5f +
        m_SelectNo * m_PlateTexture.GetHeight() * 1.07f + m_PlateTexture.GetHeight() * 0.45f;
    m_SelectTexture.Render(px, py);

    if ((GetData().StageNo != MaxStage - 1))
    {
        m_btnNextStage.Render();
    }
    m_btnGoToTitle.Render();
}

// ********************************************************************************
/// <summary>
/// ���
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CGameClear::Release(void)
{
    m_PlateTexture    .Release();
    m_BackPlateTexture.Release();
    m_NextStageTexture.Release();
    m_SelectTexture   .Release();
    m_GoToTitleTexture.Release();
}
