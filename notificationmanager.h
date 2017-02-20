#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QObject>

#include "networkmanager.h"
#include "configmanager.h"
#include "notificationentity.h"

class NotificationManager : public QObject
{
    Q_OBJECT
public:
    NotificationManager();

public slots:
    void getLegacyNotification(QString notificationString);

private:
    NetworkManager network;
    ConfigManager config;
    QVector<NotificationEntity*> waitingNotifications;

signals:
    void newNotification(NotificationEntity* legacyNotification);
};

#endif // NOTIFICATIONMANAGER_H
