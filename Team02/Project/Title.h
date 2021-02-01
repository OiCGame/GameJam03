#pragma once
#include "SceneDefine.h"

class CTitle : public MyApp::CScene
{
private:

public:


    explicit CTitle(const InitData& data);

    ~CTitle(void);

    void Update(void) override;

    void Render(void) override;
};

