#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QUdpSocket>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    NetworkManager();
    void getNextNotification();
    void sendAcknowledgement();
    void initLegacy();
    QString getLegacy();

public:

private slots:
    void legacyReceived();

private:
    void stillPresent();
    void startConnection();

private:
    QScopedPointer<QUdpSocket> legacySocket;

signals:
    void legacy(QString notificationString);
};

#endif // NETWORKMANAGER_H
