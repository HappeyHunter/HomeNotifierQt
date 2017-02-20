#ifndef STATICITEMS_H_
#define STATICITEMS_H_

#include <QString>
#include <QMap>

class StaticItems {

public:
    static QString const IDENTITY_FILE;
    static QString const CUSTOM_MESSAGE_FILE;

    static QString const CUSTOM_MESSAGE;
    static QString const SHUTDOWN_COMMAND;

    static QMap<QString, QString> const SOUND_NAMES;
    static QMap<QString, QString> const BUBBLE_MESSAGES;

    static QString getFilename(QString);
    static QString getMessage(QString);
};


#endif /* STATICITEMS_H_ */
