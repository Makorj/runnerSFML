#include "bonus.h"

Bonus::Bonus(float x, float y, int w, int h, float dx, float dy, int typeBon)
    : MovableElement(x,y,w,h,dx,dy,MOVABLE_ELEMENT_TYPE_BONUS),
      m_typeBon(typeBon)
{
}

int Bonus::getType() const {
    return (MOVABLE_ELEMENT_TYPE_BONUS*10)+m_typeBon;
}

