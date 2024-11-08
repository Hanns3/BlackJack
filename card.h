#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QPixmap>

enum Suit { hearts, diamonds, clubs, spades };
enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:
    Card(Rank rank, Suit suit, const QString& imagePath);
    Card(const QString& imagePath);
    Rank getRank() const;
    Suit getSuit() const;
    QPixmap getImage() const;
    int getValue() const;

private:
    Rank rank;
    Suit suit;
    QPixmap image;
};

#endif // CARD_H
