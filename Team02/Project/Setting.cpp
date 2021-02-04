#include "Setting.h"
#include "RoundRect.h"
#include "SoundManager.h"
#include "Periodic.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CSetting::CSetting(void)
    : m_bShow(false)
    , m_SelectNo(1)
{
}

// ********************************************************************************
/// <summary>
/// �f�X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CSetting::~CSetting(void)
{
    Release();
}

// ********************************************************************************
/// <summary>
/// �ݒ�f�[�^�̕ۑ�
/// </summary>
/// <returns>true : ����, false : ���s</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CSetting::Save(void)
{
    // �t�@�C���������J����
    FILE* fp = fopen("Setting.config", "wb");

    // �t�@�C���I�[�v�����s
    if (fp == NULL)
    {
        return false;
    }

    // �ݒ�f�[�^�����̂܂܃o�C�i���ŏ����o��
    fwrite(&m_SettingData, 1, sizeof(m_SettingData), fp);

    // �J�����炵�߂悤�z�g�g�M�X
    fclose(fp);
    return true;
}

// ********************************************************************************
/// <summary>
/// �ݒ�f�[�^�̓ǂݍ���
/// </summary>
/// <returns>true : ����, false : ���s</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CSetting::Load(void)
{
    // �t�@�C���������J����
    FILE* fp = fopen("Setting.config", "rb");

    // �t�@�C���I�[�v�����s
    if (fp == NULL)
    {
        return false;
    }

    // �ݒ�f�[�^�����̂܂܃o�C�i���œǂݍ���
    fread(&m_SettingData, 1, sizeof(m_SettingData), fp);

    // �J�����炵�߂悤�z�g�g�M�X
    fclose(fp);

    SetVolume();

    CUtilities::SetCurrentDirectory("UI/�I�v�V�������");

    MofBool b[] =
    {
        m_ZeroTexture.Load("0.png"),
        m_HyakuTexture.Load("100.png"),
        m_BGMTexture.Load("BGM.png"),
        m_SETexture.Load("SE.png"),
        m_OptionTexture.Load("�I�v�V����.png"),
        m_SoundTexture.Load("�T�E���h.png"),
        m_BackPlateTexture.Load("�v���[�g6.png"),
        m_VolumeButtonTexture.Load("�����L�[.png"),
        m_VolumeBarTexture.Load("�����o�[.png"),
        m_BackTexture.Load("�߂�.png"),
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
/// ������
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CSetting::Initialize(CTexture* pSelectTex)
{
    // �߂�{�^���̈ʒu����
    float w = g_pGraphics->GetTargetWidth();
    float h = g_pGraphics->GetTargetHeight();
    float x = (w + m_BackPlateTexture.GetWidth() ) * 0.5f - m_BackTexture.GetWidth()  * 1.3f;
    float y = (h - m_BackPlateTexture.GetHeight()) * 0.5f + m_BackTexture.GetHeight() * 0.8f;
    m_BtnBack.Initialize(Vector2(x, y), nullptr, &m_BackTexture);

    m_pSelectTexture = pSelectTex;

    m_SelectNo = 1;

    const float BGMPosX   = 685.199951f + m_VolumeBarTexture.GetWidth() * 0.05f;
    const float SEPosX    = BGMPosX;
    const float MoveValue = m_VolumeBarTexture.GetWidth() * 0.9f / 100.0f;
    m_BGMPosX = BGMPosX + MoveValue * m_SettingData.BGM_Volume * 100.0f;
    m_SEPosX  = SEPosX  + MoveValue * m_SettingData.SE_Volume  * 100.0f;
}

// ********************************************************************************
/// <summary>
/// �\��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CSetting::Show(void)
{
    m_bShow = true;
    m_SelectNo = 1;
}

// ********************************************************************************
/// <summary>
/// ��\��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CSetting::Hide(void)
{
    m_bShow = false;
}

// ********************************************************************************
/// <summary>
/// �X�V
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CSetting::Update(void)
{
    // �\���t���O���܂�Ă���ꍇ�X�V���Ȃ�
    if (!m_bShow)
    {
        return;
    }

    // �I����ړ�����
    if (g_pInput->IsKeyPush(MOFKEY_UP))
    {
        m_SelectNo = (m_SelectNo - 1 < 0) ? (2) : (m_SelectNo - 1);
    }
    if (g_pInput->IsKeyPush(MOFKEY_DOWN))
    {
        m_SelectNo = (m_SelectNo + 1 > 2) ? (0) : (m_SelectNo + 1);
    }

    // �߂�I�𒆂ɃG���^�[�Ŗ߂�
    if (m_SelectNo == 0 && g_pInput->IsKeyPull(MOFKEY_RETURN))
    {
        Hide();
    }

    const float BGMPosX  = 685.199951f + m_VolumeBarTexture.GetWidth() * 0.05f;
    const float SEPosX   = BGMPosX;
    const float BGMPosY  = 545.340027 + m_VolumeBarTexture.GetHeight() * 0.5f;
    const float SEPosY   = 710.340027 + m_VolumeBarTexture.GetHeight() * 0.5f;
    const float Circle_r = m_VolumeButtonTexture.GetHeight() * 0.5f;

    CCircle BGMCircle(m_BGMPosX, BGMPosY, Circle_r);
    CCircle SECircle(m_SEPosX, SEPosY, Circle_r);
    
    const  float MoveValue   = m_VolumeBarTexture.GetWidth() * 0.9f / 100.0f;
    static float sFlameCount = 0;       //! �t���[���J�E���^
    int          moveDir     = 0;       //! 0:�����Ă��Ȃ� 1:�� 2:�E
    float*       pMovePos    = nullptr; //! �ړ�������W�l

    // ���ʒ��ߗp�X�C�b�`��
    switch (m_SelectNo)
    {
    case 1: // BGM�I����
        pMovePos = &m_BGMPosX;
        break;
    case 2: // SE�I����
        pMovePos = &m_SEPosX;
        break;
    default: // ����ȊO
        pMovePos    = nullptr;
        sFlameCount = 0;
        break;
    }

    // ���E���L�[�ł܂݂̈ړ����������߂Ă��
    if (pMovePos)
    {
        if (g_pInput->IsKeyHold(MOFKEY_LEFT))
        {
            sFlameCount++;
            moveDir = 1;
        }
        else if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
        {
            sFlameCount++;
            moveDir = 2;
        }
        else
        {
            sFlameCount = 0;
        }
    }
    // �ړ��ʂ����������Ă��
    if ((sFlameCount == 1 || sFlameCount > 10))
    {
        if (moveDir == 1)
        {
            (*pMovePos) -= MoveValue;
            (*pMovePos) = MOF_CLIPING((*pMovePos), BGMPosX, BGMPosX + MoveValue * 100.0f);
        }
        if (moveDir == 2)
        {
            (*pMovePos) += MoveValue;
            (*pMovePos) = MOF_CLIPING((*pMovePos), BGMPosX, BGMPosX + MoveValue * 100.0f);
        }
        switch (m_SelectNo)
        {
        case 1:
            m_SettingData.BGM_Volume = ((*pMovePos) - BGMPosX) / MoveValue * 0.01f;
            break;
        case 2:
            m_SettingData.SE_Volume  = ((*pMovePos) - BGMPosX) / MoveValue * 0.01f;
            break;
        default:
            break;
        }
        SetVolume();
    }
}

// ********************************************************************************
/// <summary>
/// �`��
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CSetting::Render(void)
{
    // �\���t���O���܂�Ă���ꍇ�`�悵�Ȃ�
    if (!m_bShow)
    {
        return;
    }

    // �`��ʒu�v�Z�p
    float w = g_pGraphics->GetTargetWidth();
    float h = g_pGraphics->GetTargetHeight();
    Vector2 pos;

    // ��ʒ������낦
    pos.x = (w - m_BackPlateTexture.GetWidth() ) * 0.5f;
    pos.y = (h - m_BackPlateTexture.GetHeight()) * 0.5f;
    m_BackPlateTexture.Render(pos.x, pos.y);

    pos.x += m_OptionTexture.GetHeight() * 0.2f;
    pos.y += m_OptionTexture.GetHeight() * 0.1f;
    m_OptionTexture.Render(pos.x, pos.y);

    pos.x += m_OptionTexture.GetHeight() * 0.1f;
    pos.y += m_OptionTexture.GetHeight() * 1.01f;
    m_SoundTexture.Render(pos.x, pos.y);

    const float OffsetVolumeH = (m_VolumeBarTexture.GetHeight() + m_HyakuTexture.GetHeight()) * 1.2f;
    pos.x += m_pSelectTexture->GetWidth() * 0.7f;
    pos.y += OffsetVolumeH;
    m_BGMTexture.Render(pos.x, pos.y);
    const float BGMPosX = pos.x;
    const float BGMPosY = pos.y;

    pos.y += OffsetVolumeH;
    m_SETexture.Render(pos.x, pos.y);

    // BGMVolume
    const float Circle_r = m_VolumeBarTexture.GetHeight() * 0.5f;
    pos.x += m_BGMTexture.GetWidth();
    pos.y = BGMPosY + (m_BGMTexture.GetHeight() - m_VolumeBarTexture.GetHeight()) * 0.5f;
    pos.y -= m_ZeroTexture.GetHeight();
    m_ZeroTexture.Render(pos.x + m_ZeroTexture.GetWidth() * 0.5f, pos.y);
    m_HyakuTexture.Render(pos.x + m_VolumeBarTexture.GetWidth() - m_HyakuTexture.GetWidth(), pos.y);
    pos.y += m_ZeroTexture.GetHeight();
    m_VolumeBarTexture.Render(pos.x, pos.y);
    m_VolumeButtonTexture.Render(m_BGMPosX, pos.y + Circle_r, TEXALIGN_CENTERCENTER);

    // SEVolume
    pos.y += OffsetVolumeH - m_ZeroTexture.GetHeight();
    m_ZeroTexture.Render(pos.x + m_ZeroTexture.GetWidth() * 0.5f, pos.y);
    m_HyakuTexture.Render(pos.x + m_VolumeBarTexture.GetWidth() - m_HyakuTexture.GetWidth(), pos.y);
    pos.y += m_ZeroTexture.GetHeight();
    m_VolumeBarTexture.Render(pos.x, pos.y);
    m_VolumeButtonTexture.Render(m_SEPosX, pos.y + Circle_r, TEXALIGN_CENTERCENTER);

    // �߂�{�^��
    m_BtnBack.Render();

    // �I���{�^���̈ʒu
    const float tw = m_pSelectTexture->GetWidth();
    const float th = m_pSelectTexture->GetHeight();
    switch (m_SelectNo)
    {
    case 0:
        pos.x = m_BtnBack.GetRect().Left - tw * 1.1f;
        pos.y = m_BtnBack.GetRect().Top  + (m_BtnBack.GetRect().GetHeight() - th) * 0.5f;
        break;
    case 1:
        pos.x = BGMPosX - tw * 1.1f;
        pos.y = BGMPosY + (m_BGMTexture.GetHeight() - th) * 0.5f;
        break;
    case 2:
        pos.x = BGMPosX - tw * 1.1f;
        pos.y = BGMPosY + (m_BGMTexture.GetHeight() - th) * 0.5f + OffsetVolumeH;
        break;
    default:
        break;
    }
    MofS32 alpha = 255 * sip::CPeriodic::Sine0_1(0.8f);
    MofU32 color = MOF_ALPHA_WHITE(alpha);
    m_pSelectTexture->Render(pos.x, pos.y, color);
}

// ********************************************************************************
/// <summary>
/// ���
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
void CSetting::Release(void)
{
    m_ZeroTexture.Release();
    m_HyakuTexture.Release();
    m_BGMTexture.Release();
    m_SETexture.Release();
    m_OptionTexture.Release();
    m_SoundTexture.Release();
    m_BackPlateTexture.Release();
    m_VolumeButtonTexture.Release();
    m_VolumeBarTexture.Release();
    m_BackTexture.Release();
}

// ********************************************************************************
/// <summary>
/// �\���t���O�̎擾
/// </summary>
/// <returns>true : �\��, false : ��\��</returns>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
bool CSetting::IsShow(void) const
{
    return m_bShow;
}

// ********************************************************************************
/// <summary>
/// �{�����[���̐ݒ�
/// </summary>
/// <created>���̂���,2021/02/02</created>
/// <changed>���̂���,2021/02/02</changed>
// ********************************************************************************
void CSetting::SetVolume(void)
{
    for (int i = 0; i < BGM_Count; i++)
    {
        g_SoundManager.GetBGM((BGM_Name)i)->SetVolume(m_SettingData.BGM_Volume);
    }

    for (int i = 0; i < SE_Count; i++)
    {
        for (int j = 0; j < SoundPoolCount; j++)
        {
            g_SoundManager.GetSE((SE_Name)i, j)->SetVolume(m_SettingData.SE_Volume);
        }
    }
}
