#include "QJFrame/QJKeyControl.h"
#include <ncurses.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <QJCore/QJSleep.h>

void QJKeyControl::Init()
{
    b_keyUseful = true;
}

void QJKeyControl::UnInit()
{
}

int QJKeyControl::GetKeyNum()
{
    fcntl(0,F_SETFL, O_NONBLOCK);
    QJSleep::mSleepThread (2);
    int key = -1;
    key =  getch();

    if (b_keyUseful)
    {
        return key;
    }
    return -1;
}

void QJKeyControl::SetKeyUseFul(bool b_IsUseFul)
{
    char temp[4096];
    getstr (temp);
    b_keyUseful = b_IsUseFul;
}

