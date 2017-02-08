
#include <string>
#include "QJCtrl/SpinItem.h"

std::string SpinItem::GetStringValue()
{
    return std::to_string (m_value);
}

void SpinItem::Clicked(int num)
{
    QJ_UNUSE(num);
}

SpinItem::SpinItem(std::string name, int min, int max, int defValue)
    :BaseItem<int>::BaseItem(name,defValue)
    ,m_min(min),m_max(max)
{}

bool SpinItem::KeyHandle(int keyCode)
{
    switch(keyCode)
    {
    case KEY_LEFT:
        if(--m_value <= m_min)
            m_value = m_min;
        SetValue(m_value);
        QJemit(SpinItem::Clicked,m_value);
        return true;
    case KEY_RIGHT:
        if(++m_value >= m_max)
            m_value = m_max;
        SetValue(m_value);
        QJemit(SpinItem::Clicked,m_value);
        return true;
    }
    return false;
}

int SpinItem::GetValue()
{
    return m_value;
}

void SpinItem::SetValue(int value)
{
    m_value = value;
}
