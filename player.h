#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "cardwidget.h"
#include "badgelabel.h"

class Player
{
public:
    virtual void calculate();
    virtual void addCardPoint();
    virtual void addCardToHand(Card card) = 0;
    int getPoints() const;
    std::vector<Card> getHand () const;
    void setHand (std::vector<Card> _hand);
    std::vector<std::shared_ptr<CardWidget>> getCardWidgets() const;
    void addCardWidget(std::shared_ptr<CardWidget> cardWidget);
    void setCardWidgets(std::vector<std::shared_ptr<CardWidget>> _cardWidgets);
    int getHandPosX();
    int getHandPosY();
    void setHandPosX(int PosX);
    void setHandPosY(int PosY);
    void setBadge(std::shared_ptr<BadgeLabel<int>> _badge);
    std::shared_ptr<BadgeLabel<int>> getBadge();

protected:
    int points;
    std::vector<Card> hand;
    std::vector<std::shared_ptr<CardWidget>> cardWidgets;
    int handPosX, handPosY;
    std::shared_ptr<BadgeLabel<int>> badge;

};

#endif // PLAYER_H
