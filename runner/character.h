#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include <SFML/Graphics.hpp>
#include <movableelement.h>


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
