#include "conexao.h"

using namespace Rede_Cliente;

Conexao::Conexao(QObject* _parent):QTcpSocket(_parent)
{
    QObject::connect(this, SIGNAL(connected()), this, SLOT(conectado()));
    QObject::connect(this, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(erro(QAbstractSocket::SocketError)));
    QObject::connect(this, SIGNAL(readyRead()), this, SLOT(recebeDado()));
}


void
Conexao::conectar(QString _ipServidor, quint16 _portaServidor)
{
    this->connectToHost(_ipServidor, _portaServidor);
}

void
Conexao::conectado()
{
    qDebug() << "Conectado";
}

void
Conexao::enviaDado(QString _dado)
{
    if(this->isWritable())
    {
        QByteArray bloco;
        QDataStream saida(&bloco, QIODevice::ReadWrite);
        saida.setVersion(QDataStream::Qt_4_0);
        saida << (quint16)0;
        saida << _dado;
        saida.device()->seek(0);
        saida << (quint16)(bloco.size() - sizeof(quint16));

        this->write(bloco);
    }

    else
    {
        qDebug() << "Erro ao escrever: o cara é analfabeto.";
    }
}

void
Conexao::erro(QAbstractSocket::SocketError _erroConexao)
{
    qWarning() << "Deu merda na conexao: " << this->errorString();
}

void
Conexao::recebeDado()
{
    qDebug() << "Tem dado para ler";

    quint16 bloco = 0;
    QDataStream entrada(this);
    entrada.setVersion(QDataStream::Qt_4_0);

    if(this->bytesAvailable() < sizeof(quint16))
        return;

    entrada >> bloco;

    if(this->bytesAvailable() < bloco)
        return;

    QString mensagem;
    entrada >> mensagem;

    qDebug() << mensagem;

    emit this->incommingMessage(mensagem);
}
