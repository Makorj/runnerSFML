#include "invicibility.h"
#include "character.h"

Invicibility::Invicibility(float x, float y, int w, int h, float dx, float dy, int duration)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_INVICIBILITY),
      m_duration(duration)
{
}

void Invicibility::apply(Character* player)
{
    player->startInvicibility(m_duration);
}
