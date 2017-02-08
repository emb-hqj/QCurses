#pragma once
#include <QJCore/GDef.h>
#include <vector>
#include <list>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>

#define QJconnect( sender,event, accepter, slot) \
    QJEventCenter::GetInstance().addObserver(sender,std::bind(&event,sender,std::placeholders::_1),#event, \
    accepter,std::bind(&slot,accepter,std::placeholders::_1),#slot)

#define QJunconnect( sender,event, accepter, slot) \
    QJEventCenter::GetInstance().removeObserver(#event,#slot,sender,accepter)

#define QJemit(event,eventNum) \
    QJEventCenter::GetInstance().PostNotification(#event,eventNum,this)

struct QJEventObserver
{
    QJEventObserver(void* p_send,std::function<void(int)> sendFunc,std::string sendFuncName,
                    void* p_slot,std::function<void(int)> slotFunc, std::string slotFuncName)
        :m_pSendPtr(p_send)
        ,m_SendFunc(sendFunc)
        ,m_SendFuncName(sendFuncName)
        ,m_pSlotPtr(p_slot)
        ,m_SlotFunc(slotFunc)
        ,m_SlotFuncName(slotFuncName)
    {}
    void * m_pSendPtr ;
    std::function<void(int)>	m_SendFunc;
    std::string	m_SendFuncName;
    void* m_pSlotPtr;
    std::function<void(int)>	m_SlotFunc;
    std::string	m_SlotFuncName;
};

class QJEventCenter
{
public:
    inline static QJEventCenter& GetInstance()
    {
        static QJEventCenter Instance;
        return  Instance;
    }
    void addObserver(void* p_send,std::function<void(int)> sendFunc,std::string sendFuncName,
                     void* p_slot,std::function<void(int)> slotFunc, std::string slotFuncName);
    void removeObserver(std::string sendFuncName, std::string slotFuncName, void *sender, void *slot);
    void PostNotification(std::string sendFuncName, int ref, void *ptr);
private:
    bool ObserverExisted(std::string sendFuncName, std::string slotFuncName, void *sender, void *slot);
    QJEventCenter(){}
    ~QJEventCenter(){}
    std::vector<QJEventObserver*>	m_array;
};

