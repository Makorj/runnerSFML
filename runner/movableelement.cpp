#include "movableelement.h"

MovableElement::MovableElement(float x, float y, int w, int h, float dx, float dy, int type)
    : m_type(type),
      m_x(x),
      m_y(y),
      m_w(w),
      m_h(h),
      m_dx(dx),
      m_dy(dy)
{
}

void MovableElement::move(int timeElapsed) {
    m_x+=m_dx;
}

void MovableElement::setDX(float d) {
    m_dx = d;
}

void MovableElement::setDY(float d) {
    m_dy = d;
}

int MovableElement::getType() const {
    return m_type;
}

float MovableElement::getX() const {
    return m_x;
}

float MovableElement::getY() const {
    return m_y;
}

int MovableElement::getH() const {
    return m_h;
}

int MovableElement::getW() const {
    return m_w;
}

bool MovableElement::outOfScreen(){
    if(m_x+m_w<-100)
        return true;
    return false;
}

void MovableElement::apply(Character &charact)
{

}


bool collide (MovableElement elem1,MovableElement elem2) {
    if (elem1.getX() < elem2.getX() + elem2.getW() &&
            elem1.getX() + elem1.getW() > elem2.getX() &&
            elem1.getY() < elem2.getY() + elem2.getH() &&
            elem1.getY() + elem1.getH() > elem2.getY())
        return true;
    else
        return false;
}
