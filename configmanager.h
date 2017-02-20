#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>

class ConfigManager
{
public:
    ConfigManager();

    QString& getIdentity();

private:
    void loadIdentitySettings();

private:
    QString userIdentity;
};

#endif // CONFIGMANAGER_H
