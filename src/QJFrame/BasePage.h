#pragma once

#include <vector>
#include "QJCtrl/IAbsItems.h"
#include <ncurses.h>
#include "QJFrame/AppDef.h"


class QJAPPlication;
class BasePage QJ_INTERFACE
{
public:
    BasePage(std::string title,std::vector<IAbsItems *> Items);
    BasePage(std::string title);
    virtual ~BasePage();
    virtual void Init() = 0;
    virtual void UnInit() = 0;
    void AddItems(IAbsItems * item);
    friend class QJAPPlication;
protected:
    int m_focus_index;

private:

    void ShowTitle();
    void ShowBorder();

    std::string m_Title;
    std::vector<IAbsItems *> m_items;
};
