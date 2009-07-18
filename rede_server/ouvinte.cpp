#include "ouvinte.h"

#include <QDebug>

#include "./roteador.h"

Ouvinte::Ouvinte( Roteador* _parent )
        : QTcpServer( _parent )
{
    QObject::connect(this, SIGNAL(novoJogador(Jogador*)),
                     _parent, SLOT(novoJogador(Jogador*)));
}

Ouvinte::~Ouvinte()
{

}

bool
Ouvinte::startListen()
{
    qint16
    porta = 6969;

    this->listen( QHostAddress::LocalHost, porta );

    if ( this->isListening() )
    {
        qDebug() << "Ouvinte: to ouvino fia!!!";
        return true;
    }
    else
    {
        qWarning() << "Ouvinte: diabo de muié surda!!!";
        return false;
    }
}

void
Ouvinte::incomingConnection( int _socket_descriptor )
{
    Jogador*
    novo_jogador;

    novo_jogador = new Jogador( _socket_descriptor, this->parent() );

    QObject::connect( novo_jogador, SIGNAL(novoDado(QByteArray)),
                      this->parent(), SLOT(recebeDado(QByteArray)));

    emit this->novoJogador( novo_jogador );
}
