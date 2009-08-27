#include <QApplication>
#include <QDebug>

#include "roteador.h"

int main( int argc, char* argv[] )
{
    QApplication app( argc, argv );

    Rede_Server::Roteador
    novo_roteador(3);

    return app.exec();
}
