#include "QJAPP/APage.h"

#include  "QJFrame/QJAPPlication.h"
#include <QJCore/QJShell.h>

APage::APage(std::string title, std::vector<IAbsItems *> Items)
    : BasePage::BasePage(title,Items)
{
}

APage::APage(std::string title)
    : BasePage::BasePage(title)
{
}

void APage::Init()
{
    m_OnA = QJNEW SwitchItem("OnA      ",false);
    m_OffA = QJNEW SwitchItem("OffA     ",false);

    AddItems(m_OnA);
    AddItems(m_OffA);

    QJconnect(m_OnA,SwitchItem::Clicked,this,APage::SlotOnA);
    QJconnect(m_OffA,SwitchItem::Clicked,this,APage::SlotOffA);
}

void APage::UnInit()
{
    QJunconnect(m_OnA,SwitchItem::Clicked,this,APage::SlotOnA);
    QJunconnect(m_OffA,SwitchItem::Clicked,this,APage::SlotOffA);
}

void APage::SlotOnA(int m_b)
{
    QJ_UNUSE(m_b);
}

void APage::SlotOffA(int m_b)
{
    QJ_UNUSE(m_b);
}

APage::~APage()
{
}


