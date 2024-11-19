    #include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "card.h"
#include "badgelabel.h"
#include "constants.h"
#include "deckchange.h"
#include <QLabel>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , bet(initialBet)
    , soundHitButton(std::make_unique<QMediaPlayer>(this))
    , audioOutputHit(std::make_unique<QAudioOutput>(this))
    , soundRefreshButton(std::make_unique<QMediaPlayer>(this))
    , audioOutputStand(std::make_unique<QAudioOutput>(this))
{
    ui->setupUi(this);
    
    game = std::make_unique<Game>();

    musicPlayer = std::make_unique<MusicPlayer>(ui->musicButton, pathToBackgroundMusic, this);
    soundHitButton->setSource(QUrl(pathToCardDropSound));
    soundHitButton->setAudioOutput(audioOutputHit.get());

    soundRefreshButton->setSource(QUrl(pathToRestartGameSound));
    soundRefreshButton->setAudioOutput(audioOutputStand.get());

    humanInit();
    dealerInit();
    deckInit();
    ui->refreshButton->setDisabled(true);

    cash = displayLabel("Cash: " + QString::number(game->getHuman()->getBalance()) + "$", humanCardInitialPositionX - shiftCashLabelX,
                        humanCardInitialPositionY + shiftCashLabelY, colorCashLabel, fontSizeCashAndBet);
    betLabel = displayLabel("Bet: " + QString::number(bet) + "$", humanCardInitialPositionX + shiftBetLabelX,
                            humanCardInitialPositionY + shiftBetLabelY, colorBetLabel, fontSizeCashAndBet);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayBack(QPixmap pixmap, int xPos, int yPos) {
    auto cardWidget = std::make_shared<CardWidget>(game->getDeck()->getBack(), this);
    deck.push_back(cardWidget);
    cardWidget->move(xPos, yPos);
    cardWidget->show();
}

void MainWindow::displayCard(const std::shared_ptr<CardWidget>& cardWidget, Player* player) {
    cardWidget->move(player->getHandPosX(), player->getHandPosY());
    cardWidget->show();
    cardWidget->animateEntry();

    player->setHandPosX(player->getHandPosX() + shiftCardX);
}


template <typename T>
std::shared_ptr<BadgeLabel<T>> MainWindow::displayLabel(T value, int x, int y, QString textColor, int fontSize)
{
    auto badge = std::make_shared<BadgeLabel<T>>(value, this, textColor, fontSize);
    badge->move(x, y);
    badge->show();
    return badge;
}

void MainWindow::humanInit() {
    for (const auto& card : game->getHuman()->getHand()) {
        auto cardWidget = std::make_shared<CardWidget>(card.getFront(), this);
        displayCard(cardWidget, game->getHuman());
        game->getHuman()->addCardWidget(cardWidget);
    }

    auto badge = displayLabel(game->getHuman()->getPoints(),
        game->getHuman()->getHandPosX(),
        game->getHuman()->getHandPosY() - cardLabelShift
        );
    game->getHuman()->setBadge(badge);
}

void MainWindow::deckInit()
{
    for(int i = 0, xPos = deckInitialPositionX, yPos = deckInitialPositionY; i < 5; i++) {
        displayBack(game->getDeck()->getBack(), xPos, yPos);
        xPos += shiftDeckX;
        yPos -= shiftDeckY;
    }
}

void MainWindow::dealerInit() {
    std::vector<Card> hand = game->getDealer()->getHand();

    for (size_t i = 0; i < hand.size() - 1; ++i) {
        auto cardWidget = std::make_shared<CardWidget>(hand[i].getFront(), this);
        displayCard(cardWidget, game->getDealer());
        game->getDealer()->addCardWidget(cardWidget);
    }

    auto cardWidget = std::make_shared<CardWidget>(game->getDeck()->getBack(), this);
    displayCard(cardWidget, game->getDealer());
    game->getDealer()->addCardWidget(cardWidget);
}


void MainWindow::on_hit_clicked()
{
    soundHitButton->play();
    Card card = game->getDeck()->drawCard();
    game->getHuman()->addCardToHand(card);

    auto newCardWidget = std::make_shared<CardWidget>(card.getFront(), this);
    game->getHuman()->addCardWidget(newCardWidget);
    displayCard(newCardWidget, game->getHuman());

    if (game->getHuman()->getPoints() > gamePoint) {
        on_stand_clicked();
    }
}


void MainWindow::on_stand_clicked()
{
    game->getDealer()->revealHand();
    displayCard(game->getDealer()->getLast(), game->getDealer());
    auto badge = displayLabel(game->getDealer()->getPoints(), game->getDealer()->getHandPosX(),
                                          game->getDealer()->getHandPosY() - cardLabelShift);
    game->getDealer()->setBadge(badge);
    if((game->getHuman()->getPoints() <= gamePoint && game->getHuman()->getPoints() > game->getDealer()->getPoints())
        || (game->getHuman()->getPoints() <= gamePoint && game->getDealer()->getPoints() > gamePoint))
    {
        cardLabelStatus = displayLabel(QString("WIN"), game->getHuman()->getHandPosX(),
                                game->getHuman()->getHandPosY() + cardLabelStatusLabelShift, colorWinLabel, cardLabelStatusLabelSize);

        game->getHuman()->setBalance(game->getHuman()->getBalance() + bet);
        cash->setText("Cash: " + QString::number(game->getHuman()->getBalance()) + "$");

        setOver = displayLabel("YOU WON: " + QString::number(bet) + "$", humanCardInitialPositionX - shiftSetOverX,
                               humanCardInitialPositionY + shiftSetOverY, colorWinLabel, fontSizeSetOver);
    }
    else {
        cardLabelStatus = displayLabel(QString("BUST"), game->getHuman()->getHandPosX(),
                                game->getHuman()->getHandPosY() + cardLabelStatusLabelShift, colorBustLabel, cardLabelStatusLabelSize);

        game->getHuman()->setBalance(game->getHuman()->getBalance() - bet);
        cash->setText("Cash: " + QString::number(game->getHuman()->getBalance()) + "$");

        setOver = displayLabel("YOU LOST: " + QString::number(bet) + "$", humanCardInitialPositionX - shiftSetOverX,
                               humanCardInitialPositionY + shiftSetOverY, colorBustLabel, fontSizeSetOver);
    }

    ui->hit->setDisabled(true);
    ui->stand->setDisabled(true);
    ui->refreshButton->setEnabled(true);
    if(game->getHuman()->getBalance() <= 0) {
        this->close();
    }

}


void MainWindow::on_refreshButton_clicked()
{
    soundRefreshButton->play();
    game->refreshGame();
    cardLabelStatus.reset();
    setOver.reset();
    for(auto &cardWidget : deck) {
        cardWidget.reset();
    }
    dealerInit();
    humanInit();
    deckInit();
    ui->hit->setEnabled(true);
    ui->stand->setEnabled(true);
    ui->refreshButton->setDisabled(true);
    ui->horizontalSlider->setValue(initialBet);
    bet = initialBet;
    betLabel->setText("Bet: " + QString::number(bet) + "$");
}


void MainWindow::on_deckChangeButton_clicked()
{
    deckChange deckChangeWindow;
    deckChangeWindow.setModal(true);
    deckChangeWindow.exec();
    game->setBasePath(":/" + deckChangeWindow.getCurrentDirectory());
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(value < game->getHuman()->getBalance())
        ui->horizontalSlider->setMaximum(game->getHuman()->getBalance());
    bet = value;
    if(betLabel)
        betLabel.reset();
    betLabel = displayLabel("Bet: " + QString::number(bet) + "$", humanCardInitialPositionX + shiftBetLabelX,
                            humanCardInitialPositionY + shiftBetLabelY, colorBetLabel, fontSizeCashAndBet);
}

