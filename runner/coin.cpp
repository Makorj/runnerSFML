#include "coin.h"

Coin::Coin(float x, float y, int w, int h, float dx, float dy, int scoreValue)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_COIN),
      m_scoreValue(scoreValue)
{
}

void Coin::apply(Character* charact) {
    charact->addScore(m_scoreValue);
}
