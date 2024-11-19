#include "human.h"
#include "constants.h"

Human::Human(const std::vector<Card>& initialHand, int _handPosX, int _handPosY) {
    hand = initialHand;
    points = 0;
    balance = startingBalance;
    handPosX = _handPosX; handPosY = _handPosY;
    calculate();
}

void Human::clearCards() {
    cardWidgets.clear();
    badge.reset();
    handPosX -= hand.size() * shiftCardX;
    hand.clear();
    points = 0;
}

void Human::initHand(std::vector<Card> init) {
    hand = init;
    calculate();
}

int Human::getBalance() const{ return balance; }

void Human::setBalance(int _balance) { balance = _balance; }

void Human::addCardToHand(Card card)  {
    hand.push_back(card);
    addCardPoint();
    badge->setText(QString::number(points));
}
