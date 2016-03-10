#include "character.h"

Character::Character()
    : m_x(10),
      m_y(400),
      m_speed(1),
      m_dir(1),
      m_maxLife(100),
      m_actualLife(m_maxLife),
      m_actualBonusId(-1),
      m_actualSkinId(-1),
      m_actualHatId(-1)
{
    /*
    for(int i=0;i<LIMBS_NUMBER;i++)
        m_members[i]=new MovableElement;
    */
}

Character::~Character()
{
    /*
    for(int i=0;i<LIMBS_NUMBER;i++)
        delete m_members[i];
    */
}

void Character::move()
{
    m_x+=m_speed*m_dir;
}

void Character::addLife(int& x)
{
    if(m_actualLife+x>m_maxLife)
        m_actualLife=m_maxLife;
    else
        m_actualLife+=x;
}

void Character::setActualBonusId(int& bonusId)
{
}

int Character::getLife() const
{
    return m_actualLife;
}
