#include "character.h"
#include <SFML/Graphics.hpp>

/**** DEFINES ****/

#define TORSO_XPOS 100
#define TORSO_YPOS 100
#define TORSO_H 10
#define TORSO_W 50
#define TORSO_ORIGIN_X (10/2)
#define TORSO_ORIGIN_Y (50/2)

#define ARM_LEFT_XPOS 0
#define ARM_LEFT_YPOS 0
#define ARM_LEFT_H 10
#define ARM_LEFT_W 25
#define ARM_LEFT_ORIGIN_X 0
#define ARM_LEFT_ORIGIN_Y 0

#define FOREARM_LEFT_XPOS 0
#define FOREARM_LEFT_YPOS 0
#define FOREARM_LEFT_H 10
#define FOREARM_LEFT_W 25
#define FOREARM_LEFT_ORIGIN_X 0
#define FOREARM_LEFT_ORIGIN_Y 0

#define ARM_RIGHT_XPOS 0
#define ARM_RIGHT_YPOS 0
#define ARM_RIGHT_H 10
#define ARM_RIGHT_W 25
#define ARM_RIGHT_ORIGIN_X 0
#define ARM_RIGHT_ORIGIN_Y 0

#define FOREARM_RIGHT_XPOS 0
#define FOREARM_RIGHT_YPOS 0
#define FOREARM_RIGHT_H 0
#define FOREARM_RIGHT_W 0
#define FOREARM_RIGHT_ORIGIN_X 0
#define FOREARM_RIGHT_ORIGIN_Y 0

#define LEG_LEFT_XPOS 0
#define LEG_LEFT_YPOS 0
#define LEG_LEFT_H 0
#define LEG_LEFT_W 0
#define LEG_LEFT_ORIGIN_X 0
#define LEG_LEFT_ORIGIN_Y 0

#define CALF_LEFT_XPOS 0
#define CALF_LEFT_YPOS 0
#define CALF_LEFT_H 0
#define CALF_LEFT_W 0
#define CALF_LEFT_ORIGIN_X 0
#define CALF_LEFT_ORIGIN_Y 0

#define LEG_RIGHT_XPOS 0
#define LEG_RIGHT_YPOS 0
#define LEG_RIGHT_H 0
#define LEG_RIGHT_W 0
#define LEG_RIGHT_ORIGIN_X 0
#define LEG_RIGHT_ORIGIN_Y 0

#define CALF_RIGHT_XPOS 0
#define CALF_RIGHT_YPOS 0
#define CALF_RIGHT_H 0
#define CALF_RIGHT_W 0
#define CALF_RIGHT_ORIGIN_X 0
#define CALF_RIGHT_ORIGIN_Y 0

/*****************/

//struct Limb {
// int x, y, originx, originy;
// string name;
//};

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
    /*
    for(int i=0;i<LIMBS_NUMBER;i++)
        m_members[i]=new MovableElement;
    */
//    std::List<Limb> _limbs;
    
//    for (var it = std::List<Limb>.BeginIterator(); it != endIterator; ++it) {
//        members[*it->name] = new sf::RectangleShape;
//        members[*it->name]->setPosition(*it->)
        
//    }
    
