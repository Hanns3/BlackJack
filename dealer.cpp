#include "dealer.h"
#include "cardwidget.h"
#include "constants.h"

Dealer::Dealer(const std::vector<Card>& initialHand, int _handPosX, int _handPosY) {
    hand = initialHand;
    points = 0;
    handPosX = _handPosX; handPosY = _handPosY;
    calculate();
}

std::shared_ptr<CardWidget> Dealer::getLast() { return cardWidgets.back(); }

void Dealer::addCardToHand(Card card) {
    hand.push_back(card);
    addCardPoint();
}

void Dealer::revealHand() {
    auto cardWidget = cardWidgets.back();
    cardWidget->setPixmap(hand[hand.size() - 1].getFront());
    handPosX -= shiftCardX;
}
