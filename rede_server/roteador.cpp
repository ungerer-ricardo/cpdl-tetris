#include "roteador.h"

#include <QDebug>

Rede_Server::Roteador::Roteador( QObject* _parent )
        : QObject(_parent)
{
    this->ouvinte = new Ouvinte(this);

    this->ouvinte->startListen();
    qDebug() << "Roteador: iniciado!";
}

Rede_Server::Roteador::~Roteador()
{

}

void
Rede_Server::Roteador::novoJogador( Jogador* _novo_jogador )
{
    qDebug() << "Roteador: Novo jogador conectado!!";


    QByteArray dado ("boga boga boga");

    qDebug() << "enviano dados";
    _novo_jogador->enviaDado( dado );

    qDebug() << "enviano dados";
    _novo_jogador->enviaDado( dado );

    qDebug() << "enviano dados";
    _novo_jogador->enviaDado( dado );

    this->listaJogadores.push_back( _novo_jogador );
}

void
Rede_Server::Roteador::recebeDado( QByteArray _dado )
{

}

void
Rede_Server::Roteador::processaComando( ::ComandoParseado& _comando )
{

}