//    for(int i=0;i<LIMBS_NUMBER;i++) {
//          m_members[i]
//    }

    m_members[MEMBER_TORSO]->setOrigin((float)TORSO_ORIGIN_X,(float)TORSO_ORIGIN_Y);
    m_members[MEMBER_TORSO]->setPosition((float)TORSO_XPOS,(float)TORSO_YPOS);
    m_members[MEMBER_TORSO]->setSize(sf::Vector2f(TORSO_W,TORSO_H));
    m_members[MEMBER_TORSO]->setFillColor(sf::Color::Black);

    m_members[MEMBER_ARM_LEFT]->setOrigin((float)ARM_LEFT_ORIGIN_X,(float)ARM_LEFT_ORIGIN_Y);
    m_members[MEMBER_ARM_LEFT]->setPosition((float)ARM_LEFT_XPOS,(float)ARM_LEFT_YPOS);
    m_members[MEMBER_ARM_LEFT]->setSize(sf::Vector2f(ARM_LEFT_W,ARM_LEFT_H));

    m_members[MEMBER_FOREARM_LEFT]->setOrigin((float)FOREARM_LEFT_ORIGIN_X,(float)FOREARM_LEFT_ORIGIN_Y);
    m_members[MEMBER_FOREARM_LEFT]->setPosition((float)FOREARM_LEFT_XPOS,(float)FOREARM_LEFT_YPOS);
    m_members[MEMBER_FOREARM_LEFT]->setSize(sf::Vector2f(FOREARM_LEFT_W,FOREARM_LEFT_H));

    m_members[MEMBER_ARM_RIGHT]->setOrigin((float)ARM_RIGHT_ORIGIN_X,(float)ARM_RIGHT_ORIGIN_Y);
    m_members[MEMBER_ARM_RIGHT]->setPosition((float)ARM_RIGHT_XPOS,(float)ARM_RIGHT_YPOS);
    m_members[MEMBER_ARM_RIGHT]->setSize(sf::Vector2f(ARM_RIGHT_W,ARM_RIGHT_H));

    m_members[MEMBER_FOREARM_RIGHT]->setOrigin((float)FOREARM_RIGHT_ORIGIN_X,(float)FOREARM_RIGHT_ORIGIN_Y);
    m_members[MEMBER_FOREARM_RIGHT]->setPosition((float)FOREARM_RIGHT_XPOS,(float)FOREARM_RIGHT_YPOS);
    m_members[MEMBER_FOREARM_RIGHT]->setSize(sf::Vector2f(FOREARM_RIGHT_W,FOREARM_RIGHT_H));

    m_members[MEMBER_LEG_LEFT]->setOrigin((float)LEG_LEFT_ORIGIN_X,(float)LEG_LEFT_ORIGIN_Y);
    m_members[MEMBER_LEG_LEFT]->setPosition((float)LEG_LEFT_XPOS,(float)LEG_LEFT_YPOS);
    m_members[MEMBER_LEG_LEFT]->setSize(sf::Vector2f(LEG_LEFT_W,LEG_LEFT_H));

    m_members[MEMBER_CALF_LEFT]->setOrigin((float)CALF_LEFT_ORIGIN_X,(float)CALF_LEFT_ORIGIN_Y);
    m_members[MEMBER_CALF_LEFT]->setPosition((float)CALF_LEFT_XPOS,(float)CALF_LEFT_YPOS);
    m_members[MEMBER_CALF_LEFT]->setSize(sf::Vector2f(CALF_LEFT_W,CALF_LEFT_H));

    m_members[MEMBER_LEG_RIGHT]->setOrigin((float)LEG_RIGHT_ORIGIN_X,(float)LEG_RIGHT_ORIGIN_Y);
    m_members[MEMBER_LEG_RIGHT]->setPosition((float)LEG_RIGHT_XPOS,(float)LEG_RIGHT_YPOS);
    m_members[MEMBER_LEG_RIGHT]->setSize(sf::Vector2f(LEG_RIGHT_W,LEG_RIGHT_H));

    m_members[MEMBER_CALF_RIGHT]->setOrigin((float)CALF_RIGHT_ORIGIN_X,(float)CALF_RIGHT_ORIGIN_Y);
    m_members[MEMBER_CALF_RIGHT]->setPosition((float)CALF_RIGHT_XPOS,(float)CALF_RIGHT_YPOS);
    m_members[MEMBER_CALF_RIGHT]->setSize(sf::Vector2f(CALF_RIGHT_W,CALF_RIGHT_H));


}

Character::~Character()
{
    for(int i=0;i<LIMBS_NUMBER;i++)
        delete m_members[i];
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
