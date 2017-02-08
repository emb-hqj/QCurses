#pragma once

#include <QJFrame/BasePage.h>
#include "QJCtrl/SpinItem.h"
#include "QJCtrl/SwitchItem.h"
#include "QJCtrl/TextItem.h"

class BPage : public BasePage
{
public:
    BPage(std::string title, std::vector<IAbsItems *> Items);
    BPage(std::string title);
     void Init() QJ_OVERRIDE;
     void UnInit() QJ_OVERRIDE;

    ~BPage();

private QJSlot:
      QJSlot void SlotBSwitch(int m_b);
      QJSlot void SlotBAdjust(int m_b);

private:
     SwitchItem *m_BSwitch;
     SpinItem *m_BAdjust;
     TextItem *m_Resolution;

};

