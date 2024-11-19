#include "deck.h"
#include <algorithm> // для std::shuffle
#include <random>
#include <chrono>

Deck::Deck(QString basePath)
    : back(basePath), path(basePath)
{
    initializeDeck(basePath);
    shuffle();
}

void Deck::initializeDeck(const QString& basePath) {
    for (int suit = hearts; suit <= spades; ++suit) {
        for (int rank = Two; rank <= Ace; ++rank) {
            cards.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit), basePath);
        }
    }
}

void Deck::shuffle() {
    auto rng = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::drawCard() {
    if (!cards.empty()) {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }
    return Card(Two, hearts, "");
}

QPixmap Deck::getBack() const {
    return back.getBack();
}

void Deck::setBasePath(QString _basePath){ path = _basePath; }

