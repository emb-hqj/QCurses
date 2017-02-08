#include "QJFrame/QJPageControl.h"
#include "QJFrame/QJAPPlication.h"
#include "QJAPP/FirstPage.h"
#include "QJAPP/SecondPage.h"
#include "QJAPP/APage.h"
#include "QJAPP/BPage.h"


void QJPageControl::Init()
{
    if (firstPage == nullptr)
    {
        firstPage   = QJNEW FirstPage("QCursesLib");
        m_page.push_back (firstPage);
    }
    rootPage = firstPage;
    QJAPPlication::GetInstance ()->Show (firstPage);
}

void QJPageControl::UnInit()
{
    for (size_t i = 0; i < m_page.size (); ++i)
    {
        QJDELETE(m_page[i]);
    }
    m_page.clear ();
    QJDELETE(rootPage);
}

QJPageControl::QJPageControl()
    :rootPage(nullptr)
    ,firstPage(nullptr)
    ,secondPage(nullptr)
    ,aPage1(nullptr)
    ,aPage2(nullptr)
    ,bPage3(nullptr)
    ,bPage4(nullptr)
    ,aPagetwo1(nullptr)
    ,aPagetwo2(nullptr)
    ,bPagetwo3(nullptr)
    ,bPagetwo4(nullptr)
{
}

BasePage *QJPageControl::GetRootPage()
{
    return rootPage;
}

void QJPageControl::SlotPage1(int m_b)
{
    QJ_UNUSE(m_b);
    if (aPage1 ==nullptr)
    {
        aPage1   = QJNEW APage("Page1");
        m_page.push_back (aPage1);
    }
    QJAPPlication::GetInstance ()->Show (aPage1);
}

void QJPageControl::SlotPage2(int m_b)
{
    QJ_UNUSE(m_b);
    if (aPage2 ==nullptr)
    {
        aPage2   = QJNEW APage("Page2");
        m_page.push_back (aPage2);
    }
    QJAPPlication::GetInstance ()->Show (aPage2);
}

void QJPageControl::SlotPage3(int m_b)
{
    QJ_UNUSE(m_b);
    if (bPage3 ==nullptr)
    {
        bPage3   = QJNEW BPage("bPage3");
        m_page.push_back (bPage3);
    }
    QJAPPlication::GetInstance ()->Show (bPage3);
}


void QJPageControl::SlotPage4(int m_b)
{
    QJ_UNUSE(m_b);
    if (bPage4 ==nullptr)
    {
        bPage4   = QJNEW BPage("bPage4");
        m_page.push_back (bPage4);
    }
    QJAPPlication::GetInstance ()->Show (bPage4);
}

void QJPageControl::SlotNextPage(int m_b)
{
    secondPage = QJNEW SecondPage("SecondPage");
    QJ_UNUSE(m_b);
    if (secondPage == nullptr)
    {
        m_page.push_back (secondPage);
    }
    QJAPPlication::GetInstance ()->Show (secondPage);
}

void QJPageControl::SlotPagetwo1(int m_b)
{
    QJ_UNUSE(m_b);
    if (aPagetwo1 ==nullptr)
    {
        aPagetwo1   = QJNEW APage("bPagetwo1");
        m_page.push_back (aPagetwo1);
    }
    QJAPPlication::GetInstance ()->Show (aPagetwo1);
}

void QJPageControl::SlotPagetwo2(int m_b)
{
    QJ_UNUSE(m_b);
    if (aPagetwo2 ==nullptr)
    {
        aPagetwo2   = QJNEW APage("aPagetwo2");
        m_page.push_back (aPagetwo2);
    }
    QJAPPlication::GetInstance ()->Show (aPagetwo2);
}

void QJPageControl::SlotPagetwo3(int m_b)
{
    QJ_UNUSE(m_b);
    if (bPagetwo3 ==nullptr)
    {
        bPagetwo3   = QJNEW APage("bPagetwo3");
        m_page.push_back (bPagetwo3);
    }
    QJAPPlication::GetInstance ()->Show (bPagetwo3);
}

void QJPageControl::SlotPagetwo4(int m_b)
{

}

