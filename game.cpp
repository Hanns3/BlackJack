#include "game.h"
#include "constants.h"

Game::Game() {
    basePath = initialCardPath;
    InitializeDeck();
    InitializeDealer();
    InitializeHuman();
}

void Game::InitializeDealer() {
    dealer = std::make_unique<Dealer>(
        std::initializer_list<Card>{deck->drawCard(), deck->drawCard()},
        dealerCardInitialPositionX,
        dealerCardInitialPositionY
        );
    while (dealer->getPoints() <= 12) {
        dealer->addCardToHand(deck->drawCard());
    }
}

void Game::InitializeDeck() {
    deck = std::make_unique<Deck>(basePath);
}

void Game::InitializeHuman() {
    human = std::make_unique<Human>(
        std::initializer_list<Card>{deck->drawCard(), deck->drawCard()},
        humanCardInitialPositionX,
        humanCardInitialPositionY
        );
}

void Game::refreshGame() {
    deck = std::make_unique<Deck>(basePath);
    InitializeDealer();

    human->clearCards();
    human->initHand(std::initializer_list<Card>{deck->drawCard(), deck->drawCard()});
}

void Game::setBasePath(QString _basePath) {
    basePath = _basePath;
}

Dealer* Game::getDealer() const { return dealer.get(); }
Human* Game::getHuman() const { return human.get(); }
Deck* Game::getDeck() const { return deck.get(); }
