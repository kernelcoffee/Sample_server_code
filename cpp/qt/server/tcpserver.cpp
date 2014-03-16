#include "tcpserver.h"
#include "processthread.h"

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent)
{
    qDebug() << "server created";
}

void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    ProcessThread* thread = new ProcessThread(socketDescriptor, this);
    connect(thread, &QThread::finished,
            thread, &QThread::deleteLater);
    thread->start();
}
