#include "roteador.h"

#include <QDebug>
/*
  Comandos de roteamento:
    -"init:x" em que x é o número de jogadores já conectados.
    -"novo"
    -"down:x" em que x indica o id do jogador com problemas.
*/

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
Rede_Server::Roteador::stopListen()
{
    this->ouvinte->close();
}

void
Rede_Server::Roteador::novoJogador( Jogador* _novo_jogador )
{
    qDebug() << "Roteador: Novo jogador conectado!!";

    QObject::connect(_novo_jogador,SIGNAL(novoDado(QString)),
                     this,SLOT(recebeDado(QString)));

    /* SERIA LEGAL MODULARIZAR TODAS AS FORMAÇÕES DE COMANDOS */
    QString
    comando_init("init:");

    comando_init.append( QString::number(this->listaJogadores.size()) );
    _novo_jogador->enviaDado(comando_init);

    if ( this->listaJogadores.size() > 0 )
    {
        emit this->broadcast(QString("novo"));
    }

    this->listaJogadores.push_back( _novo_jogador );

    //so deve ser adicionado na lista de broadcast depois que todos ja souberem
    //de sua existencia e que ele saiba da existencia dos outros.
    QObject::connect(this,SIGNAL(broadcast(QString)),
                     _novo_jogador,SLOT(enviaDado(QString)));
}

void
Rede_Server::Roteador::recebeDado( QString _dado )
{

}

void
Rede_Server::Roteador::jogadorCaiu( Jogador* _com_erro )
{
    QObject::disconnect(this,SIGNAL(broadcast(QString)),
                        _com_erro,SLOT(enviaDado(QString)));

    int
    id_jogador = this->listaJogadores.indexOf(_com_erro);

    this->listaJogadores.removeAt(id_jogador);

    QString
    comando_caiu( "down:" + QString::number(id_jogador) );
    emit this->broadcast(comando_caiu);
}
