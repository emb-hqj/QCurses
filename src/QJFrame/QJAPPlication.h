#ifndef QJAPPLICATION_H
#define QJAPPLICATION_H

#include  <vector>
#include <QJCore/GDef.h>
#include <QJFrame/AppDef.h>
#include <QJFrame/QJPageControl.h>
class QJTimer;
class BasePage;
class QJKeyControl;
class QJPageControl;

class QJAPPlication
{
public:
    static QJAPPlication* GetInstance();
    void Init();
    void UnInit();
    void Show(BasePage* page);

    void SaveBeforePage();
    void RecoverBeforePage();

    QJKeyControl* GetKeyControl();
    QJPageControl* GetPageControl();

private:
    ~QJAPPlication();
    QJAPPlication();
    void initCurses();

private QJSlot:
    QJSlot void SlotTImerPageRefresh(int n);


private:
     static QJAPPlication* m_Instance;
    QJKeyControl* m_keyControl;
    QJPageControl* m_pageControl;
};

#endif // QJAPPLICATION_H
