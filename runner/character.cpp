/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "character.h"
#include <SFML/Graphics.hpp>

#include <math.h>
#include <movableelement.h>

const float GRAVITATIONAL_CONST = 9.81;
const int JUMP_TIME_CONST_MILLISECONDS = 485;
const float JUMP_TIME_MULTIPLIER = 0.5;
const float JUMP_FIRST_MULTIPLIER = 1.5;
const float JUMP_FINAL_MULTIPLIER = 0.9;

const float HORIZONTAL_JUMPING_SPEED_MULTIPLIER = 0.09;
const float HORIZONTAL_SPEED_MULTIPLIER = 0.05;

void Character::jump()
{
    if(m_jumping)
    {
        if(jumpTime.asMilliseconds()<=JUMP_TIME_CONST_MILLISECONDS && m_y-1<450)//1388
        {

            int timeas=jumpTime.asMilliseconds()*JUMP_TIME_MULTIPLIER;
            m_dy=-(JUMP_FINAL_MULTIPLIER*((float)(((cos(M_PI/3)*JUMP_FIRST_MULTIPLIER*timeas)-((GRAVITATIONAL_CONST*timeas*timeas)/2000)))));
        }
        else
        {
            m_jumping=false;
            m_y=450;
        }
    }
}

void Character::isJumping()
{
    if(!m_jumping || !m_DoubleJumpTimer.hasEnded())
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


Character::Character(float x, float y, int w, int h, float dx, float dy, int maxLife)
    : MovableElement(x,y,w,h,dx,dy,MOVABLE_ELEMENT_TYPE_CHAR),
      jumpTime(),
      m_jumping(false),
      m_speed(1),
      m_dir(1),
      m_maxLife(maxLife),
      m_actualLife(m_maxLife),
      m_score(0),
      m_InvicibleTimer(),
      m_DoubleJumpTimer(),
      m_ScoreMultiplierTimer()
{

}

void Character::addLife(const int &x)
{
    if(m_actualLife+x>m_maxLife)
        m_actualLife=m_maxLife;
    else
        m_actualLife+=x;
}

void Character::addScore(int& x)
{
    m_score+=x;
}

void Character::addCoin(int &x)
{
    m_coin+=x;
}

void Character::subLife(const int &x)
{
    m_actualLife-=x;
}

void Character::startInvicibility(const int &countdown) {
    m_InvicibleTimer.startCounter(countdown);
}

void Character::startDoubleJump(const int &countdown) {
    m_DoubleJumpTimer.startCounter(countdown);
}

void Character::startScoreMultiplier(const int &countdown) {
    m_ScoreMultiplierTimer.startCounter(countdown);
}

int Character::getGold() const
{
    return m_coin;
}
int Character::getLife() const
{
    return m_actualLife;
}

int Character::getScore() const
{
    return m_score;
}

void Character::damage(const int &damage){
    if(m_InvicibleTimer.hasEnded())
        m_actualLife-=damage;
}

bool Character::isInvicible() {
    return m_InvicibleTimer.hasEnded();
}
