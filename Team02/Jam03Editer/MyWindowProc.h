#pragma once
#include "Mof.h"

class CMyWindowProc : public CDefWindowProc
{
public:

    CMyWindowProc(void) = default;
    ~CMyWindowProc(void) = default;

    virtual MofProcResult WindowProc(MofWindowHandle hWnd, MofUInt msg, MofProcParamW wpar, MofProcParamL lpar) override;

};

