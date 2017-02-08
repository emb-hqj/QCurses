#pragma once

#include "QJCtrl/BaseItem.h"

class SpinItem : public BaseItem<int>
{
public:
    SpinItem(std::string name,int min,int max,int defValue);
    bool KeyHandle(int keyCode)QJ_OVERRIDE;
    QJSignal virtual void Clicked(int num) QJ_OVERRIDE;
    void SetValue(int value)QJ_OVERRIDE;
protected:
    int GetValue()QJ_OVERRIDE;
    std::string GetStringValue()QJ_OVERRIDE;

private:
	int m_min,m_max;
};


