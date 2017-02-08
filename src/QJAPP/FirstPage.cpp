#include "QJAPP/FirstPage.h"
#include  "QJFrame/QJPageControl.h"

FirstPage::FirstPage(std::string title, std::vector<IAbsItems *> Items)
    : BasePage::BasePage(title,Items)
{
}

FirstPage::FirstPage(std::string title)
    : BasePage::BasePage(title)
{
}

void FirstPage::Init()
{
    m_Page1 = QJNEW EntryItem("page1   ",true);
    m_Page2 = QJNEW EntryItem("page2   ",true);
    m_Page3 = QJNEW EntryItem("page3   ",true);
    m_Page4 = QJNEW EntryItem("page4   ",true);
    m_NextPage = QJNEW EntryItem("NextPage",false);

    AddItems(m_Page1);
    AddItems(m_Page2);
    AddItems(m_Page3);
    AddItems(m_Page4);
    AddItems(m_NextPage);

    QJconnect(m_Page1,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage1);
    QJconnect(m_Page2,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage2);
    QJconnect(m_Page3,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage3);
    QJconnect(m_Page4,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage4);
    QJconnect(m_NextPage,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotNextPage);
}

void FirstPage::UnInit()
{
    QJunconnect(m_Page1,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage1);
    QJunconnect(m_Page2,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage2);
    QJunconnect(m_Page3,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage3);
    QJunconnect(m_Page4,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotPage4);
    QJunconnect(m_NextPage,EntryItem::Clicked,QJAPPlication::GetInstance()->GetPageControl (),QJPageControl::SlotNextPage);
}

FirstPage::~FirstPage()
{
}

