#pragma once
#include "SceneManager.h"

// �V�[������
enum class SceneName
{
    Title,
    Game,
};

// �V�[�����ʃf�[�^
struct SceneData
{

};

// �V�[���}�l�[�W���[
using MyApp = sip::CSceneManager<SceneName, SceneData>;