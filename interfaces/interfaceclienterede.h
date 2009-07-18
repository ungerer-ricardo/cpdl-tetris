#ifndef INTERFACECLIENTEREDE_H
#define INTERFACECLIENTEREDE_H

#include <QObject>

class InterfaceClienteRede : public QObject
{
    Q_OBJECT

    signals:
        void EnviaPecas(qint16);
        void EnviaGameOver();
        void EnviaChat(QString);
        void EnviaEncaixe();
        void EnviaTecla(qint16);
        void EnviaStart();

        void
        RecebePecas(qint16);

        void
        RecebeGameOver();

        void
        RecebeChat(QString);

        void
        RecebeEncaixe();

        void
        RecebeTecla(qint16);

        void
        RecebeStart();
};

#endif // INTERFACECLIENTEREDE_H
