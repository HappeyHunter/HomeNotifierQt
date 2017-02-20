#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QMediaPlayer>

class SoundManager
{
public:
    SoundManager();
    void playSound(QString message);

private:
    QScopedPointer<QMediaPlayer> player;
};

#endif // SOUNDMANAGER_H
