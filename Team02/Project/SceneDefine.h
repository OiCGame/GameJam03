#pragma once
#include "SceneManager.h"

// シーン名列挙
enum class SceneName
{
    Title,
    Game,
    GameOver,
    GameClear,
};

// シーン共通データ
struct SceneData
{
    int StageNo; //! ステージ番号
};

// シーンマネージャー
using MyApp = sip::CSceneManager<SceneName, SceneData>;