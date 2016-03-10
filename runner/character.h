#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>

/*** DEFINE ***/

#define LIMBS_NUMBER 5
#define MEMBER_TORSO 0
#define MEMBER_ARM_LEFT 1
#define MEMBER_ARM_RIGHT 2
#define MEMBER_LEG_LEFT 3
#define MEMBER_LEG_RIGHT 4

/**************/


class Character
{
private:

    ///Character's horizontal position
    int m_x;
    ///Character's vertical position
    int m_y;

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

public:

    /* CONSTRUCTORS */
    Character();

    /* DESTRUCTOR */
    ~Character();

    void addLife(int &x);
    void setActualBonusId(int& bonusId);
    void move();

    int getMaxLife() const;
    int getActualSkinId() const;
    int getActualHatId() const;
    int getLife() const;
};

#endif // CHARACTER_H
