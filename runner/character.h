#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include "movableelement.h"
#include <SFML/Graphics.hpp>
#include "clock.h"


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

    Clock jumpTime;
    bool m_jumping;

public:

    /* CONSTRUCTORS */
    Character(float x, float y, int w, int h, float dx, float dy);

    void addLife(int const& x);
    void subLife(int const& x);
    void setActualBonusId(int& bonusId);
    void damage(int const& damage);
    void move(int screen_w);

    void isJumping();
    void jump();
    void setDX(float d);

    int getMaxLife() const;
    int getActualSkinId() const;
    int getActualHatId() const;
    int getLife() const;

};

#endif // CHARACTER_H
