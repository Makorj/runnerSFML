#include "moovableelement.h"

MoovableElement::MoovableElement(int x, int y, int w, int h, int dx, int dy):
    m_x(x),
    m_y(y),
    m_w(w),
    m_h(h),
    m_dx(dx),
    m_dy(dy)
{
}

void MoovableElement::moove() {
    m_x+=m_dx;
    m_y+=m_dx;
}

void MoovableElement::setDX(int d) {
    m_dx = d;
}

void MoovableElement::setDY(int d) {
    m_dy = d;
}

int MoovableElement::getX() {
    return m_x;
}

int MoovableElement::getY() {
    return m_y;
}
