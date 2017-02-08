#include "QJAPP/SecondPage.h"

#include  "QJFrame/QJAPPlication.h"
#include <QJCore/QJShell.h>
#include <QJCore/QJSleep.h>

SecondPage::SecondPage(std::string title, std::vector<IAbsItems *> Items)
    : BasePage::BasePage(title,Items)
{
}

SecondPage::SecondPage(std::string title)
    : BasePage::BasePage(title)
{
}

void SecondPage::Init()
{
    m_Page1 = QJNEW EntryItem("page1   ",true);
    m_Page2 = QJNEW EntryItem("page2   ",true);
    m_Page3 = QJNEW EntryItem("page3   ",true);
    m_Page4 = QJNEW EntryItem("page4   ",true);

    AddItems(m_Page1);
    AddItems(m_Page2);
    AddItems(m_Page3);
    AddItems(m_Page4);

    QJconnect(m_Page1,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo1);
    QJconnect(m_Page2,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo2);
    QJconnect(m_Page3,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo3);
    QJconnect(m_Page4,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo4);
}

void SecondPage::UnInit()
{
    QJunconnect(m_Page1,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo1);
    QJunconnect(m_Page2,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo2);
    QJunconnect(m_Page3,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo3);
    QJunconnect(m_Page4,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPagetwo4);
}


SecondPage::~SecondPage()
{
}

