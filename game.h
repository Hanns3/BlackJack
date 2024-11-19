#ifndef GAME_H
#define GAME_H

#include "dealer.h"
#include "human.h"
#include "deck.h"
#include <memory>

class Game
{
public:
    Game();
    Dealer * getDealer() const;
    Human * getHuman() const;
    Deck * getDeck() const;
    void InitializeDealer();
    void InitializeDeck();
    void InitializeHuman();
    void refreshGame();
    void setBasePath(QString _basePath);

private:
    std::unique_ptr<Dealer> dealer;
    std::unique_ptr<Human> human;
    std::unique_ptr<Deck> deck;
    QString basePath;
};

#endif // GAME_H
