#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(float x, float y, int w, int h, float dx, float dy, int difficulty)
    : MovableElement(x,y,w,h,dx,dy,MOVABLE_ELEMENT_TYPE_OBSTACLE),
      m_difficulty(difficulty),
      m_damage(25*m_difficulty)
{
}
