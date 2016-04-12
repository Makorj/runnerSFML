#include "heal.h"
#include "character.h"

Heal::Heal(float x, float y, int w, int h, float dx, float dy, int healingPower)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_HEALTH),
      m_healingPower(healingPower)
{
}

void Heal::apply(Character *player) {
    player->addLife(m_healingPower);
}
