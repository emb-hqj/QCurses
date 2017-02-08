#pragma once

#include "QJFrame/BasePage.h"
#include "QJCtrl/EntryItem.h"
#include "QJCtrl/TextItem.h"
#include "QJCtrl/SwitchItem.h"

class FirstPage : public BasePage
{
public:
    FirstPage(std::string title, std::vector<IAbsItems *> Items);
    FirstPage(std::string title);
    ~FirstPage();
    void Init() QJ_OVERRIDE;
    void UnInit() QJ_OVERRIDE;
private:
    EntryItem *m_Page1;
    EntryItem *m_Page2;
    EntryItem *m_Page3;
    EntryItem *m_Page4;
    EntryItem *m_NextPage;
};


