#pragma once
#include "Mof.h"
#include <unordered_map>
#include "StopWatch.h"

// �Q�l SceneManager.hpp in OpenSiv3D ver4.3.0

namespace sip
{
	// �v���g�^�C�v�錾
	template <class State, class Data> class CSceneManager;

	struct EmptyData {};

	// ********************************************************************************
	/// <summary>
	/// �V�[���E�C���^�[�t�F�[�X
	/// </summary>
	// ********************************************************************************
	template<class State, class Data>
	class IScene
	{
	public:

		// ********************************************************************************
		/// <summary>
		/// �������f�[�^
		/// </summary>
		// ********************************************************************************
		struct InitData
		{
			State                       state;    //! �X�e�[�g

			std::shared_ptr<Data>       pData;    //! ���ʃf�[�^�|�C���^

			CSceneManager<State, Data>* pManager; //! �V�[���}�l�[�W���|�C���^

			// ********************************************************************************
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <created>���̂���,2020/11/11</created>
			/// <changed>���̂���,2020/11/11</changed>
			// ********************************************************************************
			InitData(void) = default;

			// ********************************************************************************
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			/// <param name="s">�X�e�[�g</param>
			/// <param name="d">���ʃf�[�^�̃|�C���^</param>
			/// <param name="m">�}�l�[�W���̃|�C���^</param>
			/// <created>���̂���,2020/11/11</created>
			/// <changed>���̂���,2020/11/11</changed>
			// ********************************************************************************
			InitData(const State& s, std::shared_ptr<Data>& d, CSceneManager<State, Data>* m) :
				state(s),
				pData(d),
				pManager(m) {}
		};

	private:

		State                           m_State;     //! �X�e�[�g

		std::shared_ptr<Data>           m_pData;     //! ���ʃf�[�^�|�C���^

		CSceneManager<State, Data>*     m_pManager;  //! �}�l�[�W���|�C���^

	public:

		// ********************************************************************************
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		/// <param name="init">�������f�[�^</param>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		explicit IScene(const InitData& init)
			: m_State(init.state)
			, m_pData(init.pData)
			, m_pManager(init.pManager)
		{
		}

		// ********************************************************************************
		/// <summary>
		/// �f�X�g���N�^
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual ~IScene(void) = default;

		// ********************************************************************************
		/// <summary>
		/// �t�F�[�h�C�����̍X�V
		/// </summary>
		/// <param name="float">�t�F�[�h�C������</param>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual void UpdateFadeIn(float) {}

		// ********************************************************************************
		/// <summary>
		/// �ʏ펞�̍X�V
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual void Update(void) {}

		// ********************************************************************************
		/// <summary>
		/// �t�F�[�h�A�E�g���̍X�V
		/// </summary>
		/// <param name="float">�t�F�[�h�A�E�g����</param>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual void UpdateFadeOut(float) {}

		// ********************************************************************************
		/// <summary>
		/// �ʏ펞�̕`��
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual void Render(void) {}

		// ********************************************************************************
		/// <summary>
		/// �t�F�[�h�C�����̕`��
		/// </summary>
		/// <param name="t">�t�F�[�h�C������</param>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual void RenderFadeIn(float t) 
		{
			Render();

			MofU32 color     = m_pManager->GetFadeColor();

			MofU8  alpha     = (1.0f - t) * 255;

			MofU32 fadeColor = MOF_ARGB(alpha, MOF_GetRed(color), MOF_GetGreen(color), MOF_GetBlue(color));

			CGraphicsUtilities::RenderFillRect(
				0, 0,
				g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),
				fadeColor
			);
		}

		// ********************************************************************************
		/// <summary>
		/// �t�F�[�h�A�E�g���̕`��
		/// </summary>
		/// <param name="t">�t�F�[�h�A�E�g����</param>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		virtual void RenderFadeOut(float t)
		{
			Render();

			MofU32 color     = m_pManager->GetFadeColor();

			MofU8  alpha     = t * 255;

			MofU32 fadeColor = MOF_ARGB(alpha, MOF_GetRed(color), MOF_GetGreen(color), MOF_GetBlue(color));

			CGraphicsUtilities::RenderFillRect(
				0, 0,
				g_pGraphics->GetTargetWidth(), g_pGraphics->GetTargetHeight(),
				fadeColor
			);
		}

	protected:

		// ********************************************************************************
		/// <summary>
		/// �X�e�[�g�̎擾
		/// </summary>
		/// <returns>�X�e�[�g</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		const State& GetState(void) const
		{
			return m_State;
		}

		// ********************************************************************************
		/// <summary>
		/// ���L�f�[�^�ւ̎Q�Ƃ��擾
		/// </summary>
		/// <returns>���L�f�[�^</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		Data& GetData(void) const
		{
			return *m_pData;
		}

