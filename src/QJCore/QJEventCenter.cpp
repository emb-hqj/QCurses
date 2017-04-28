#include "QJEventCenter.h"
#include "QJMutex.h"
#include <algorithm>

void QJEventCenter::addObserver(WeakVoid p_send, Functor sendFunc, std::string sendFuncName,WeakVoid p_slot, Functor slotFunc, std::string slotFuncName)
{
    if (this->ObserverExisted(sendFuncName, slotFuncName,p_send,p_slot))
    {
        return;
    }
    std::shared_ptr<QJEventObserver> observe ( QJNEW QJEventObserver(p_send, sendFunc,sendFuncName,p_slot,slotFunc,slotFuncName) );
    qijia::QJMutex lock (mtx);
    if (!m_array.unique ())
    {
        m_array.reset (new ObserVec(*m_array));
        QJLOG("copy m_array in addObserver \n");
    }
    m_array->push_back(observe);
}

bool QJEventCenter::ObserverExisted(std::string sendFuncName, std::string slotFuncName, WeakVoid sender, WeakVoid slot)
{
    //only read not write
    bool b_existed = false;
    ObserVecPtr array;
    {
        qijia::QJMutex lock (mtx);
        array = m_array;
        QJASSERT(!m_array.unique ());
    }
    auto iter =   array->begin();
    while(iter !=   (array)->end())
    {
        void* objShareSend = ((*iter)->m_pSendPtr);
        void* objShareSlot = ((*iter)->m_pSlotPtr);
        if (objShareSend && objShareSlot)
        {
            if ((*iter)->m_SendFuncName==sendFuncName)
            {
                if ((*iter)->m_SlotFuncName == slotFuncName)
                {
                    if (sender== objShareSend)
                    {
                        if (slot== objShareSlot)
                        {
                            b_existed=true;
                            break;
                        }
                    }
                }
            }
            ++iter;
        }
        else
        {
            QJLOG("in ObserverExisted sender or slot ptr null");
        }
    }
    return b_existed;
}

void QJEventCenter::removeObserver(std::string sendFuncName, std::string slotFuncName,WeakVoid sender,WeakVoid slot)
{
    qijia::QJMutex lock (mtx);
    if (!m_array.unique ())
    {
        m_array.reset (new ObserVec(*m_array));
        QJLOG("copy m_array in removeObserver \n");
    }
    auto iter =   (m_array)->begin();
    while(iter !=   (m_array)->end())
    {
        void* objShareSend = ((*iter)->m_pSendPtr);
        void* objShareSlot = ((*iter)->m_pSlotPtr);
        if (objShareSend && objShareSlot)
        {
            if ((*iter)->m_SendFuncName==sendFuncName)
            {
                if ((*iter)->m_SlotFuncName == slotFuncName)
                {
                    if (sender== objShareSend)
                    {
                        if (slot== objShareSlot)
                        {
                            iter =   (m_array)->erase(iter);
                            continue;
                        }
                    }
                }
            }
            ++iter;
        }
        else
        {
            iter =   (m_array)->erase (iter);
        }
    }
}

void QJEventCenter::PostNotification(std::string sendFuncName, FunctorPara ref, WeakVoid sender)
{
    //only read not write
    ObserVecPtr array;
    {
        qijia::QJMutex lock (mtx);
        array = m_array;
        QJASSERT(!m_array.unique ());
    }
    auto iter =   (array)->begin();
    while(iter !=   (array)->end())
    {
        void* objShareSend = ((*iter)->m_pSendPtr);
        if (objShareSend)
        {
            if ((*iter)->m_SendFuncName==sendFuncName)
            {
                if (sender== objShareSend)
                {
                    if (((*iter)->m_pSlotPtr))
                    {
                        (*iter)->m_SlotFunc(ref);
                    }
                    else
                    {
                        QJLOG("in PostNotification slot ptr null");
                    }
                }
            }
            ++iter;
        }
        else
        {
            QJLOG("in PostNotification sender ptr null");
        }
    }
}
