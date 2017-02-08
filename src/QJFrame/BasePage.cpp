#include <QJCore/GDef.h>
#include <QJCtrl/CtrlDef.h>
#include "QJFrame/BasePage.h"
#include <QJFrame/QJAPPlication.h>

BasePage::BasePage(std::string title, std::vector<IAbsItems *> Items)
    :m_focus_index(0)
    ,m_Title(title)
    ,m_items(Items)
{
}

BasePage::BasePage(std::string title)
    :m_focus_index(0)
    ,m_Title(title)
{
}

BasePage::~BasePage()
{
}

void BasePage::ShowTitle()
{
    attron(A_STANDOUT|A_BLINK);
    attron(COLOR_PAIR(1));
    mvprintw(NCURSES_PAGE_LACATION_TITLE_Y,NCURSES_PAGE_LACATION_TITLE_X,"\t%s\t",m_Title.c_str());
    attroff(A_STANDOUT|A_BLINK);
    attroff(COLOR_PAIR(1));
}

void BasePage::ShowBorder()
{
    mvprintw(NCURSES_PAGE_LACATION_BORDER_Y0,NCURSES_PAGE_LACATION_BORDER_X0,"********************************************");
    mvprintw(NCURSES_PAGE_LACATION_BORDER_Y1,NCURSES_PAGE_LACATION_BORDER_X0,"********************************************");
    for (int i = NCURSES_PAGE_LACATION_BORDER_Y0; i < NCURSES_PAGE_LACATION_BORDER_Y1; ++i)
    {
        mvprintw(i,NCURSES_PAGE_LACATION_BORDER_X0,"*");
        mvprintw(i,NCURSES_PAGE_LACATION_BORDER_X1,"*");
    }
}

void BasePage::AddItems(IAbsItems *item)
{
    if (item)
    {
        m_items.push_back (item);
    }
}



