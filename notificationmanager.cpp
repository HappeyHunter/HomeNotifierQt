#include "notificationmanager.h"
#include "notificationfactory.h"

NotificationManager::NotificationManager()
{
    network.initLegacy();

    connect(&network, SIGNAL(legacy(QString)), this, SLOT(getLegacyNotification(QString)));
}

// Gets the notification received
void NotificationManager::getLegacyNotification(QString notificationString) {

    NotificationEntity* legacyNotification = NotificationFactory::getLegacyNotification(config.getIdentity(), notificationString);

    if(legacyNotification) {
        //waitingNotifications.push_back(legacyNotification);

        emit newNotification(legacyNotification);
    }
}

