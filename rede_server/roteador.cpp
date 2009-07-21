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


    qDebug() << "enviano dados";

    QObject::connect(_novo_jogador,SIGNAL(novoDado(QByteArray)),
                     this,SLOT(recebeDado(QByteArray)));

    QByteArray block;
    QDataStream out(&block, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << "boga boga";
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    _novo_jogador->enviaDado(block);


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
