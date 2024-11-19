#ifndef DEALER_H
#define DEALER_H
#include "card.h"
#include "player.h"

class Dealer : public Player
{
public:
    Dealer(const std::vector<Card>& initialHand, int _handPosX, int _handPosY);
    virtual void addCardToHand(Card card) override;
    void revealHand();
    std::shared_ptr<CardWidget> getLast();
    ~Dealer() = default;

};
#endif // DEALER_H
