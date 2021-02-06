#include "GameDescription.h"

CGameDescription::CGameDescription(const InitData & data)
	: IScene(data)
{
	Load();
}

CGameDescription::~CGameDescription()
{
	Release();
}

void CGameDescription::Load()
{
	DescriptionTexture.Load("‘€ìà–¾.png");
}

void CGameDescription::Update()
{
	if (g_pInput->IsKeyPush(MOFKEY_SPACE))
	{
		ChangeScene(SceneName::Game);
	}
}

void CGameDescription::Render()
{
	DescriptionTexture.Render(0, 0);
}

void CGameDescription::Release()
{
	DescriptionTexture.Release();
}
