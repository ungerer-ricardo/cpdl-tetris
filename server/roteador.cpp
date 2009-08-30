#include "roteador.h"

#include <QDebug>
#include <QStringList>

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

    this->listaJogadores.push_back( _novo_jogador );

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

    if ( comando_str == "enca" )
    {
        _dado.append(";" + QString::number( qrand() % 7 ) );
    }
    else if ( comando_str == "novo" )
    {
        quint16
        id_jogador = this->getIdJogador(_dado);

        this->setNomeJogador( _dado );
        this->enviaListaJogadores( id_jogador );
        this->broadcastNovoNome( id_jogador );
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


//não testado.
void
Rede_Server::Roteador::setNomeJogador( QString _dado )
{
    quint16
    id_jogador = this->getIdJogador( _dado );

    QString
    novo_nome = _dado.split(";")[1];

    Jogador*
    jogador = this->getJogadorById( id_jogador );

    jogador->nome_jogador = novo_nome;

    QObject::disconnect(this,SIGNAL(broadcast(QString)),
                        jogador,SLOT(enviaDado(QString)));

    this->broadcastNovoNome( id_jogador );

    QObject::connect(this, SIGNAL(broadcast(QString)),
                     jogador,SLOT(enviaDado(QString)));
}

//não testado.
void
Rede_Server::Roteador::broadcastNovoNome( quint16 _id_jogador )
{
    QString
    mensagem = "novo:" +QString::number(_id_jogador)+";";

    Jogador*
    novo_jogador = this->getJogadorById(_id_jogador);

    mensagem.append(novo_jogador->nome_jogador);
}

//não testado.
quint16
Rede_Server::Roteador::getIdJogador( QString _dado )
{
    QString
    id_str = _dado.split(":")[1].split(";")[0];

    return id_str.toInt();
}

//não testado.
Rede_Server::Jogador*
Rede_Server::Roteador::getJogadorById( quint16 _id_jogador )
{
    QList<Rede_Server::Jogador*>::iterator
    it_jogadores;

    for ( it_jogadores = this->listaJogadores.begin();
          it_jogadores != this->listaJogadores.end();
          it_jogadores++ )
    {
        if ( **it_jogadores == _id_jogador )
        {
            return *it_jogadores;
        }
    }

    qWarning() << "Roteador::getJogadorById: nao achei o jogador com a id: "
               << _id_jogador;

    return NULL;
}

//não testado.
void
Rede_Server::Roteador::enviaListaJogadores( quint16 _id_jogador )
{
    QStringList
    listaJogadores;

    QList<Jogador*>::iterator
    it_jogadores;

    QString
    entrada_jogador;

    for ( it_jogadores = this->listaJogadores.begin();
          it_jogadores != this->listaJogadores.end();
          it_jogadores++)
    {
        if ( **it_jogadores != _id_jogador )
        {
            entrada_jogador = QString::number((*it_jogadores)->id_jogador)+","+
                              (*it_jogadores)->nome_jogador;

            listaJogadores << entrada_jogador;
        }
    }

    QString
    msg_lista_jogadores = "novo:";

    msg_lista_jogadores.append( listaJogadores.join(" ") );

    this->getJogadorById(_id_jogador)->enviaDado(msg_lista_jogadores);
}
