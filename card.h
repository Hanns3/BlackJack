#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QPixmap>
#include "back.h"
#include "front.h"

enum Suit { hearts, diamonds, clubs, spades };
enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:
    Card(Rank rank, Suit suit, const QString& imagePath);
    Rank getRank() const;
    Suit getSuit() const;
    QPixmap getFront() const;
    QPixmap getBack() const;
    int getValue() const;
    QString rankToString(Rank rank) const;
    QString suitToString(Suit suit) const;

private:
    Rank rank;
    Suit suit;
    Back back;
    Front front;
};

#endif // CARD_H
