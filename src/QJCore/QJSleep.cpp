#include "QJSleep.h"
#include <unistd.h>
#include <thread>
#include <time.h>
#include <stdio.h>


void QJSleep::mSleep(int mseconds)
{
    long n = (mseconds%1000)*(1e-3)/(1e-9);
    struct timespec ts;
    ts.tv_sec = (mseconds/1000);
    ts.tv_nsec = n;
    nanosleep(&ts, NULL);
}

void QJSleep::Sleep(int seconds)
{
    struct timespec ts;
    ts.tv_nsec = 0;
    ts.tv_sec = seconds;
    nanosleep(&ts, NULL);
}

void QJSleep::Delay(int mseconds)
{
    int num = mseconds*1000;
    while (num)
    {
        num = usleep(num);
    }
}

void QJSleep::mSleepThread(int mseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(mseconds));
}
