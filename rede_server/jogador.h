#ifndef JOGADOR_H
#define JOGADOR_H

#include <QTcpSocket>
#include <QThread>

class Jogador : public QThread
{
    Q_OBJECT
public:

    Jogador( int _socket_descriptor, QObject* _parent = 0 );

    void
    run();

signals:

    void
    novoDado( QByteArray _dado );

public slots:

    void
    leNovoDadoRede();

protected:

    void
    enviaDado( QByteArray& _dado );

private:

    QTcpSocket*
    conexao;

};

#endif // JOGADOR_H
