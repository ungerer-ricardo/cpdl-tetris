#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>

class TetrixServer : public QTcpServer
{
public:
    TetrixServer();
};

#endif // SERVER_H
