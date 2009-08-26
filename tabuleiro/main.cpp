#include <QtGui/QApplication>
#include "tabuleiro.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tabuleiro w;
    w.show();

    w.startjogo(6,5);

    //w.novapeca(4);

    return a.exec();
}
