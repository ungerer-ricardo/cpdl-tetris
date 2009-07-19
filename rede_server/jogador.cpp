#include "jogador.h"

#include "./roteador.h"

using namespace Rede_Server;

Jogador::Jogador( int _socket_descriptor, QObject* _parent )
        : QThread(_parent)
{
    this->sem_caixa_saida = new QSemaphore(0);
    this->socket_descriptor = _socket_descriptor;
}

Jogador::~Jogador()
{
    this->m_quit.lock();

    this->quit = true;

    this->m_quit.unlock();
}

void
Jogador::run()
{
    qDebug() << "Jogador iniciado na thread " << this->currentThreadId();
    this->quit = false;
    this->conexao = new QTcpSocket();

    QObject::connect(this->conexao,SIGNAL(readyRead()),
                 this,SLOT(leNovoDadoRede()),
                 Qt::DirectConnection);  //pega dados do cido

    QObject::connect(this->conexao,SIGNAL(error(QAbstractSocket::SocketError)),
                     this,SLOT(erroConexao(QAbstractSocket::SocketError)),
                     Qt::DirectConnection); //erro durante a conexao

    if ( ! this->conexao->setSocketDescriptor( this->socket_descriptor ) )
    {
        //envia erro de conexão
    }

    while(! this->quit || this->conexao->isValid() )
    {
        this->sem_caixa_saida->acquire(1);

        this->writeNetwork( this->caixa_saida.front() );

        this->caixa_saida.pop_front();
    }

    this->conexao->disconnectFromHost();
    this->conexao->waitForDisconnected();
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
    this->caixa_saida.push_back( _dado );
    this->sem_caixa_saida->release(1);
}

void
Jogador::writeNetwork( QByteArray _dado )
{
    if ( this->conexao->isWritable() )
    {
        qDebug() << "Jogador " << this->currentThreadId() << ": escrevendo dados na placa";
        this->conexao->write( _dado );
    }
    else
    {
        qDebug() << "Jogador " << this->currentThreadId() << ": nao pude escrever";
        this->erroConexao( QAbstractSocket::NetworkError );
    }
}
