#include "roteador.h"

#include <QDebug>

Rede_Server::Roteador::Roteador( int _njogadores, QObject* _parent )
        : QObject(_parent)
{
    qsrand( QTime::currentTime().msec() );
    this->njogadores = _njogadores;

    this->ouvinte = new Ouvinte(this);

    this->ouvinte->startListen();
    qDebug() << "Roteador: iniciado!";

    this->current_id = 1;
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

    QObject::connect(_novo_jogador,SIGNAL(erro( Jogador* )),
                     this,SLOT(jogadorCaiu(Jogador*)));

    /* SERIA LEGAL MODULARIZAR TODAS AS FORMAÇÕES DE COMANDOS */
    QString
    comando_init("init:");

    comando_init.append( QString::number(this->current_id) );
    _novo_jogador->id_jogador = this->current_id;
    ++this->current_id;

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

    if ( this->listaJogadores.size() == this->njogadores )
    {
        qDebug() << "roteador:iniciando o jogo!";
        this->startJogo();
    }
}

void
Rede_Server::Roteador::recebeDado( QString _dado )
{
    QString
    comando_str = _dado.left(4).toLower();

    if ( comando_str == "butt" && _dado.right(7) == "encaixe")
    {
        _dado.append(";" + QString::number( qrand() % 7 ) );
    }

    emit this->broadcast(_dado);
}

void
Rede_Server::Roteador::jogadorCaiu( Jogador* _com_erro )
{
    QObject::disconnect(this,SIGNAL(broadcast(QString)),
                        _com_erro,SLOT(enviaDado(QString)));

    int
    id_vetor = this->listaJogadores.indexOf(_com_erro),
    id_jogador = _com_erro->id_jogador;

    this->listaJogadores.removeAt(id_vetor);

    QString
    comando_caiu( "down:" +  QString::number(id_jogador));
    qDebug() << "Roteador: jogador " << id_jogador << " caiu!";
    emit this->broadcast(comando_caiu);
}

void
Rede_Server::Roteador::startJogo()
{
    this->stopListen();
    qDebug() << "roteador: to startano fia!";

    sleep(1);
    QString
    comando_start("star:");

    comando_start.append( QString::number( qrand() % 5 ) + ";" );
    comando_start.append( QString::number( qrand() % 5 ) );

    emit this->broadcast(comando_start);
}
