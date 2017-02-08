#include "QJFrame/QJAPPlication.h"
#include <QJCore/QJTimer.h>
#include <QJFrame/BasePage.h>
#include <QJFrame/QJKeyControl.h>
#include <QJFrame/QJPageControl.h>


QJAPPlication* QJAPPlication::m_Instance = QJNEW QJAPPlication;

QJAPPlication::QJAPPlication()
{
}

void QJAPPlication::initCurses()
{
    initscr();
    setlocale (LC_ALL,"");
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    curs_set(0);
    noecho();
    keypad(stdscr,TRUE);
    erase ();
    refresh();
}

void QJAPPlication::Show(BasePage *page)
{
    page->Init ();

    bool bRuning = true;
    int len = page->m_items.size();
    this->initCurses();

    int keypress = 0;

    while(bRuning)
    {
        QJTimerControl::GetInstance ()->UpdataTimer ();
        keypress = QJAPPlication::GetInstance ()->GetKeyControl ()->GetKeyNum ();

        erase ();
        page->ShowTitle ();
        page->ShowBorder ();
        for (int i =0; i < len; i++)
        {
            page->m_items[i]->DrawContent((i==page->m_focus_index),i+1);
        }
        refresh();

        if (len > 0)
        {
            if(page->m_items[page->m_focus_index]->KeyHandle(keypress) == true)
                continue;
        }

        switch(keypress)
        {
        case KEY_UP:
            if(--page->m_focus_index < 0)
                page->m_focus_index = 0;
            break;
        case KEY_DOWN:
            if(++page->m_focus_index >= len)
                page->m_focus_index = len -1;
            break;
        case KEY_BACKSPACE:
        case KEY_EXIT:
        case 'q':
        case 'Q':
            if ( page != GetPageControl ()->GetRootPage ())
            {
                bRuning = false;
            }
            break;
        }

    }

    endwin();
    page->UnInit ();
    for (int i =0; i < len; i++)
    {
        QJDELETE(page->m_items[i]);
    }
    page->m_items.clear ();

}

QJAPPlication::~QJAPPlication()
{
    UnInit ();
}

QJAPPlication *QJAPPlication::GetInstance()
{
    return m_Instance;
}

void QJAPPlication::Init()
{
    m_keyControl = QJNEW QJKeyControl();
    m_keyControl->Init ();

    QJTimerControl::GetInstance ()->Init ();
    m_pageControl = QJNEW QJPageControl();
    m_pageControl->Init ();
}

void QJAPPlication::UnInit()
{
    GetPageControl ()->UnInit ();
    QJDELETE(m_pageControl);

    GetKeyControl ()->UnInit ();
    QJDELETE(m_keyControl);
}

void QJAPPlication::SaveBeforePage()
{
    GetKeyControl ()->SetKeyUseFul (false);
    def_prog_mode();
    endwin();
}

void QJAPPlication::RecoverBeforePage()
{
    reset_prog_mode();
    refresh();
    GetKeyControl ()->SetKeyUseFul (true);
}

QJKeyControl *QJAPPlication::GetKeyControl()
{
    return m_keyControl;
}

QJPageControl *QJAPPlication::GetPageControl()
{
    return m_pageControl;
}


