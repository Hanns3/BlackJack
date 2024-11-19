#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "musicplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void displayCard(const std::shared_ptr<CardWidget>& cardWidget, Player* player);
    void displayBack(QPixmap pixmap, int xPos, int yPos);
    void setRefreshButtonImage();
    template <typename T>
    std::shared_ptr<BadgeLabel<T>> displayLabel(T value, int x, int y, QString textColor = "white", int fontSize = 14);


private:
    void humanInit();
    void deckInit();
    void dealerInit();


private slots:
    void on_hit_clicked();

    void on_stand_clicked();

    void on_refreshButton_clicked();

    void on_deckChangeButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Game> game;
    std::unique_ptr<MusicPlayer> musicPlayer;
    std::unique_ptr<QMediaPlayer> soundHitButton;
    std::unique_ptr<QMediaPlayer> soundRefreshButton;
    std::unique_ptr<QAudioOutput> audioOutputHit;
    std::unique_ptr<QAudioOutput> audioOutputStand;
    std::shared_ptr<BadgeLabel<QString>> cardLabelStatus;
    std::vector<std::shared_ptr<CardWidget>> deck;
    std::shared_ptr<BadgeLabel<QString>> cash;
    std::shared_ptr<BadgeLabel<QString>> betLabel;
    std::shared_ptr<BadgeLabel<QString>> setOver;
    int bet;

};
#endif // MAINWINDOW_H
