#ifndef OUVINTE_H
#define OUVINTE_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include <QList>

#include "./jogador.h"

namespace Rede_Server
{
    class Roteador;

    class Ouvinte : public QTcpServer
    {
        Q_OBJECT
    public:
        Ouvinte( Roteador* _parent = NULL );

        ~Ouvinte();

        bool
        startListen();

    signals:

        void
        novoJogador( Jogador* _jogador );

    protected:

        void
        incomingConnection ( int _socket_descriptor );
    };

}
#endif // OUVINTE_H
