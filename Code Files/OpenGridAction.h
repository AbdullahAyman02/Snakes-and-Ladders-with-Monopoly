#pragma once
#include "Action.h"
#include <string>

using namespace std;
class OpenGridAction :
    public Action
{
protected:
    string FileName;


public:
    OpenGridAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
};
