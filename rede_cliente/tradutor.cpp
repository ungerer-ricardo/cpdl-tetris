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
    QObject::connect(this->conexao, SIGNAL(incommingMessage(QString)), this, SLOT(incommingMessage(QString)));

}

void
Tradutor::chat(QString _mensagem)
{
    _mensagem = "chat:" + this->idJogador + ";" + _mensagem;
    this->conexao->enviaDado(_mensagem);
}

void
Tradutor::incommingMessage(QString _mensagem)
{
    if(this->idJogador.isEmpty())
    {
        this->idJogador = _mensagem.mid(5);
        qDebug() << "Id: " << this->idJogador;
    }

    Comando traduzido = this->traduzir(_mensagem);

    //switch traduzido

//    qDebug() << "Tradutor: " << _mensagem;
}

Comando
Tradutor::traduzir(QString _mensagem)
{
    QString comando = _mensagem.split(':')[0];
    qDebug() << "Tradutor: recebi comando: " << comando;


    Comando parseado;

    if(comando == "init")
    {
        parseado.comando = INIT;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
    }
    else if(comando == "novo")
    {
        parseado.comando = NOVO;
    }
    else if(comando == "down")
    {
        parseado.comando = DOWN;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
    }
    else if(comando == "chat")
    {
        parseado.comando = CHAT;
        parseado.idJogador = this->getPrimeiroParametro(_mensagem);
        parseado.segundoStr = this->getSegundoParametroStr(_mensagem);
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
