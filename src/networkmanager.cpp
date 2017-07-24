#include "networkmanager.h"

NetworkManager::NetworkManager()
{

}

// This will start the tcp connection
void NetworkManager::startConnection() {
    //WIP
}

// Need this so I can use the fancy new one until I update the server to the new system as well (Still weighing the need for it)
void NetworkManager::initLegacy() {
    legacySocket.reset(new QUdpSocket(this));
    legacySocket->bind(QHostAddress::Any, 3141);

    connect(legacySocket.data(), SIGNAL(readyRead()), this, SLOT(legacyReceived()));
}

// Received a legacy (UDP) notification so read it and emit back up the chain
void NetworkManager::legacyReceived() {
    while(legacySocket->hasPendingDatagrams()) {
        QString legacyString;
        QByteArray datagram;
        datagram.resize(legacySocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        legacySocket->readDatagram(datagram.data(), datagram.size(),
                                    &sender, &senderPort);

        legacyString = QString(datagram);

        emit legacy(legacyString);
    }
}

// Heartbeat for the TCP connection stuff
void NetworkManager::stillPresent() {
    //WIP
}

// Get the next notification from the TCP connection
void NetworkManager::getNextNotification() {
    //WIP
}

// Sends the acknowledgement response to the server for when a notification is acknowledged/removed
void NetworkManager::sendAcknowledgement() {
    //WIP
}
