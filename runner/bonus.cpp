#include "bonus.h"

<<<<<<< HEAD
Bonus::Bonus(float x, float y, int w, int h, float dx, float dy, int typeBon)
    : MovableElement(x,y,w,h,dx,dy,MOVABLE_ELEMENT_TYPE_BONUS),
      m_typeBon(typeBon)
{
}

int Bonus::getType() const {
    return (MOVABLE_ELEMENT_TYPE_BONUS*10)+m_typeBon;
=======
Bonus::Bonus(float x, float y, int w, int h, float dx, float dy, int type):
    MovableElement(x,y,w,h,dx,dy,type)
{
    
>>>>>>> 6c12cccc539de40edd1d5fea0ba216b51f39701c
}
