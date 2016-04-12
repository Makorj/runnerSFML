#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(float x, float y, int w, int h, float dx, float dy, int type)
    : MovableElement(x,(type<2?y:y-h),(type<=2?w:w*2),(type<2?h:h*2),dx,dy,MOVABLE_ELEMENT_TYPE_OBSTACLE),
      m_typeObs(type),
      m_damage((5*m_typeObs)+((5*(m_typeObs*m_typeObs))))
{
}

void Obstacle::apply(Character *player) {
    player->damage(m_damage);
}

int Obstacle::getType() const {
    return (MOVABLE_ELEMENT_TYPE_OBSTACLE*10)+m_typeObs;
}
