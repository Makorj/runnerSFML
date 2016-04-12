#ifndef COIN_H
#define COIN_H

#include "bonus.h"
#include "character.h"

class Coin : public Bonus
{
private:
    int m_scoreValue;
    static const int COIN_MONEY_VALUE=1;
public:
    Coin(float x, float y, int w, int h, float dx, float dy, int scoreValue=5);
    void apply(Character* charact) override;
};

#endif // COIN_H
