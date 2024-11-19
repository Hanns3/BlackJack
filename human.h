#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player
{
public:
    Human(const std::vector<Card>& initialHand, int _handPosX, int _handPosY);
    virtual void addCardToHand(Card card) override;
    void clearCards();
    void initHand(std::vector<Card> init);
    int getBalance() const;
    void setBalance(int _balance);
    ~Human() = default;

private:
    int balance;
};

#endif // HUMAN_H
