#include "roteador.h"

#include <QDebug>

Roteador::Roteador( QObject* _parent )
        : QObject(_parent)
{
    this->ouvinte = new Ouvinte(this);

    this->ouvinte->startListen();
    qDebug() << "Roteador: iniciado!";
}

Roteador::~Roteador()
{

}

void
Roteador::novoJogador( Jogador* _novo_jogador )
{
    qDebug() << "Roteador: Novo jogador conectado!!";
    QByteArray boga("boga boga boga");

    this->listaJogadores.push_back( _novo_jogador );
}

void
Roteador::recebeDado( QByteArray _dado )
{

}

void
Roteador::processaComando( ComandoParseado& _comando )
{

}
