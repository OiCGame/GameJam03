#pragma once
#include	"SceneDefine.h"

class CGameDescription : public MyApp::CScene
{
private:
	CTexture	DescriptionTexture;

public:
	explicit CGameDescription(const InitData & data);
	~CGameDescription();

	void Load();
	void Update();
	void Render();
	void Release();

};