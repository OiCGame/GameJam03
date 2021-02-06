#pragma once
#include "SceneManager.h"

// �V�[������
enum class SceneName
{
    Title,
    Game,
    GameOver,
    GameClear,
	GameDescription,
};

// �V�[�����ʃf�[�^
struct SceneData
{
    int StageNo; //! �X�e�[�W�ԍ�
};

// �V�[���}�l�[�W���[
using MyApp = sip::CSceneManager<SceneName, SceneData>;