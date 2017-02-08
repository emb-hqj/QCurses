#include "QJShell.h"

QJShell* QJShell::m_Instance = QJNEW QJShell;

QJShell *QJShell::GetInstance()
{
    return m_Instance;
}

int QJShell::SystemCplusplus(const char *cmd)
{
    return system (cmd)/256;
}

int QJShell::System(const char *cmd)
{
    return system (cmd);
}

std::string QJShell::Popen(const char *cmd)
{
    FILE *pf = popen(cmd, "r");
    if (pf == nullptr)
    {
        return "Popen error";
    }
    char res[4096];
    fread(res, 4096, 1, pf);
    pclose(pf);
    std::string str = res;
    return str;
}

bool QJShell::PopenUnBlock(const char *cmd)
{
    popen(cmd, "r");
    return true;
}


