#ifndef PROCESSTHREAD_H
#define PROCESSTHREAD_H

#include <QThread>
#include <QtNetwork/QTcpSocket>

class ProcessThread : public QThread
{
    Q_OBJECT
public:
    explicit ProcessThread(int sd, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:

private:
    int socketDescriptor;
};

#endif // PROCESSTHREAD_H
