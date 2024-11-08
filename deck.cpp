#include "Deck.h"
#include <algorithm> // для std::shuffle
#include <random>
#include <chrono>

Deck::Deck() {
    initializeDeck();
    shuffle();
}

void Deck::initializeDeck() {
    const QString basePath = ":/cards/images/cards/"; // Базовий шлях до зображень карт

    // Ініціалізуємо кожну карту для всіх мастей і значень
    for (int suit = hearts; suit <= spades; ++suit) {
        for (int rank = Two; rank <= Ace; ++rank) {
            QString imagePath = basePath + rankToString(static_cast<Rank>(rank))
            + "_of_" + suitToString(static_cast<Suit>(suit)) + ".png";
            cards.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit), imagePath);
        }
    }
}

void Deck::shuffle() {
    // Використовуємо випадковий генератор для перемішування колоди
    auto rng = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(cards.begin(), cards.end(), rng);
}

Card Deck::drawCard() {
    if (!cards.empty()) {
        Card drawnCard = cards.back();
        cards.pop_back();
        return drawnCard;
    }
    // Додайте обробку випадку, коли колода порожня, за потреби
    return Card(Two, hearts, ""); // Повертаємо заглушку
}

Card Deck::getBack() {
    QString path = ":/cards/images/cards/back.png";
    Card card(path);
    return card;
}

// Допоміжна функція для перетворення масті на рядок
QString Deck::suitToString(Suit suit) const {
    switch (suit) {
    case hearts: return "hearts";
    case diamonds: return "diamonds";
    case clubs: return "clubs";
    case spades: return "spades";
    default: return "unknown";
    }
}

// Допоміжна функція для перетворення рангу на рядок
QString Deck::rankToString(Rank rank) const {
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
