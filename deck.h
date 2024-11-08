#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include <QString>

class Deck {
public:
    Deck();
    void shuffle();
    Card drawCard();
    QString suitToString(Suit suit) const;
    QString rankToString(Rank rank) const;
    Card getBack();


private:
    std::vector<Card> cards;
    void initializeDeck();
};

#endif // DECK_H
