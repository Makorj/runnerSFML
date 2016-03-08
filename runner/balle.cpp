#include "balle.h"

Balle::Balle(int x, int y, int w, int h, int dx, int dy)
{
    m_x=x;
    m_y=y;
    m_h=h;
    m_w=w;
    m_dx=dx;
    m_dy=dy;
}

void Balle::move()
{
    m_x+=m_dx;
    m_y+=m_dy;
}

int Balle::getX() const
{
 return m_x;
}

int Balle::getY() const
{
    return m_y;
}

int Balle::getH() const
{
 return m_h;
}

int Balle::getW() const
{
    return m_w;
}

void Balle::setDX(int &b)
{
    m_dx=b;
}

void Balle::setDY(int &b)
{
    m_dy=b;
}
