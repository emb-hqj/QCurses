#pragma once

#include <iostream>
#include <QJCore/GDef.h>

class IAbsItems QJ_INTERFACE
{
public:
    virtual ~IAbsItems(){}
    virtual void DrawContent(bool bFocus = false,int itemNum = -1)=0;
    virtual bool KeyHandle(int keyCode)=0;
};



