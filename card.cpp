#include "card.h"

Card::Card(Rank rank, Suit suit, const QString& imagePath)
    : rank(rank), suit(suit), back(imagePath),
    front(rankToString(rank), suitToString(suit) ,imagePath)
{
}


Rank Card::getRank() const { return rank; }
Suit Card::getSuit() const { return suit; }

QPixmap Card::getFront() const { return front.getFront(); }
QPixmap Card::getBack() const { return back.getBack(); }

int Card::getValue() const {
    if (rank >= Two && rank <= Ten) {
        return rank;
    } else if (rank >= Jack && rank <= King) {
        return 10;
    } else if (rank == Ace) {
        return 11;
    }
    return 0;
}

QString Card::suitToString(Suit suit) const {
    switch (suit) {
    case hearts: return "hearts";
    case diamonds: return "diamonds";
    case clubs: return "clubs";
    case spades: return "spades";
    default: return "unknown";
    }
}

QString Card::rankToString(Rank rank) const {
    switch (rank) {
    case Two: return "2";
    case Three: return "3";
    case Four: return "4";
    case Five: return "5";
    case Six: return "6";
    case Seven: return "7";
    case Eight: return "8";
    case Nine: return "9";
    case Ten: return "10";
    case Jack: return "jack";
    case Queen: return "queen";
    case King: return "king";
    case Ace: return "ace";
    default: return "unknown";
    }
}
