#include <QApplication>
#include <QDebug>

#include "roteador.h"

int main( int argc, char* argv[] )
{
    qDebug() << "mandando ver nos testes...";

    QApplication app( argc, argv );

    Roteador
    novo_roteador;

    return app.exec();
}

