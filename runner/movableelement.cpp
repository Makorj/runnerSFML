#include "movableelement.h"

MovableElement::MovableElement(float x, float y, int w, int h, float dx, float dy):
    m_x(x),
    m_y(y),
    m_w(w),
    m_h(h),
    m_dx(dx),
    m_dy(dy)
{
}

void MovableElement::move() {
    m_x+=m_dx;
    m_y+=m_dx;
}

void MovableElement::setDX(float d) {
    m_dx = d;
}

void MovableElement::setDY(float d) {
    m_dy = d;
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
