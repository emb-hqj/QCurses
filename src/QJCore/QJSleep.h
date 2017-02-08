#ifndef QJSLEEP_H
#define QJSLEEP_H

#include <QJCore/GDef.h>

class QJSleep
{
public:
    static void  mSleep(int mseconds);
    static void  Sleep(int seconds);
    static void  Delay(int mseconds);
    static void mSleepThread(int mseconds);
private:
    QJSleep(){}
    ~QJSleep(){}
};

#endif // QJSHELL_H
