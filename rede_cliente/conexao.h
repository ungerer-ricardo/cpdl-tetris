#ifndef CONEXAO_H
#define CONEXAO_H

#include <QTcpSocket>

namespace Rede_Cliente
{
    class Tradutor;

    class Conexao : public QTcpSocket
    {
        Q_OBJECT

    public:

        Conexao(Tradutor*);

    public slots:

        void
        enviaDado(QString);

        void
        recebeDado();

    signals:

        void
        incommingMessage(QString);
    };
}

#endif // CONEXAO_H
