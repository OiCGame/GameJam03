#include "Game.h"

CGame::CGame(const InitData & data)
    : IScene(data)
{
}

CGame::~CGame(void)
{
}

void CGame::Update(void)
{
    // DEBUG : １キーでタイトルへ
    if (g_pInput->IsKeyPush(MOFKEY_1))
    {
        ChangeScene(SceneName::Title);
    }
}

void CGame::Render(void)
{
    // DEBUG
    CGraphicsUtilities::RenderString(0, 0, "GAME");
}
