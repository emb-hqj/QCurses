#ifndef QJTIMERCONTROL_H
#define QJTIMERCONTROL_H

#include <QJCore/GDef.h>
#include <QJCore/QJTimer.h>
#include <vector>
#include <chrono>
class QJTimer;
class QJTimerControl
{
public:
    static QJTimerControl* GetInstance();
    void  addTimer(QJTimer* timer);
    void  removeTimer(QJTimer* timer);
    void UpdataTimer();
    unsigned int GetDiffTimeMS();
    void Init();
private:
    void callFunTimer();
    bool existTimer(QJTimer* timer);
    QJTimerControl(){}
    ~QJTimerControl(){}
    static QJTimerControl* m_Instance;
    std::vector<QJTimer*> m_TimerVec;
    std::chrono::steady_clock::time_point beforeTime;
    std::chrono::duration<double> diffTime;
};

#endif // QJTIMERCONTROL_H
