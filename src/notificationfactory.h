#ifndef NOTIFICATIONFACTORY_H
#define NOTIFICATIONFACTORY_H

#include "notificationentity.h"

class NotificationFactory
{
public:
    static NotificationEntity* getLegacyNotification(QString& identity, QString notificationString);

private:
    NotificationFactory();
};

#endif // NOTIFICATIONFACTORY_H
