#ifndef QJKEYCONTROL_H
#define QJKEYCONTROL_H

#include <QJCore/GDef.h>
#include <QJFrame/AppDef.h>


class QJKeyControl
{
public:
    QJKeyControl(){}
    ~QJKeyControl(){}
    void Init();
    void UnInit();
    int GetKeyNum();
    void SetKeyUseFul(bool b_IsUseFul);

private:
    bool b_keyUseful;
};

#endif // QJSHELL_H
