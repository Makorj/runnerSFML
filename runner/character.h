#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>

/*** DEFINE ***/
#define LIMBS_NUMBER 5
/**************/

enum limbs {leftarm=0, rightarm=1, leftleg=2, rightleg=3, torso=4};

class character
{
private:

    ///Character's horizontal position
    int m_x;
    ///Character's vertical position
    int m_y;

    ///Character's speed
    int m_speed;

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

    //std::array<MovableElement*> m_members[LIMBS_NUMBER];

public:
    character();

    int getLife();
};

#endif // CHARACTER_H
