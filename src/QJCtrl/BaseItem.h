#pragma once

#include <ncurses.h>
#include <QJCore/GDef.h>
#include <QJCtrl/CtrlDef.h>
#include "QJCtrl/IAbsItems.h"
#include <functional>
#include <QJCore/QJEventCenter.h>

template <typename T>
class BaseItem : public IAbsItems
{
public:
 BaseItem(std::string name, T defValue) \
      :m_name(name),m_value(defValue){}

 virtual ~BaseItem(){}

 virtual void DrawContent(bool bFocus, int itemNum)QJ_OVERRIDE
 {
     mvprintw(itemNum+1,NCURSES_PAGE_LACATION_STAR_X , " %c %.2d %s\t\t%s",bFocus?'*':' ',itemNum ,m_name.c_str() , GetStringValue().c_str());
 }
 QJSignal virtual void Clicked(int num)=0;

 virtual void SetValue(T value)=0;

protected:
  virtual T GetValue()=0;
  virtual std::string GetStringValue()=0;

  std::string m_name;
  T m_value;
};
