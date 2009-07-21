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

    qWarning() << "Jogador : ih! A conexão caiu!";
    this->conexao->close();

    emit this->erro();
}

void
Jogador::enviaDado( QByteArray& _dado )
{
    if ( this->conexao->isWritable() )
    {
        qDebug() << "Jogador: escrevendo dados na placa";
        this->conexao->write( _dado.toUpper() );
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
    qDebug() << "Jogador: Chegou um dado aqui hein";

    QByteArray
    dado_chegante = this->conexao->readLine(64);
    qDebug() << (QString) dado_chegante;

}
