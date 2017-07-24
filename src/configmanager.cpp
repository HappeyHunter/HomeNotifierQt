#include "configmanager.h"
#include "staticitems.h"

#include <QFile>
#include <QTextStream>

ConfigManager::ConfigManager()
{
    loadIdentitySettings();
}

// Loads the identity from the IdentitySettings file
// Just reads the first line and takes that as the identity
void ConfigManager::loadIdentitySettings() {
    QFile identityFile(StaticItems::IDENTITY_FILE);

    if(identityFile.exists() && identityFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream input(&identityFile);

        QString identityLine = input.readLine(64); // Hardcode a size of 64 in here because if the name you are using is bigger than that then you've got a long name

        if(identityLine.length() > 0) {
            userIdentity = identityLine;
        }
    }
}

QString& ConfigManager::getIdentity() {
    return userIdentity;
}

// Will also need this to load the server info if/when I move to tcp
