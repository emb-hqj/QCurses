#pragma once

#include "QJCtrl/BaseItem.h"

class TextItem : public BaseItem<std::string>
{
public:
    TextItem(std::string name,std::string defValue);
    bool KeyHandle(int keyCode) QJ_OVERRIDE ;
    void DrawContent(bool bFocus, int itemNum) QJ_OVERRIDE;
    QJSignal virtual void Clicked(int num) QJ_OVERRIDE;

    void SetValue(std::string value) QJ_OVERRIDE;
protected:
    std::string GetValue() QJ_OVERRIDE;
    std::string GetStringValue() QJ_OVERRIDE;
};
