#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "card.h"
#include "deck.h"
#include <QLabel>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Deck deck;
    int xPos = 500, yPos = 500;
    for(int i = 0; i < 2; i++) {
        displayCard(deck.drawCard(), xPos, yPos);
        xPos += 20;
    }
    displayCard(deck.getBack(), xPos, yPos);
}

void MainWindow::displayCard(const Card &card, int xPos, int yPos) {
    QLabel *cardLabel = new QLabel(this);
    cardLabel->setFixedSize(100, 150); // Встановлюємо розмір QLabel для карти
    cardLabel->setPixmap(card.getImage().scaled(cardLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Масштабуємо зображення
    cardLabel->setScaledContents(true); // Дозволяємо QLabel автоматично масштабувати зображення
    cardLabel->move(xPos, yPos); // Задаємо позицію QLabel
    cardLabel->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}