		// ********************************************************************************
		/// <summary>
		/// �V�[���̕ύX��ʒm����B
		/// </summary>
		/// <param name="state">���̃V�[���̃L�[</param>
		/// <param name="transitionTime">�t�F�[�h�C���E�A�E�g�̎���(�P��:�b)</param>
		/// <returns>�V�[���̕ύX���\�Ńt�F�[�h�C���E�A�E�g���J�n�����ꍇ true, ����ȊO false</returns>
		/// <created>���̂���,2020/05/22</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool ChangeScene(const State& state, const float& transitionTime = 1.0f)
		{
			return m_pManager->ChangeScene(state, transitionTime);
		}

		// ********************************************************************************
		/// <summary>
		/// �G���[�̔�����ʒm����B
		/// ���̊֐����ĂԂƁA�ȍ~�� CSceneManager::Update() / CSceneManager::Render() �� false ��Ԃ��B
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		void NotifyError(void)
		{
			return m_pManager->NotifyError();
		}
	};

	// ********************************************************************************
	/// <summary>
	/// �V�[���Ǘ�
	/// State : �V�[������ʂ���L�[�̌^
	/// Data  : �V�[���Ԃŋ��L����f�[�^�̌^
	/// </summary>
	// ********************************************************************************
	template<class State, class Data = EmptyData>
	class CSceneManager
	{
	private:

		using Scene_t = std::shared_ptr<IScene<State, Data>>;

		using FactoryFunction_t = std::function<Scene_t()>;

		std::unordered_map<State, FactoryFunction_t> m_Factories;                   //! �e�X�e�[�g���̃t�@�N�g��

		std::shared_ptr<Data>                        m_pData;                       //! ���ʃf�[�^�|�C���^

		Scene_t                                      m_pCurrent;                    //! ���݂̃V�[��

		Scene_t                                      m_pNext;                       //! ���̃V�[��

		State                                        m_CurrentState;                //! ���݂̃X�e�[�g

		State                                        m_NextState;                   //! ���̃X�e�[�g
		
		std::shared_ptr<State>                       m_pFirst;                      //! �ŏ��̃X�e�[�g

		// ********************************************************************************
		/// <summary>
		/// �V�[���̑J�ڗ�
		/// </summary>
		// ********************************************************************************
		enum class TransitionState
		{
			None,      //! �Ȃ�

			FadeIn,    //! �t�F�[�h�C��

			Active,    //! �A�N�e�B�u

			FadeOut,   //! �t�F�[�h�A�E�g

		} m_TransitionState = TransitionState::None;                                //! �V�[���̑J�ڏ��

		CStopWatch                                   m_StopWatch;                   //! �X�g�b�v�E�H�b�`

		float                                        m_TransitionTime = 1.0f;       //! �J�ڎ���(�b)

		MofU32                                       m_FadeColor = MOF_COLOR_BLACK; //! �t�F�[�h�F

		bool                                         m_bError = false;              //! �G���[�t���O

		// ********************************************************************************
		/// <summary>
		/// �V�[���P�̍X�V
		/// </summary>
		/// <returns>true : ����, false : ���s</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool UpdateSingle(void)
		{
			m_StopWatch.Update();

			float elapsed = m_StopWatch.GetTime();

			if (m_TransitionState == TransitionState::FadeOut && elapsed >= m_TransitionTime)
			{
				m_pCurrent = nullptr;

				m_pCurrent = m_Factories[m_NextState]();

				if (IsError())
				{
					return false;
				}

				m_CurrentState = m_NextState;

				m_TransitionState = TransitionState::FadeIn;

				m_StopWatch.Reset();

				elapsed = 0.0f;
			}

			if (m_TransitionState == TransitionState::FadeIn && elapsed >= m_TransitionTime)
			{
				m_StopWatch.Reset();

				m_TransitionState = TransitionState::Active;
			}

			switch (m_TransitionState)
			{
			case TransitionState::FadeIn:
				assert(m_TransitionTime);
				m_pCurrent->UpdateFadeIn(elapsed / m_TransitionTime);
				return !IsError();
			case TransitionState::Active:
				m_pCurrent->Update();
				return !IsError();
			case TransitionState::FadeOut:
				assert(m_TransitionTime);
				m_pCurrent->UpdateFadeOut(elapsed / m_TransitionTime);
				return !IsError();
			default:
				return false;
			}
		}

		// ********************************************************************************
		/// <summary>
		/// �G���[�̎擾
		/// </summary>
		/// <returns>�G���[�t���O</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool IsError(void) const noexcept
		{
			return m_bError;
		}

	public:

		// �V�[���̃C���^�[�t�F�[�X
		using CScene = IScene<State, Data>;

		// ********************************************************************************
		/// <summary>
		/// �V�[���Ǘ��̏�����������B
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		CSceneManager(void) :
			m_pData(std::make_shared<Data>()) {}

		// ********************************************************************************
		/// <summary>
		/// �V�[���Ǘ��̏�����������B
		/// </summary>
		/// <param name="data">�������f�[�^</param>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		CSceneManager(const std::shared_ptr<Data>& data) :
			m_pData(data) {}

		// ********************************************************************************
		/// <summary>
		/// �V�[����ǉ�
		/// </summary>
		/// <param name="state">�ǉ�����V�[���̃X�e�[�g��</param>
		/// <returns>�}�l�[�W��</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		template<class CScene>
		CSceneManager& Add(const State& state)
		{
			typename CScene::InitData initData(state, m_pData, this);

			FactoryFunction_t factory = [=] {
				return std::make_shared<CScene>(initData);
			};

			auto it = m_Factories.find(state);

			if (it != m_Factories.end())
			{
				m_Factories[state] = factory;
			}
			else
			{
				m_Factories.emplace(state, factory);

				if (!m_pFirst)
				{
					m_pFirst = std::make_shared<State>();
					*(m_pFirst.get()) = state;
				}
			}

			return *this;
		}

		// ********************************************************************************
		/// <summary>
		/// �ŏ��̃V�[����������
		/// </summary>
		/// <param name="state">�������f�[�^</param>
		/// <returns>true : ����, false : ���s</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool Initialize(const State& state)
		{
			if (m_pCurrent)
			{
				return false;
			}

			auto it = m_Factories.find(state);

			if (it == m_Factories.end())
			{
				return false;
			}

			m_CurrentState = state;

			m_pCurrent = it->second();

			if (IsError())
			{
				return false;
			}

			m_TransitionState = TransitionState::FadeIn;

			m_StopWatch.Start();

			return true;
		}

		// ********************************************************************************
		/// <summary>
		/// �V�[���̍X�V
		/// </summary>
		/// <returns>true : ����, false : ���s</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool UpdateScene(void)
		{
			if (IsError())
			{
				return false;
			}

			if (!m_pCurrent)
			{
				if (!m_pFirst)
				{
					return true;
				}
				else if (!Initialize(*m_pFirst.get()))
				{
					return false;
				}
			}

			return UpdateSingle();
		}

		// ********************************************************************************
		/// <summary>
		/// �V�[���̕`��
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		void RenderScene(void)
		{
			if (!m_pCurrent)
			{
				return;
			}

			if (m_TransitionState == TransitionState::Active || !m_TransitionTime)
			{
				m_pCurrent->Render();
			}

			const float elapsed = m_StopWatch.GetTime();

			if (m_TransitionState == TransitionState::FadeIn)
			{
				m_pCurrent->RenderFadeIn(elapsed / m_TransitionTime);
			}
			else if (m_TransitionState == TransitionState::FadeOut)
			{
				m_pCurrent->RenderFadeOut(elapsed / m_TransitionTime);
			}
		}

		// ********************************************************************************
		/// <summary>
		/// �V�[���̍X�V
		/// </summary>
		/// <returns>true : ����, false : ���s</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool Update(void)
		{
			if (!UpdateScene())
			{
				return false;
			}

			return true;
		}

		// ********************************************************************************
		/// <summary>
		/// �V�[���̕`��
		/// </summary>
		/// <returns>true : ����, false : ���s</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool Render(void)
		{
			if (IsError())
			{
				return false;
			}

			RenderScene();

			return true;
		}

		// ********************************************************************************
		/// <summary>
		/// ���L�f�[�^�̎擾
		/// </summary>
		/// <returns>���L�f�[�^</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		std::shared_ptr<Data> GetData(void)
		{
			return m_pData;
		}

		// ********************************************************************************
		/// <summary>
		/// ���L�f�[�^�̎擾
		/// </summary>
		/// <returns>���L�f�[�^</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		const std::shared_ptr<const Data> GetData(void) const
		{
			return m_Data;
		}

		// ********************************************************************************
		/// <summary>
		/// �V�[���̕ύX
		/// </summary>
		/// <param name="state">�ύX��̃X�e�[�g</param>
		/// <param name="transitionTime">�J�ڎ���</param>
		/// <returns>true : ����, false : ���s</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		bool ChangeScene(const State& state, float transitionTime)
		{
			if (m_Factories.find(state) == m_Factories.end())
			{
				return false;
			}

			m_NextState = state;

			m_TransitionTime = transitionTime * 0.5f;

			m_TransitionState = TransitionState::FadeOut;

			m_StopWatch.Start();

			return true;
		}

		// ********************************************************************************
		/// <summary>
		/// �t�F�[�h�C���E�A�E�g�̃f�t�H���g�̐F��ݒ肷��B
		/// </summary>
		/// <param name="color">�ݒ肷��F</param>
		/// <returns>�}�l�[�W��</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		CSceneManager& SetFadeColor(const MofU32& color)
		{
			m_FadeColor = color;
			return *this;
		}

		// ********************************************************************************
		/// <summary>
		/// �t�F�[�h�C���E�A�E�g�̃f�t�H���g�F���擾����B
		/// </summary>
		/// <returns>�t�F�[�h�F</returns>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		const MofU32& GetFadeColor(void) const
		{
			return m_FadeColor;
		}

		// ********************************************************************************
		/// <summary>
		/// �G���[�̔�����ʒm����B
		/// </summary>
		/// <created>���̂���,2020/11/11</created>
		/// <changed>���̂���,2020/11/11</changed>
		// ********************************************************************************
		void NotifyError(void)
		{
			m_bError = true;
		}
	};
}

