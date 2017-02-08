#pragma once

#include <iostream>
#include "QJCtrl/BaseItem.h"

class SwitchItem : public BaseItem<bool>
{
public:
    SwitchItem(std::string name,bool defValue);
    bool KeyHandle(int keyCode) QJ_OVERRIDE;
    QJSignal virtual void Clicked(int num) QJ_OVERRIDE;
    void SetValue(bool value) QJ_OVERRIDE ;

protected:
    bool GetValue() QJ_OVERRIDE ;
    std::string GetStringValue() QJ_OVERRIDE;

};
