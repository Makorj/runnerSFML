#include "balle.h"

#include <math.h>
#include <movableelement.h>


Balle::Balle(float x, float y, int w, int h, float dx, float dy)
    : MovableElement(x,y,w,h,dx,dy),
      jumpTime(),
      m_jumping(false)
{
}

void Balle::jump()
{
    if(m_jumping)
    {
        if(jumpTime.getElapsedTime().asMilliseconds()<=1388)//1388
        {
            int timeas=jumpTime.getElapsedTime().asMilliseconds()*0.1;
            m_dy=-0.9*((float)(((cos(M_PI/3)*0.9*timeas)-((9.81*timeas*timeas)/2000))));
        }
        else
        {
            //m_dy=0.;
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

void Balle::setDX(float d)
{
    if(!m_jumping)
    {
        if(m_dx<5 && m_dx>-5 && d!=0)
            m_dx+=d*0.02;
        else
            m_dx=d;
    }
    else
    {
        m_dx+=d*0.01555;
    }
}

void Balle::move()
{
    if((m_x<=0 && m_dx<0) || (m_x>=750 && m_dx>0))
        m_dx=0;
    m_x+=m_dx;

    if((m_y>=450 && m_dy>0) || (m_y<=0 && m_dy<0))
        m_dy=0;
    m_y+=m_dy;
}
