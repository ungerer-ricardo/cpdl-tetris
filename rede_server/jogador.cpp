#include "jogador.h"

#include "./roteador.h"

Jogador::Jogador( int _socket_descriptor, QObject* _parent )
        : QThread(_parent)
{
    this->socket_descriptor = _socket_descriptor;
}

Jogador::~Jogador()
{
    this->conexao->close();

    if (this->isRunning())
    {
        this->terminate();
    }

    delete this->conexao;
}

void
Jogador::run()
{
    this->conexao = new QTcpSocket();
    this->filha = this->thread();

    QObject::connect(this->conexao,SIGNAL(readyRead()),
                 this,SLOT(leNovoDadoRede()),
                 Qt::DirectConnection);

    QObject::connect(this->conexao,SIGNAL(error(QAbstractSocket::SocketError)),
                     this,SLOT(erroConexao(QAbstractSocket::SocketError)),
                     Qt::DirectConnection);

    if ( ! this->conexao->setSocketDescriptor( this->socket_descriptor ) )
    {
        //envia erro de conexão
    }

    QByteArray boga("0");       // hein?!?!?
    this->enviaDado(boga);      // é... gambeta bruta memo!!

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
Jogador::erroConexao( QAbstractSocket::SocketError _erro )
{
    Q_UNUSED( _erro );

    qWarning() << "Jogador " << this->currentThreadId() << ": ih! A conexão caiu!";
    this->conexao->close();

    emit this->erro();
    this->exit(1);
}

void
Jogador::enviaDado( QByteArray& _dado )
{
    qDebug() << "Jogador " << this->currentThreadId() << " enviando dados";

    this->conexao->write( _dado );
    qDebug() << "Jogador " << this->currentThreadId() <<" dados enviados";
}
