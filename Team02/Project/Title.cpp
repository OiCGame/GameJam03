#include "Title.h"

CTitle::CTitle(const InitData & data)
    : IScene(data)
{
}

CTitle::~CTitle(void)
{
}

void CTitle::Update(void)
{
    // DEBUG : �P�L�[�ŃQ�[����
    if (g_pInput->IsKeyPush(MOFKEY_1))
    {
        ChangeScene(SceneName::Game);
    }
}

void CTitle::Render(void)
{
    // DEBUG
    CGraphicsUtilities::RenderString(0, 0, "TITLE");
}
