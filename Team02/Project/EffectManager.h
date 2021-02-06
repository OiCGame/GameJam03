#pragma once
#include "Mof.h"
#include "AnimationData.h"

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g����
/// </summary>
// ********************************************************************************
enum Effect_Name
{
    Effect_Hit,
    Effect_Clear,
    Effect_GameOver,
    Effect_ReadyGo,
    Effect_Count,
};

constexpr int EffectPoolCount = 30;               //! �G�t�F�N�g�v�[���J�E���g

const Vector2 InvalidPos = Vector2(-1.0f, -1.0f); //! �������W�l

// ********************************************************************************
/// <summary>
/// �G�t�F�N�g�Ǘ��N���X
/// </summary>
// ********************************************************************************
class CEffectManager
{
private:

    sip::CAnimationData     m_EffectAnimData[Effect_Count];                //! �G�t�F�N�g�f�[�^�z��

    CSpriteMotionController m_EffectMotion[Effect_Count][EffectPoolCount]; //! ���[�V�����v�[���z��

    Vector2                 m_EffectPos[Effect_Count][EffectPoolCount];    //! ���[�V�����v�[���\�����W

    CTexture                m_EffectTexture[Effect_Count];                 //! �G�t�F�N�g�p�摜

    // ********************************************************************************
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    CEffectManager(void);

public:

    // ********************************************************************************
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    ~CEffectManager(void);
    
    // ********************************************************************************
    /// <summary>
    /// �C���X�^���X�̎擾
    /// </summary>
    /// <returns>�}�l�[�W���[</returns>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    static CEffectManager& GetInstance(void);

    // ********************************************************************************
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    void Load(void);

    // ********************************************************************************
    /// <summary>
    /// �X�V
    /// </summary>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    void Update(void);

    // ********************************************************************************
    /// <summary>
    /// �`��
    /// </summary>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    void Render(void);

    // ********************************************************************************
    /// <summary>
    /// ���
    /// </summary>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    void Release(void);

    // ********************************************************************************
    /// <summary>
    /// �G�t�F�N�g�̊J�n
    /// </summary>
    /// <param name="effect">�Đ�����G�t�F�N�g</param>
    /// <param name="pos">�Đ�������W</param>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    void Start(Effect_Name effect, const Vector2& pos);

    // ********************************************************************************
    /// <summary>
    /// �G�t�F�N�g�̊J�n
    /// </summary>
    /// <param name="effect">�Đ�����G�t�F�N�g</param>
    /// <param name="x">�Đ�����X���W</param>
    /// <param name="y">�Đ�����Y���W</param>
    /// <created>���̂���,2021/02/02</created>
    /// <changed>���̂���,2021/02/02</changed>
    // ********************************************************************************
    void Start(Effect_Name effect, float x, float y);

    // ********************************************************************************
    /// <summary>
    /// ���[�V�����f�[�^�̎擾
    /// </summary>
    /// <param name="effect">���[�V�����̎��</param>
    /// <param name="poolNo">�v�[���ԍ�</param>
    /// <returns>���[�V�����f�[�^</returns>
    /// <created>���̂���,2021/02/06</created>
    /// <changed>���̂���,2021/02/06</changed>
    // ********************************************************************************
    CSpriteMotionController& GetMotion(Effect_Name effect, int poolNo);
};

#define g_EffectManager CEffectManager::GetInstance()