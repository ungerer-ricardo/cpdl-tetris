#include "tradutor.h"
#include <QStringList>
#include <QStringListIterator>
#include <QList>

using namespace Rede_Cliente;

Tradutor::Tradutor(QWidget *_parent):QWidget(_parent)
{
    this->conexao = new Conexao(this);

    QObject::connect(this->conexao, SIGNAL(connected()),
                     this, SLOT(conexaoEstabelecidaInterna()));
    QObject::connect(this->conexao, SIGNAL(error(QAbstractSocket::SocketError)),
                     this, SLOT(erroConexaoInterna(QAbstractSocket::SocketError)));
    QObject::connect(this->conexao, SIGNAL(incommingMessage(QString)),
                     this, SLOT(incomingMessage(QString)));
}

Tradutor::~Tradutor()
{
}

void
Tradutor::chat(QString _mensagem)
{
    _mensagem = "chat:" + this->idJogador + ";" + _mensagem;
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::conectar(QString _ipServidor, quint16 _portaServidor, QString _nomeJogador)
{
    this->conexao->connectToHost(_ipServidor, _portaServidor);
    this->nomeJogador = _nomeJogador;
}

void
Tradutor::conexaoEstabelecidaInterna()
{
    qDebug() << "Tradutor: A Conexao foi estabelecida.";
    qDebug() << "Tradutor: Jogador: " << this->nomeJogador;

    emit this->conexaoEstabelecida();
    qDebug() << "Tradutor: Sinal conexaoEstabelecida() emitido.";
}

void
Tradutor::desce()
{
    QString _mensagem;
    _mensagem = "butt:" + this->idJogador + ";4";
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::encaixe()
{
    QString _mensagem;
    _mensagem = "enca:" + this->idJogador;
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::enviaNome()
{
    QString _mensagem;
    _mensagem = "novo:" + this->idJogador + ";" + this->nomeJogador;
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::erroConexaoInterna(QAbstractSocket::SocketError _erroConexao)
{
    Q_UNUSED(_erroConexao);
    qWarning() << "Tradutor: Deu merda na conexao: " << this->conexao->errorString();

    emit this->erroConexao(this->conexao->errorString());
    qDebug() << "Tradutor: Sinal erroConexao() emitido.";
}

void
Tradutor::getListaJogadores(QString _listaJogadores)
{
    QString
    jogador = this->idJogador + ";" + this->nomeJogador;

    quint16 id;
    QString nome;

    qDebug() << "Tradutor::getListaJogadores(): " << _listaJogadores;
    _listaJogadores = _listaJogadores.split(':')[1];
    qDebug() << "Tradutor::getListaJogadores(): " << _listaJogadores;
    qDebug() << "jogador: " << jogador;
    if(_listaJogadores.split(' ').last() == jogador)
    {
        QStringList jogadores = _listaJogadores.split(' ');
        for(int i=0; i<jogadores.size(); i++)
        {
            id = jogadores[i].split(';')[0].toInt();
            nome = jogadores[i].split(';')[1];
            emit this->novoJogador(id, nome);
            qDebug() << "Tradutor::getListaJogadores(): ID: " << id;
            qDebug() << "Tradutor::getListaJogadores(): Nome: " << nome;
        }
    }
    else
    {
        jogador = _listaJogadores.split(' ').last();
        id = jogador.split(';')[0].toInt();
        nome = jogador.split(';')[1];
        emit this->novoJogador(id, nome);
        qDebug() << "Tradutor::getListaJogadores(): ID: " << id;
        qDebug() << "Tradutor::getListaJogadores(): Nome: " << nome;
    }
}

int
Tradutor::getPrimeiroParametro(QString _mensagem)
{
    return _mensagem.split(':')[1].split(';')[0].toInt();
}

QString
Tradutor::getSegundoParametroStr(QString _mensagem)
{
    return _mensagem.split(";")[1];
}

int
Tradutor::getSegundoParametroInt(QString _mensagem)
{
    return this->getSegundoParametroStr(_mensagem).toInt();
}

void
Tradutor::movimentaDireita()
{
    QString _mensagem;
    _mensagem = "butt:" + this->idJogador + ";2";
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::movimentaEsquerda()
{
    QString _mensagem;
    _mensagem = "butt:" + this->idJogador + ";3";
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::rotacao()
{
    QString _mensagem;
    _mensagem = "butt:" + this->idJogador + ";1";
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::incomingMessage(QString _mensagem)
{
    if(this->idJogador.isEmpty())
    {
        this->idJogador = _mensagem.mid(5);
        qDebug() << "Tradutor: Id: " << this->idJogador;
    }

    Comando traduzido = this->traduzir(_mensagem);

    switch (traduzido.comando)
    {
        case INIT:
            qDebug() << "Tradutor: Parseado ENUM: " << traduzido.comando;
            qDebug() << "Tradutor: Parseado ID: " << traduzido.idJogador;
            this->enviaNome();
            break;
        case NOVO:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            break;
        case DOWN:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            qDebug() << "Tradutor: Parseado ID:" << traduzido.idJogador;
            emit this->down(traduzido.idJogador);
            break;
        case CHAT:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            qDebug() << "Tradutor: Parseado ID:" << traduzido.idJogador;
            qDebug() << "Tradutor: Parseado Mensagem:" << traduzido.segundoStr;
            emit this->chat(traduzido.idJogador, traduzido.segundoStr);
            break;
        case STAR:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            qDebug() << "Tradutor: Parseado Primeira peca:" << traduzido.idJogador;
            qDebug() << "Tradutor: Parseado Segunda peca:" << traduzido.segundoInt;
            emit this->startjogo(traduzido.idJogador, traduzido.segundoInt);
            break;
        case BUTT:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            qDebug() << "Tradutor: Parseado ID:" << traduzido.idJogador;
            qDebug() << "Tradutor: Parseado Botao:" << traduzido.segundoInt;
            switch (traduzido.segundoInt)
            {
                case 1:
//                    emit this->button(Qt::Key_Up);
                    emit this->rotacionaPeca(traduzido.idJogador);
                    break;
                case 2:
//                    emit this->button(Qt::Key_Right);
                    emit this->movePecaDireita(traduzido.idJogador);
                    break;
                case 3:
//                    emit this->button(Qt::Key_Left);
                    emit this->movePecaEsquerda(traduzido.idJogador);
                    break;
                case 4:
//                    emit this->button(Qt::Key_Down);
                    emit this->descePeca(traduzido.idJogador);
                    break;
                default:
                    qDebug() << "Tradutor: deu zica na parada";
                    break;
                }
            break;
        case ENCA:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            qDebug() << "Tradutor: Parseado ID:" << traduzido.idJogador;
            qDebug() << "Tradutor: Parseado Proxima Peca:" << traduzido.segundoInt;
            emit this->novapeca(traduzido.idJogador, traduzido.segundoInt);
            break;
        default:
            qDebug() << "Tradutor: Parseado ENUM:" << traduzido.comando;
            qDebug() << "Tradutor: Parseado Primeiro:" << traduzido.idJogador;
            qDebug() << "Tradutor: Parseado Segundo Int:" << traduzido.segundoInt;
            qDebug() << "Tradutor: Parseado Segundo String:" << traduzido.segundoStr;
            break;
        }

//    qDebug() << "Tradutor: " << _mensagem;
}

Comando
Tradutor::traduzir(QString _mensagem)
{
    QString comando = _mensagem.split(':')[0];
    qDebug() << "Tradutor: comando a parceado: " << comando;


    Comando parseado;

    if(comando == "butt")
    {
        parseado.comando = BUTT;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
        parseado.segundoInt = this->getSegundoParametroInt(_mensagem);
    }
    else if (comando == "enca")
    {
        parseado.comando = ENCA;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
        parseado.segundoInt = this->getSegundoParametroInt(_mensagem);
    }
    else if(comando == "chat")
    {
        parseado.comando = CHAT;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
        parseado.segundoStr = this->getSegundoParametroStr(_mensagem);
    }
    else if(comando == "novo")
    {
        parseado.comando = NOVO;
        this->getListaJogadores(_mensagem);
    }
    else if(comando == "init")
    {
        parseado.comando = INIT;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
    }
    else if(comando == "down")
    {
        parseado.comando = DOWN;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
    }
    else if(comando == "star")
    {
        parseado.comando = STAR;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
        parseado.segundoInt = this->getSegundoParametroInt(_mensagem);
    }
    return parseado;
}



//teste
//void
//Tradutor::keyPressEvent(QKeyEvent *key)
//{
//    switch(key->key())
//    {
//        case Qt::Key_Up:
//            this->rotacao();
//            break;
//        case Qt::Key_Right:
//            this->movimentaDireita();
//            break;
//        case Qt::Key_Left:
//            this->movimentaEsquerda();
//            break;
//        case Qt::Key_Down:
//            this->desce();
//            break;
//        case Qt::Key_Space:
//            emit this->encaixe();
//            break;
//    }
//}
