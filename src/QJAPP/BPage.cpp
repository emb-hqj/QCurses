#include "QJAPP/BPage.h"

#include  "QJFrame/QJAPPlication.h"
#include <QJCore/QJShell.h>

BPage::BPage(std::string title, std::vector<IAbsItems *> Items)
    : BasePage::BasePage(title,Items)
{
}

BPage::BPage(std::string title)
    : BasePage::BasePage(title)
{
}

void BPage::Init()
{
    m_BSwitch = QJNEW SwitchItem("BSwitch",false);
    m_BAdjust = QJNEW SpinItem("BAdjust",1,12,3);

    std::string res_Resolution = "test";
    m_Resolution = QJNEW TextItem("Resolution    ",res_Resolution);



    AddItems(m_BSwitch);
    AddItems(m_BAdjust);
    AddItems(m_Resolution);

    QJconnect(m_BSwitch,SwitchItem::Clicked,this,BPage::SlotBSwitch);
    QJconnect(m_BAdjust,SpinItem::Clicked,this,BPage::SlotBAdjust);
}

void BPage::UnInit()
{
    QJunconnect(m_BSwitch,SwitchItem::Clicked,this,BPage::SlotBSwitch);
    QJunconnect(m_BAdjust,SpinItem::Clicked,this,BPage::SlotBAdjust);
}

void BPage::SlotBSwitch(int m_b)
{
    QJ_UNUSE(m_b);
}

void BPage::SlotBAdjust(int m_b)
{
    QJ_UNUSE(m_b);
}

BPage::~BPage()
{
}
