#ifndef QJSHELL_H
#define QJSHELL_H

#include <vector>
#include <string>
#include <QJCore/GDef.h>

class QJShell
{
public:

    static QJShell* GetInstance();

    int SystemCplusplus (const char* cmd);

    int System(const char* cmd);

    std::string Popen(const char* cmd);

    bool PopenUnBlock(const char* cmd);

private:
    QJShell(){}
    ~QJShell(){}
    static QJShell* m_Instance;
};

#endif // QJSHELL_H
