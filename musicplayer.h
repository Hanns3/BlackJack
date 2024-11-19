#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPushButton>
#include <memory>

class MusicPlayer : public QObject {
    Q_OBJECT

public:
    explicit MusicPlayer(QPushButton* button, const QString& filePath, QObject* parent = nullptr);

private slots:
    void toggleMusic();

private:
    QPushButton* musicButton;
    std::unique_ptr<QMediaPlayer> mediaPlayer;
    std::unique_ptr<QAudioOutput> audioOutput;
};

#endif // MUSICPLAYER_H
