#include <QJFrame/QJAPPlication.h>

int main(int argc, char *argv[])
{
    QJ_UNUSE(argc);
    QJ_UNUSE(argv);
    try
    {
        QJAPPlication::GetInstance ()->Init ();
    }
    catch (const std::exception& e)
    {
      QJLOG(e.what ());
    }
    return 0;
}

