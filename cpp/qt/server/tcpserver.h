#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork/QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);

protected:
    void incomingConnection(qintptr socketDescriptor);

signals:

public slots:

};

#endif // TCPSERVER_H
