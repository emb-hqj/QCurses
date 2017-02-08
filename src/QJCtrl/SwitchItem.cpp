#include "QJCtrl/SwitchItem.h"


SwitchItem::SwitchItem(std::string name, bool defValue)
    :BaseItem<bool>::BaseItem(name,defValue)
{
}

bool SwitchItem::KeyHandle(int keyCode)
{
    switch(keyCode)
    {
    case KEY_LEFT:
    case KEY_RIGHT:
        SetValue(!m_value);
        QJemit(SwitchItem::Clicked,(int)(m_value));
        return true;
    }
    return false;
}

bool SwitchItem::GetValue()
{
    return m_value;
}

void SwitchItem::SetValue(bool value)
{
    m_value = value;
}

std::string SwitchItem::GetStringValue(){
    return m_value?"TRUE":"FALSE";
}

void SwitchItem::Clicked(int num)
{
    QJ_UNUSE(num);
}
