#ifndef QJTIMER_H
#define QJTIMER_H

#include <QJCore/GDef.h>
#include <QJCore/QJTimerControl.h>
#include <QJCore/QJEventCenter.h>

class QJTimer
{
public:
    QJTimer();
    ~QJTimer();
    void Start() ;
    void Stop() ;
    void SetInterval(int msec) ;
    int GetInterval() ;
    void SetSingleShot(bool bIsSingleShot) ;
    bool GetSingleShot();
    bool IsActive(void) ;
    bool addMsecNum();
    QJSignal void TimerOut(int num) ;
private:
    bool m_bIsSingleShot;
    int m_msec;
    bool m_bIsRuning;
    int m_msecNow;
};

#endif // QJTIMER_H
