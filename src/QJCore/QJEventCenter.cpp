#include "QJEventCenter.h"
#include <algorithm>

void QJEventCenter::addObserver(void *p_send, std::function<void (int)> sendFunc, std::string sendFuncName, void *p_slot, std::function<void (int)> slotFunc, std::string slotFuncName)
{
    if (this->ObserverExisted(sendFuncName, slotFuncName,p_send,p_slot))
    {
        return;
    }
    QJEventObserver *observe = QJNEW QJEventObserver(p_send, sendFunc,sendFuncName,p_slot,slotFunc,slotFuncName);
    m_array.push_back(observe);
}

bool QJEventCenter::ObserverExisted(std::string sendFuncName, std::string slotFuncName,void* sender,void* slot)
{
    QJEventObserver *obj = nullptr;
    bool _existed = false;

    auto iter = m_array.begin();
    for(;iter != m_array.end();iter++)
    {
        obj = (*iter);
        if (!obj)
        {
            continue;
        }
        if (obj->m_SendFuncName==sendFuncName)
        {
            if (obj->m_SlotFuncName == slotFuncName)
            {
                if (sender == obj->m_pSendPtr)
                {
                    if (slot == obj->m_pSlotPtr)
                    {
                        _existed=true;
                        break;
                    }
                }
            }
        }
    }
    return _existed;
}

void QJEventCenter::removeObserver(std::string sendFuncName, std::string slotFuncName,void* sender,void* slot)
{
    QJEventObserver *obj = nullptr;
    auto iter = m_array.begin();
    for(;iter != m_array.end();iter++)
    {
        obj = (*iter);
        if (!obj)
            continue;
        if (obj->m_SendFuncName==sendFuncName)
        {
            if (obj->m_SlotFuncName == slotFuncName)
            {
                if (sender == obj->m_pSendPtr)
                {
                    if (slot == obj->m_pSlotPtr)
                    {
                        m_array.erase(iter);
                        QJDELETE(obj);
                        return;
                    }
                }
            }
        }
    }
}

void QJEventCenter::PostNotification(std::string sendFuncName, int ref, void* ptr)
{

    std::vector<QJEventObserver*>	m_arrayRunOver;

    auto sp = m_array.begin();
    for(;sp != m_array.end();sp++)
    {
        if (!(*sp))
        {
            continue;
        }
        QJASSERT(0 == count(m_arrayRunOver.cbegin (),m_arrayRunOver.cend (),*sp));
        m_arrayRunOver.push_back (*sp);
        if ((*sp)->m_SendFuncName == sendFuncName)
        {
            if (ptr == nullptr)
                break;
            if (ptr == (*sp)->m_pSendPtr)
            {
//                if ( (*sp)->ObserverCallBack(ref) )
                if ( (*sp)->m_SlotFunc)
                {
                    (*sp)->m_SlotFunc(ref);
                    //bug ! 這裏出現槽函數釋放信號槽會使ｓｐ失效！！！
                    if (!m_array.empty ())//DELET all signal-slot
                    {
                        sp = m_array.begin();

                        for(;sp != m_array.end();sp++)
                        {
                            int result = count(m_arrayRunOver.cbegin (),m_arrayRunOver.cend (),*sp);

                            QJASSERT((result == 1) | (result==0));

                            if (sp == (m_array.end ()-1))
                            {
                                if (result ==1)
                                {
                                    break;
                                }
                            }
                            if (result == 0)
                            {
                                if (sp != m_array.begin ())
                                {
                                    sp--;
                                }
                                break;
                            }

                        }

                    }
                    else
                    {
                        break;
                    }

                }

            }
        }
    }
}
