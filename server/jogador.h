#ifndef JOGADOR_H
#define JOGADOR_H

#include <QSemaphore>
#include <QTcpSocket>

namespace Rede_Server
{

    class Roteador;

    class Jogador : public QObject
    {
        Q_OBJECT
    public:

        Jogador( int _socket_descriptor, Roteador* _parent = 0 );

        ~Jogador();

        bool
        operator== ( quint16 _id_jogador );

        bool
        operator!= ( quint16 _id_jogador );

        unsigned int
        id_jogador;

        QString
        nome_jogador;

    signals:

        void
        novoDado( QString _dado );

        void
        erro( Jogador* );

    public slots:

        void
        erroConexao( QAbstractSocket::SocketError _erro );

        void
        enviaDado( QString _dado );

        void
        dadoChegando();

    protected:

        QTcpSocket*
        conexao;

        int
        socket_descriptor;

    };
}

#endif // JOGADOR_H
