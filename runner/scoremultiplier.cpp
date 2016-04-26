#include "scoremultiplier.h"

ScoreMultiplier::ScoreMultiplier(float x, float y, int w, int h, float dx, float dy, int duration)
    : Bonus(x,y,h,dx,dy,BONUS_TYPE_SCORE),
      m_duration(duration)
{
}
void ScoreMultiplier::apply(Character *player) {
    player->startScoreMultiplier(m_duration);
}
