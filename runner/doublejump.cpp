#include "doublejump.h"

DoubleJump::DoubleJump(float x, float y, int w, int h, float dx, float dy, int duration)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_DOUBLE_JUMP),
      m_duration(duration)
{
}

void DoubleJump::apply(Character *player)
{
    player->startDoubleJump(m_duration);
}
