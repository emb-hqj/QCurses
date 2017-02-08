#ifndef QJPAGECONTROL_H
#define QJPAGECONTROL_H

#include <QJCore/GDef.h>
#include <QJFrame/QJAPPlication.h>
class BasePage;

class QJPageControl
{
public:
    void Init();
    void UnInit();
    QJPageControl();
    ~QJPageControl(){}
    BasePage* GetRootPage();
public QJSlot:
    QJSlot void SlotPage1(int m_b);
    QJSlot void SlotPage2(int m_b);
    QJSlot void SlotPage3(int m_b);
    QJSlot void SlotPage4(int m_b);
    QJSlot void SlotNextPage(int m_b);
    QJSlot void SlotPagetwo1(int m_b);
    QJSlot void SlotPagetwo2(int m_b);
    QJSlot void SlotPagetwo3(int m_b);
    QJSlot void SlotPagetwo4(int m_b);

private:
    std::vector<BasePage*> m_page;
    BasePage* rootPage;
    BasePage* firstPage;
    BasePage* secondPage;
    BasePage* aPage1;
    BasePage* aPage2;
    BasePage* bPage3;
    BasePage* bPage4;
    BasePage* aPagetwo1;
    BasePage* aPagetwo2;
    BasePage* bPagetwo3;
    BasePage* bPagetwo4;
};

#endif // QJSHELL_H
