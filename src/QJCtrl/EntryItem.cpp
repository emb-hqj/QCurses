#include "QJCtrl/EntryItem.h"

EntryItem::EntryItem(std::string name, bool defValue):BaseItem<bool>::BaseItem(name,defValue){}

bool EntryItem::KeyHandle(int keyCode)
{
    switch(keyCode)
    {
    case KEY_RIGHT:
        SetValue(!m_value);
        QJemit(EntryItem::Clicked,(int)(!m_value));
        return false;
    }
    return false;
}

bool EntryItem::GetValue()
{
    return m_value;
}

void EntryItem::SetValue(bool value)
{
    m_value = value;
}

std::string EntryItem::GetStringValue(){
    return ">>>";
}

void EntryItem::Clicked(int num)
{
    QJ_UNUSE(num);
}
