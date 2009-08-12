#include <QtGui/QApplication>
#include "cliente.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cliente w;
    w.show();
    return a.exec();
}
