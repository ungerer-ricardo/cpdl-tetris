#include <QApplication>

#include "janelaprincipal.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    JanelaPrincipal*
    boga = new JanelaPrincipal();


    boga->show();

    return app.exec();
}

