#include "balle.h"

#include <math.h>

Balle::Balle(int x, float y, int w, int h, int dx, int dy)
    :m_x(x),
      m_y(y),
      m_h(h),
      m_w(w),
      m_dx(dx),
      m_dy(dy),
      jumpTime(),
      m_jumping(false)
{
}

void Balle::jump()
{
    if(m_jumping)
    {
        if(jumpTime.getElapsedTime().asMilliseconds()<=1388)
        {
            int timeas=jumpTime.getElapsedTime().asMilliseconds()*0.1;
            m_dy=-0.9*((float)(((cos(M_PI/3)*0.9*timeas)-((9.81*timeas*timeas)/2000))));
        }
        else
        {
            m_dy=0.;
            m_jumping=false;
            m_y=450;
        }
    }
}

void Balle::isJumping()
{
    if(!m_jumping)
    {
        jumpTime.restart();
        m_jumping=true;
    }
}

void Balle::move()
{
    m_x+=m_dx;
    m_y+=m_dy;
}

float Balle::getX() const
{
    return m_x;
}

float Balle::getY() const
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

void Balle::setDY(float &b)
{
    m_dy=b;
}
