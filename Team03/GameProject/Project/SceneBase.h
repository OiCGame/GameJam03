#pragma once

#include	<Mof.h>

enum class NextScene {
	Title,
	Game,
	GameClear,
	GameOver,
};

class CSceneBase
{
private:
	bool m_EndFlag{ false };
	NextScene m_NextScene;

	bool			m_bSceneEnd;
	BYTE			m_FadeAlpha;
public:

	virtual ~CSceneBase() {}
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void RenderDebug() {}
	virtual void Release() {}

	void SceneEnd() {
		m_bSceneEnd = true;
	}
	bool IsSceneEnd() {
		return m_EndFlag;
	}

	void SetNextScene(NextScene scene) {
		m_NextScene = scene;
	}

	NextScene NextScene() {
		return m_NextScene;
	}
};

