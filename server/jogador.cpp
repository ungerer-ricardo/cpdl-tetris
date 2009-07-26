#include "jogador.h"

#include "./roteador.h"

using namespace Rede_Server;

Jogador::Jogador( int _socket_descriptor, Roteador* _parent )
        : QObject(_parent)
{
    qDebug() << "Novo jogador iniciando";

    this->conexao = new QTcpSocket(this);

    if (! this->conexao->setSocketDescriptor( _socket_descriptor))
    {
        //envia erro
    }

    QObject::connect(this->conexao,SIGNAL(readyRead()),
                     this,SLOT(dadoChegando()));

    QObject::connect(this->conexao,SIGNAL(error(QAbstractSocket::SocketError)),
                     this,SLOT(erroConexao(QAbstractSocket::SocketError)));
}

Jogador::~Jogador()
{
    if (this->conexao->isOpen())
    {
        this->conexao->close();
    }
}

void
Jogador::erroConexao( QAbstractSocket::SocketError _erro )
{
    Q_UNUSED( _erro );

    qWarning() << "Jogador : ih! A conex�o caiu!";
    this->conexao->close();

    emit this->erro();
}

void
Jogador::enviaDado( QString& _dado )
{
    if ( this->conexao->isWritable() )
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::ReadWrite);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint16)0;
        out << _dado;
        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));

        qDebug() << "Jogador: escrevendo dados na placa";
        this->conexao->write( block );
    }
    else
    {
        qDebug() << "Jogador: nao pude escrever";
        this->erroConexao( QAbstractSocket::NetworkError );
    }
}

void
Jogador::dadoChegando()
{
    quint16 bloco = 0;
    QDataStream in(this->conexao);
    in.setVersion(QDataStream::Qt_4_0);

    if (bloco == 0) {
        if (this->conexao->bytesAvailable() < (int)sizeof(quint16))
            return; //erro ao ler pacote

        in >> bloco;
    }

    if ( this->conexao->bytesAvailable() < bloco )
        return; //erro ao ler pacote

    QString mensagem;
    in >> mensagem;

    qDebug() << "Jogador: Chegou um dado aqui hein: "<< mensagem;
    emit this->novoDado(mensagem);
}