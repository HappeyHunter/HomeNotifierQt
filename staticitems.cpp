#include "StaticItems.h"
#include <iostream>

const QString StaticItems::IDENTITY_FILE = "Resources/IdentitySettings";
const QString StaticItems::CUSTOM_MESSAGE_FILE = "Resources/customMessage.wav";

const QString StaticItems::CUSTOM_MESSAGE = "Custom Message";

const QString StaticItems::SHUTDOWN_COMMAND = "Shutdown";

const QMap<QString, QString> StaticItems::SOUND_NAMES = {{"Hang Up Washing", "Resources/hangWashing.wav"},
                                                                    {"Putting Wash On", "Resources/puttingOnWash.wav"},
                                                                    {"Pick Dinner", "Resources/pickDinner.wav"},
                                                                    {"Cook Dinner", "Resources/cookDinner.wav"},
                                                                    {"Dinner is ready!", "Resources/dinnerReady.wav"},};

const QMap<QString, QString> StaticItems::BUBBLE_MESSAGES = {{"Hang Up Washing", "The wash is done, hang it up."},
                                                                    {"Putting Wash On", "Putting on a wash, bring down any dirty clothes."},
                                                                    {"Pick Dinner", "What do you want for dinner?"},
                                                                    {"Cook Dinner", "Start cooking dinner."},
                                                                    {"Dinner is ready!", "Dinner is ready!"}};

// Gets the filename for the message or defaults to the custom one
QString StaticItems::getFilename(QString message) {
    QMap<QString, QString>::const_iterator fileName = StaticItems::SOUND_NAMES.find(message);
    if (fileName == StaticItems::SOUND_NAMES.end()) {
        return StaticItems::CUSTOM_MESSAGE_FILE;
    }
    return fileName.value();
}

// Gets the full message from the short one received
QString StaticItems::getMessage(QString shortMessage) {
    QMap<QString, QString>::const_iterator message = StaticItems::BUBBLE_MESSAGES.find(shortMessage);
    if (message == StaticItems::BUBBLE_MESSAGES.end()) {
        return StaticItems::CUSTOM_MESSAGE;
    }
    return message.value();
}
