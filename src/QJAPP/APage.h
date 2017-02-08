#pragma once

#include <QJFrame/BasePage.h>
#include "QJCtrl/SwitchItem.h"

class APage : public BasePage
{
public:
    APage(std::string title, std::vector<IAbsItems *> Items);
    APage(std::string title);
     void Init() QJ_OVERRIDE;
     void UnInit() QJ_OVERRIDE;
    ~APage();

private QJSlot:
      QJSlot void SlotOnA(int m_b);
      QJSlot void SlotOffA(int m_b);

private:
     SwitchItem *m_OnA;
     SwitchItem *m_OffA;
};

