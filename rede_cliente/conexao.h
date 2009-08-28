#ifndef CONEXAO_H
#define CONEXAO_H

#include <QTcpSocket>

namespace Rede_Cliente
{

    class Conexao : public QTcpSocket
    {
        Q_OBJECT

    public:

        Conexao(QObject* = NULL);

    public slots:

        void
        conectar(QString, quint16);

        void
        conectado();

        void
        enviaDado(QString);

        void
        erro(QAbstractSocket::SocketError);

        void
        recebeDado();

    signals:

        void
        outgoingMessage(QString);

    private:

    };
}

#endif // CONEXAO_H
