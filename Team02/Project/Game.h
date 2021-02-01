#pragma once
#include "SceneDefine.h"

class CGame : public MyApp::CScene
{
private:

public:

    explicit CGame(const InitData& data);
    
    ~CGame(void);

    void Update(void) override;

    void Render(void) override;
};

