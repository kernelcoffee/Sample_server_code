#include <QCoreApplication>
#include <QtNetwork/QNetworkInterface>

#include <QDebug>

#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TcpServer server;

    QString ipAddress;
    QHostAddress addr;
    int port = 8900;

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();


    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        qDebug() << "Looking into address " << ipAddressesList.at(i).toString();;
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            addr = ipAddressesList.at(i);
            ipAddress = ipAddressesList.at(i).toString();
            qDebug() << "found address " << ipAddress;
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty()) {
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
        addr = QHostAddress(QHostAddress::LocalHost);
    }

    if (!server.listen(addr, port)) {
        qDebug() << "Server Unable to start the server: "
                 << server.errorString();
        return 0;
    }

    qDebug() << "Listening on port " << server.serverPort()
             << " addr " << addr.toString();

    return a.exec();
}
