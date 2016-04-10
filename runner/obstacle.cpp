#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(float x, float y, int w, int h, float dx, float dy, int type)
    : MovableElement(x,y,w,h,dx,dy,MOVABLE_ELEMENT_TYPE_OBSTACLE),
      m_type(type),
      m_damage(20+(5*m_type)+((5*(m_type*m_type))))
{
}

void Obstacle::damageChar(Character &player){
    player.damage(m_damage);
}
