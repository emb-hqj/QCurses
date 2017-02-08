#include "QJTimerControl.h"
#include <QJCore/QJEventCenter.h>
#include <algorithm>

QJTimerControl* QJTimerControl::m_Instance = QJNEW QJTimerControl;

QJTimerControl *QJTimerControl::GetInstance()
{
    return m_Instance;
}

void QJTimerControl::addTimer(QJTimer *timer)
{
    if (!existTimer(timer))
    {
        m_TimerVec.push_back (timer);
    }
}

void QJTimerControl::removeTimer(QJTimer *timer)
{
    auto iter = m_TimerVec.begin ();
    for (int i = 0; i < (int)m_TimerVec.size (); ++i)
    {
        if (timer == *iter)
        {
            m_TimerVec.erase (iter);
        }
        iter ++;
    }
}

void QJTimerControl::UpdataTimer()
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    diffTime = start-beforeTime;
    if (diffTime.count ()< 0.001)// while scan is less 1ms
    {
        return;
    }
    beforeTime = start;
    callFunTimer ();
}

unsigned int QJTimerControl::GetDiffTimeMS()
{
    return (unsigned int)(diffTime.count ()*1000);
}

void QJTimerControl::Init()
{
    beforeTime = std::chrono::steady_clock::now();
}

void QJTimerControl::callFunTimer()
{
    std::vector<QJTimer*> m_TimerVecRunOver;
    auto iter = m_TimerVec.begin ();
    for (; iter!=m_TimerVec.end (); iter++)
    {
        QJTimer* tmp_timer = *iter;
        if (tmp_timer == nullptr)
            continue;
        QJASSERT(0 == count(m_TimerVecRunOver.cbegin (),m_TimerVecRunOver.cend (),*iter));
        m_TimerVecRunOver.push_back (*iter);

        if (tmp_timer->IsActive())
        {
            if ( tmp_timer->addMsecNum())
            {
                if (tmp_timer != nullptr)//maby timer delete self
                {
                    if (tmp_timer->GetSingleShot())
                    {
                        tmp_timer->Stop();
//                        break;
                    }
                }

                if (!m_TimerVec.empty ())
                {
                    //for find now real iter if in timer-slot delete or add some timer
                    iter = m_TimerVec.begin();
                    for(;iter != m_TimerVec.end();iter++)
                    {
                        int result = count(m_TimerVecRunOver.cbegin (),m_TimerVecRunOver.cend (),*iter);
                        QJASSERT((result == 1) | (result==0));
                        if (iter == (m_TimerVec.end ()-1))
                        {
                            if ( result == 1 )
                            {
                                break;//if last timer is runover break
                            }
                        }
                        if ( result ==0 )
                        {
                            if (iter != m_TimerVec.begin ())
                            {
                                iter--;
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

bool QJTimerControl::existTimer(QJTimer *timer)
{
    auto iter = m_TimerVec.begin ();
    for (; iter != m_TimerVec.end ();iter++)
    {
        if (timer == *iter)
        {
            return true;
        }
    }
    return false;
}

