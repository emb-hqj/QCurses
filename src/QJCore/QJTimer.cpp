#include "QJTimer.h"
#include <QJCore/QJTimerControl.h>

QJTimer::QJTimer()
    :m_bIsSingleShot(true)
    ,m_msec(1000)
    ,m_bIsRuning(false)
    ,m_msecNow(0)
{
}

QJTimer::~QJTimer()
{
    if (m_bIsRuning)
    {
        Stop ();
    }
}

void QJTimer::Start()
{
    if (m_bIsRuning)
    {
        return;
    }
    m_bIsRuning = true;
    QJTimerControl::GetInstance ()->addTimer (this);
}

void QJTimer::Stop ()
{
    m_bIsRuning = false;
    QJTimerControl::GetInstance ()->removeTimer (this);
}

void QJTimer::SetInterval(int msec)
{
    m_msec = msec;
}

int QJTimer::GetInterval()
{
    return m_msec;
}

void QJTimer::SetSingleShot(bool bIsSingleShot)
{
    m_bIsSingleShot = bIsSingleShot;

}

bool QJTimer::GetSingleShot()
{
    return m_bIsSingleShot;
}

bool QJTimer::IsActive()
{
    return m_bIsRuning;
}

bool QJTimer::addMsecNum()
{
    m_msecNow = m_msecNow + QJTimerControl::GetInstance ()->GetDiffTimeMS ();
    if (m_msecNow > m_msec)
    {
        m_msecNow = 0;
        QJemit(QJTimer::TimerOut,0);
        return true;
    }
    return false;
}

void QJTimer::TimerOut(int num)
{
    QJ_UNUSE(num);
}


