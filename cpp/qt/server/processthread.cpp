#include "processthread.h"

ProcessThread::ProcessThread(int sd, QObject *parent) :
    QThread(parent)
  , socketDescriptor(sd)
{
    qDebug() << "new thread created";
}

void ProcessThread::run()
{
    QTcpSocket tcpSocket;
    if (!tcpSocket.setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket.error());
        return;
    }

//    QByteArray block;
//    QDataStream out(&block, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_4_8);
//    out << (quint16)0;
//    out << text;
//    out.device()->seek(0);
//    out << (quint16)(block.size() - sizeof(quint16));
//    tcpSocket.write(block);


    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();
}
