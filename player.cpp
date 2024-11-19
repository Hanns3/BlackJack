#include "player.h"

int Player::getPoints() const { return points; }

void Player::calculate() {
    for(auto &card : hand) {
        this->points += card.getValue();
    }
}

void Player::addCardWidget(std::shared_ptr<CardWidget> cardWidget) {
    this->cardWidgets.push_back(cardWidget);
}


void Player::addCardPoint() {
    if(hand[hand.size() - 1].getRank() == Ace && this->points + hand[hand.size() - 1].getValue() > 21)
        this->points += 1;
    else this->points += hand[hand.size() - 1].getValue();
}

std::vector<Card> Player::getHand() const { return hand; }
void Player::setHand(std::vector<Card> _hand) { hand = _hand; }
std::vector<std::shared_ptr<CardWidget>> Player::getCardWidgets() const { return cardWidgets; }
void Player::setCardWidgets(std::vector<std::shared_ptr<CardWidget>> _cardWidgets) { cardWidgets = _cardWidgets; }
int Player::getHandPosX() { return handPosX; }
int Player::getHandPosY() { return handPosY; }
void Player::setHandPosX(int PosX) { handPosX = PosX; }
void Player::setHandPosY(int PosY) { handPosY = PosY; }
void Player::setBadge(std::shared_ptr<BadgeLabel<int>> _badge) { badge = _badge; }
std::shared_ptr<BadgeLabel<int>> Player::getBadge() { return badge; }
