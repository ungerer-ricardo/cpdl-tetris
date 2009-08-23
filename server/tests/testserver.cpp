#include <QObject>
#include <QtTest>
#include <QSignalSpy>

#include <QTcpSocket>

#include "../ouvinte.h"
#include "../roteador.h"

class TestServer : public QObject
{
    Q_OBJECT
public:

    TestServer();

private slots:

    void
    testStartListen();

    void
    testStopListen();

    void
    testReceiveClient();

    void
    testReceive2Clientes();

private:

    QString
    jogReceive( QTcpSocket* jog );

    void
    jogSend( QTcpSocket* jog, QString msg );

    Rede_Server::Roteador*
    roteador_teste;

    QTcpSocket*
    jog1;

    QTcpSocket*
    jog2;
};

TestServer::TestServer()
{
    this->roteador_teste = new Rede_Server::Roteador(2);
}

void
TestServer::testStartListen()
{
    QTcpSocket*
    con_teste = new QTcpSocket(this);

    QSignalSpy
    watchman(con_teste,SIGNAL(connected()));

    con_teste->connectToHost(QString("LocalHost"),6969);
    con_teste->waitForConnected(1000);

    QCOMPARE( watchman.count() , 1);
}

void
TestServer::testStopListen()
{
    QTcpSocket*
    con_teste = new QTcpSocket(this);

    QSignalSpy
    watchman(con_teste,SIGNAL(error(QAbstractSocket::SocketError)));

    this->roteador_teste->stopListen();

    con_teste->connectToHost(QString("LocalHost"),6969);
    con_teste->waitForConnected(1000);

    QCOMPARE( watchman.count(), 1 );

    QVERIFY( con_teste->error() == QAbstractSocket::ConnectionRefusedError );
}

void
TestServer::testReceiveClient()
{
    delete this->roteador_teste;
    this->roteador_teste = new Rede_Server::Roteador(2);

    QTcpSocket*
    jog1 = new QTcpSocket(this);
    jog1->connectToHost( QString("LocalHost"), 6969 );
    jog1->waitForReadyRead(1000);

    QCOMPARE(this->jogReceive(jog1), QString("init:0"));

    this->jog1 = jog1;
}

void
TestServer::testReceive2Clientes()
{

}

QString
TestServer::jogReceive( QTcpSocket* jog )
{
    quint16 bloco = 0;
    QDataStream in(jog);
    in.setVersion(QDataStream::Qt_4_0);
    in >> bloco;
    QString mensagem;
    in >> mensagem;

    return mensagem;
}

void
TestServer::jogSend( QTcpSocket* jog, QString msg )
{

}

QTEST_MAIN(TestServer)
#include "testserver.moc"
