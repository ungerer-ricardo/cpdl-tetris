#ifndef JOGADOR_H
#define JOGADOR_H

#include <QMutex>
#include <QTcpSocket>
#include <QThread>

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

private:

    QTcpSocket*
    conexao;

    QMutex
    nao_enviado_mutex;

    QThread*
    filha;

    int
    socket_descriptor;
};

#endif // JOGADOR_H
