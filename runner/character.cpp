#include "character.h"
#include <SFML/Graphics.hpp>

#include <math.h>
#include <movableelement.h>

#define GRAVITATIONAL_CONST 9.81
#define JUMP_TIME_CONST_MILLISECONDS 485
#define JUMP_TIME_MULTIPLIER 0.5
#define JUMP_FIRST_MULTIPLIER 1.5
#define JUMP_FINAL_MULTIPLIER 0.9

#define HORIZONTAL_JUMPING_SPEED_MULTIPLIER 0.09
#define HORIZONTAL_SPEED_MULTIPLIER 0.05

void Character::jump()
{
    if(m_jumping)
    {
        if(jumpTime.asMilliseconds()<=JUMP_TIME_CONST_MILLISECONDS)//1388
        {

            int timeas=jumpTime.asMilliseconds()*JUMP_TIME_MULTIPLIER;
            m_dy=-(JUMP_FINAL_MULTIPLIER*((float)(((cos(M_PI/3)*JUMP_FIRST_MULTIPLIER*timeas)-((GRAVITATIONAL_CONST*timeas*timeas)/2000)))));
        }
        else
        {
            //m_dy=0.;
            m_jumping=false;
            m_y=450;
        }
    }
}

void Character::isJumping()
{
    if(!m_jumping)
    {
        jumpTime.restart();
        m_jumping=true;
    }
}

void Character::setDX(float d)
{
    if(!m_jumping)
    {
        if(m_dx<5 && m_dx>-3 && d!=0)
            m_dx+=d*HORIZONTAL_JUMPING_SPEED_MULTIPLIER;
        else
            m_dx=d;
    }
    else
    {
        m_dx+=d*HORIZONTAL_SPEED_MULTIPLIER;
    }
}

void Character::move(int screen_w)
{
    if((m_x<=0 && m_dx<0) || (m_x>=screen_w-m_w && m_dx>0))
        m_dx=0;
    m_x+=m_dx;

    if((m_y>=450 && m_dy>0) || (m_y<=0 && m_dy<0))
        m_dy=0;
    m_y+=m_dy;
}


Character::Character(float x, float y, int w, int h, float dx, float dy)
    : MovableElement(x,y,w,h,dx,dy,MOVABLE_ELEMENT_TYPE_CHAR),
      jumpTime(),
      m_jumping(false),
      m_speed(1),
      m_dir(1),
      m_maxLife(100),
      m_actualLife(m_maxLife),
      m_actualBonusId(-1),
      m_actualSkinId(-1),
      m_actualHatId(-1)
{

}

void Character::addLife(const int &x)
{
    if(m_actualLife+x>m_maxLife)
        m_actualLife=m_maxLife;
    else
        m_actualLife+=x;
}

void Character::subLife(const int &x)
{
    m_actualLife-=x;
}

void Character::setActualBonusId(int& bonusId)
{
    m_actualBonusId=bonusId;
}

int Character::getLife() const
{
    return m_actualLife;
}

void Character::damage(const int &damage){
    m_actualLife-=damage;
}
