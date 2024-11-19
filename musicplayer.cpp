#include "musicplayer.h"
#include "constants.h"

MusicPlayer::MusicPlayer(QPushButton* button, const QString& filePath, QObject* parent)
    : QObject(parent), musicButton(button),
    mediaPlayer(std::make_unique<QMediaPlayer>(this)),
    audioOutput(std::make_unique<QAudioOutput>(this))
{
    mediaPlayer->setAudioOutput(audioOutput.get());
    mediaPlayer->setSource(QUrl(filePath));
    mediaPlayer->setLoops(-1);  // Зациклення пісні
    audioOutput->setVolume(initialVolume);

    mediaPlayer->play();

    musicButton->setStyleSheet("image: " + pathToSoundIcon + ";");

    connect(musicButton, &QPushButton::clicked, this, &MusicPlayer::toggleMusic);
}

void MusicPlayer::toggleMusic() {
    if (mediaPlayer->playbackState() == QMediaPlayer::PlayingState) {
        mediaPlayer->pause();
        musicButton->setStyleSheet("image: " + pathToNoSoundIcon + ";");
    } else {
        mediaPlayer->play();
        musicButton->setStyleSheet("image: " + pathToSoundIcon + ";");
    }
}
