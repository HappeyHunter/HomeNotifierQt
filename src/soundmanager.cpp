#include "soundmanager.h"
#include "staticitems.h"

#include <QDir>
#include <QFileInfo>

SoundManager::SoundManager()
{
    player.reset(new QMediaPlayer);
}

// Plays the sound associated with the message
void SoundManager::playSound(QString message) {
    QString soundFile = StaticItems::getFilename(message);

    player->setMedia(QUrl::fromLocalFile(QFileInfo(soundFile).absoluteFilePath()));
    player->setVolume(100);
    player->play();
}
