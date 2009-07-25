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

    QObject::connect(_novo_jogador,SIGNAL(novoDado(QString)),
                     this,SLOT(recebeDado(QString)));

    //avisar a este quantos outros jogadores existem.

    //avisar aos outros conectados que entrou mais um.

    this->listaJogadores.push_back( _novo_jogador );
}

void
Rede_Server::Roteador::recebeDado( QString _dado )
{

}

void
Rede_Server::Roteador::processaComando( ::ComandoParseado& _comando )
{

}
