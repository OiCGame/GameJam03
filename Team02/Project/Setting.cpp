#include "Setting.h"
#include "RoundRect.h"

// ********************************************************************************
/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <created>���̂���,2021/02/01</created>
/// <changed>���̂���,2021/02/01</changed>
// ********************************************************************************
CSetting::CSetting(void)
    : m_bShow(false)
{
    m_VolumeBarTexture.Load("UI(�R��)/�T�E���hUI/�T�E���hUI �o�[.png");
    m_VolumeButtonTexture.Load("UI(�R��)/�T�E���hUI/�T�E���hUI�@�{�^��.png");
    m_BackTexture.Load("UI(�R��)/�T�E���hUI/�߂�A�C�R��.png");
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
    return true;
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

    // �ݒ��ʂł悭���邤�����D�F�w�i���
    int w = g_pGraphics->GetTargetWidth();
    int h = g_pGraphics->GetTargetHeight();
    CRectangle windowRect( 0, 0, w, h );
    CGraphicsUtilities::RenderFillRect(windowRect, MOF_ALPHA_CBLACK(128));

    // �ݒ��ʂ̃{�[�h
    const float backBoard_r = w * 0.05f;
    sip::CRoundRect backBoard{ windowRect, backBoard_r };
    backBoard.Expansion(-w * 0.05f, -h * 0.05f, 0.0f);
    backBoard.Render(MOF_COLOR_BLACK);
    backBoard.Expansion(-w * 0.01f, -w * 0.01f, -w * 0.01f);
    backBoard.Render(MOF_COLOR_HBLACK);

    // SEVolume

    // BGMVolume

    // �߂�{�^��

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
