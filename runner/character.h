#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include <SFML/Graphics.hpp>
#include <movableelement.h>

/*** DEFINES ***/

#define LIMBS_NUMBER 9
#define MEMBER_TORSO 0
#define MEMBER_ARM_LEFT 1
#define MEMBER_FOREARM_LEFT 2
#define MEMBER_ARM_RIGHT 3
#define MEMBER_FOREARM_RIGHT 4
#define MEMBER_LEG_LEFT 5
#define MEMBER_CALF_LEFT 6
#define MEMBER_LEG_RIGHT 7
#define MEMBER_CALF_RIGHT 8

/**************/


class Character : public MovableElement
{
private:

    ///Character's speed
    int m_speed;
    ///Character's direction
    int m_dir;

    ///Character's maximum life rate
    int m_maxLife;
    ///Character's actual life rate
    int m_actualLife;

    ///Id of the active bonus on the character, -1 if none
    int m_actualBonusId;

    ///Id of the active skin on the character, -1 if default
    int m_actualSkinId;
    ///Id of the active hat on the character, -1 if default
    int m_actualHatId;

    //std::array<MovableElement*, LIMBS_NUMBER> m_members;
    std::array<sf::RectangleShape*, LIMBS_NUMBER> m_members;

public:

    /* CONSTRUCTORS */
    Character();

    /* DESTRUCTOR */
    ~Character();

    void addLife(int const& x);
    void subLife(int const& x);
    void setActualBonusId(int& bonusId);
    void move();

    int getMaxLife() const;
    int getActualSkinId() const;
    int getActualHatId() const;
    int getLife() const;
};

#endif // CHARACTER_H
