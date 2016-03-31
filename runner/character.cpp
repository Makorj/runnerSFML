#include "character.h"
#include <SFML/Graphics.hpp>

Character::Character()
    : m_speed(1),
      m_dir(1),
      m_maxLife(100),
      m_actualLife(m_maxLife),
      m_actualBonusId(-1),
      m_actualSkinId(-1),
      m_actualHatId(-1),
      MovableElement(10,450,100,100,5,0)
{

}

Character::~Character()
{

}

void Character::move()
{
    m_x+=m_speed*m_dir;
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
