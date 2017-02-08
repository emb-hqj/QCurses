#include "QJCtrl/TextItem.h"

#define TEXT_ITEM_CHANGE_NUM 50

TextItem::TextItem(std::string name, std::string defValue) \
    :BaseItem<std::string>::BaseItem(name,defValue){}

bool TextItem::KeyHandle(int keyCode)
{
    switch (keyCode)
    {
    case KEY_RIGHT:
        QJemit(TextItem::Clicked,0);
        return true;
    default:
        break;
    }
    return false;
}

void TextItem::DrawContent(bool bFocus, int itemNum)
{
    std::string    str_value(m_value,0,3);
    str_value = str_value + "...";
    mvprintw(itemNum+1,NCURSES_PAGE_LACATION_STAR_X , " %c %.2d %s\t\t%s",bFocus?'*':' ',itemNum ,m_name.c_str() , str_value.c_str ());
    if (bFocus)
    {
        attron(A_BOLD);
        mvprintw(NCURSES_PAGE_LACATION_EXPLAIN_Y,0 , " %s\t\t" ,m_value.c_str() );
        attroff (A_BOLD);
    }
}

void TextItem::Clicked(int num)
{
    QJ_UNUSE(num);
}

std::string TextItem::GetValue()
{
    return m_value;
}

void TextItem::SetValue(std::string value)
{
    m_value = value;
}

std::string TextItem::GetStringValue()
{
    return m_value;
}



