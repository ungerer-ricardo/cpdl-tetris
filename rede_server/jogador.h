#ifndef JOGADOR_H
#define JOGADOR_H

#include <QList>
#include <QMutex>
#include <QSemaphore>
#include <QTcpSocket>
#include <QThread>


namespace Rede_Server
{

    class Roteador;

    class Jogador : public QThread
    {
        Q_OBJECT
    public:

        Jogador( int _socket_descriptor, QObject* _parent = 0 );

        ~Jogador();

        void
        run();

    signals:

        void
        novoDado( QByteArray _dado );

        void
        erro();

    public slots:

        void
        leNovoDadoRede();

        void
        erroConexao( QAbstractSocket::SocketError _erro );

        void
        enviaDado( QByteArray& _dado );

    protected:

        void
        writeNetwork( QByteArray _dado );

    private:

        QTcpSocket*
        conexao;

        int
        socket_descriptor;

        QList<QByteArray>
        caixa_saida;

        QSemaphore*
        sem_caixa_saida;

        bool
        quit;

        QMutex
        m_quit;
    };
};

#endif // JOGADOR_H
