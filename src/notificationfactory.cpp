#include "notificationfactory.h"
#include "staticitems.h"

#include <QStringList>

NotificationFactory::NotificationFactory()
{

}

// Builds the notification entity for the legacy notification
NotificationEntity* NotificationFactory::getLegacyNotification(QString& identity, QString notificationString) {
    NotificationEntity* aNotification = NULL;

    QStringList splitString = notificationString.split("::");

    QString target((QString) splitString.at(0));
    QString message((QString) splitString.at(1));

    if(splitString.size() == 2 && (target.compare("All", Qt::CaseInsensitive) == 0 || (identity.length() > 0 && target.compare(identity, Qt::CaseInsensitive) == 0))) {
        aNotification = new NotificationEntity(NULL, splitString.at(1), StaticItems::getMessage(message.simplified()), -1);
    }

    return aNotification;
}
