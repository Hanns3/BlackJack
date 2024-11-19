#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include <QString>

class Deck {
public:
    Deck(QString basePath);
    void shuffle();
    Card drawCard();
    QPixmap getBack() const;
    void setBasePath(QString _basePath);

private:
    std::vector<Card> cards;
    Back back;
    QString path;
    void initializeDeck(const QString& basePath);
};

#endif // DECK_H
