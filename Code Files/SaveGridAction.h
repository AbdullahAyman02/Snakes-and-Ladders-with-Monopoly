#pragma once
#include "Action.h"
#include <string>
using namespace std;

class SaveGridAction :
    public Action
{
protected:
    string fileName;

public:
    SaveGridAction(ApplicationManager* pApp);

    virtual void ReadActionParameters();

    virtual void Execute();
    
};
