#include "jogador.h"

Jogador::Jogador( int _socket_descriptor, QObject* _parent )
        : QThread(_parent)
{
    this->conexao = new QTcpSocket(this);

    if ( ! this->conexao->setSocketDescriptor( _socket_descriptor ) )
    {
        //envia erro de conexão
    }

    QObject::connect(this->conexao,SIGNAL(readyRead()),
                     this,SLOT(leNovoDadoRede()));
}

void
Jogador::run()
{
    this->exec();
}

void
Jogador::leNovoDadoRede()
{
    QByteArray
    novoDado = this->conexao->read( 10000 );

    emit this->novoDado( novoDado );
}

void
Jogador::enviaDado( QByteArray& _dado )
{
    this->conexao->write( _dado );
}
