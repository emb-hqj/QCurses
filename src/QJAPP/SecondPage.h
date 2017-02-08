#pragma once
#include "QJFrame/BasePage.h"
#include "QJCtrl/EntryItem.h"
#include "QJCtrl/TextItem.h"
#include "QJCtrl/SwitchItem.h"

class SecondPage : public BasePage
{
public:
    SecondPage(std::string title, std::vector<IAbsItems *> Items);
    SecondPage(std::string title);
    ~SecondPage();
     void Init() QJ_OVERRIDE;
     void UnInit() QJ_OVERRIDE;
private:
     EntryItem *m_Page1;
     EntryItem *m_Page2;
     EntryItem *m_Page3;
     EntryItem *m_Page4;
};

