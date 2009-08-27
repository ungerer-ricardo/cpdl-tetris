#include "tradutor.h"
#include <QStringList>

using namespace Rede_Cliente;

Tradutor::Tradutor(QObject *_parent):QObject(_parent)
{

}

void
Tradutor::setConexao(Conexao *_conexao)
{
    this->conexao = _conexao;
    QObject::connect(this->conexao, SIGNAL(outgoingMessage(QString)), this, SLOT(incomingMessage(QString)));

}

void
Tradutor::setConexao(QString _ipServidor, quint16 _portaServidor)
{
    this->conexao = new Conexao();
    this->conexao->connectToHost(_ipServidor, _portaServidor);
    QObject::connect(this->conexao, SIGNAL(outgoingMessage(QString)), this, SLOT(incomingMessage(QString)));

}

void
Tradutor::chat(QString _mensagem)
{
    _mensagem = "chat:" + this->idJogador + ";" + _mensagem;
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
Tradutor::encaixe()
{
    QString _mensagem;
    _mensagem = "enca:" + this->idJogador;
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::incomingMessage(QString _mensagem)
{
    if(this->idJogador.isEmpty())
    {
        this->idJogador = _mensagem.mid(5);
        qDebug() << "Id: " << this->idJogador;
    }

    Comando traduzido = this->traduzir(_mensagem);

    switch (traduzido.comando)
    {
        case INIT:
            qDebug() << "Parseado ENUM: " << traduzido.comando;
            qDebug() << "Parseado ID: " << traduzido.idJogador;
            break;
        case NOVO:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            break;
        case DOWN:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            qDebug() << "Parseado ID:" << traduzido.idJogador;
            break;
        case CHAT:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            qDebug() << "Parseado ID:" << traduzido.idJogador;
            qDebug() << "Parseado Mensagem:" << traduzido.segundoStr;
            break;
        case STAR:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            qDebug() << "Parseado Primeira peca:" << traduzido.idJogador;
            qDebug() << "Parseado Segunda peca:" << traduzido.segundoInt;
            emit this->startjogo(traduzido.idJogador, traduzido.segundoInt);
            break;
        case BUTT:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            qDebug() << "Parseado ID:" << traduzido.idJogador;
            qDebug() << "Parseado Botao:" << traduzido.segundoInt;
            switch (traduzido.segundoInt)
            case 1:
                //sinal para rotacionar
                emit this->button(Qt::Key_Up);
                break;
            case 2:
                //sinal move direita
                emit this->button(Qt::Key_Right);
                break;
            case 3:
                //sinal move esquerda
                emit this->button(Qt::Key_Left);
                break;
            case 4:
                //sinal desce
                emit this->button(Qt::Key_Down);
                break;
            default:
                qDebug() << "deu zica na parada";
                break;
            break;
        case ENCA:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            qDebug() << "Parseado ID:" << traduzido.idJogador;
            qDebug() << "Parseado Proxima Peca:" << traduzido.segundoInt;
            emit this->novapeca(traduzido.segundoInt);
            break;
        default:
            qDebug() << "Parseado ENUM:" << traduzido.comando;
            qDebug() << "Parseado Primeiro:" << traduzido.idJogador;
            qDebug() << "Parseado Segundo Int:" << traduzido.segundoInt;
            qDebug() << "Parseado Segundo String:" << traduzido.segundoStr;
            break;
        }

//    qDebug() << "Tradutor: " << _mensagem;
}

Comando
Tradutor::traduzir(QString _mensagem)
{
    QString comando = _mensagem.split(':')[0];
    qDebug() << "Tradutor: recebi comando: " << comando;


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
