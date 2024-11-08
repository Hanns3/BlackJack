#include "Card.h"

Card::Card(Rank rank, Suit suit, const QString& imagePath)
    : rank(rank), suit(suit), image(imagePath)
{
}

Card::Card(const QString& imagePath)
    : image(imagePath)
{
}

Rank Card::getRank() const { return rank; }
Suit Card::getSuit() const { return suit; }

QPixmap Card::getImage() const { return image; }

// Метод для отримання значення карти для гри в блекджек
int Card::getValue() const {
    if (rank >= Two && rank <= Ten) {
        return rank;
    } else if (rank >= Jack && rank <= King) {
        return 10;
    } else if (rank == Ace) {
        return 11; // Для туза використовується спеціальна логіка
    }
    return 0;
}
