#pragma once
#include <vector>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>
#include "GDef.h"


#define QJconnect( sender,event, accepter, slot) \
    QJEventCenter::GetInstance().addObserver(sender,std::bind(&event,sender,std::placeholders::_1),#event, \
    accepter,std::bind(&slot,accepter,std::placeholders::_1),#slot)

#define QJunconnect( sender,event, accepter, slot) \
    QJEventCenter::GetInstance().removeObserver(#event,#slot,sender,accepter)

#define QJemit(event,eventNum) \
    QJEventCenter::GetInstance().PostNotification(#event,eventNum,this)



typedef  int FunctorPara;
typedef  std::function<void(FunctorPara)> Functor;
typedef void* WeakVoid;

struct QJEventObserver
{
    QJEventObserver(WeakVoid p_send,Functor sendFunc,std::string sendFuncName,
                    WeakVoid p_slot,Functor slotFunc, std::string slotFuncName)
        :m_pSendPtr(p_send)
        ,m_SendFunc(sendFunc)
        ,m_SendFuncName(sendFuncName)
        ,m_pSlotPtr(p_slot)
        ,m_SlotFunc(slotFunc)
        ,m_SlotFuncName(slotFuncName)
    {}
    WeakVoid m_pSendPtr ;
    Functor	m_SendFunc;
    std::string	m_SendFuncName;
    WeakVoid m_pSlotPtr;
    Functor	m_SlotFunc;
    std::string	m_SlotFuncName;
};

typedef std::vector<std::shared_ptr<QJEventObserver> > ObserVec;
typedef std::shared_ptr<ObserVec> ObserVecPtr;
class QJEventCenter
{
public:

    inline static QJEventCenter& GetInstance()
    {
        static QJEventCenter Instance;
        return  Instance;
    }
    void addObserver(WeakVoid p_send,Functor sendFunc,std::string sendFuncName,
                     WeakVoid p_slot,Functor slotFunc, std::string slotFuncName);
    void removeObserver(std::string sendFuncName, std::string slotFuncName, WeakVoid sender, WeakVoid slot);
    void PostNotification(std::string sendFuncName, FunctorPara ref, WeakVoid sender);
private:
    bool ObserverExisted(std::string sendFuncName, std::string slotFuncName, WeakVoid sender, WeakVoid slot);
    QJEventCenter()
    {
        m_array.reset(new ObserVec);
    }
    ~QJEventCenter(){}
    ObserVecPtr m_array;
    std::mutex mtx;
};


