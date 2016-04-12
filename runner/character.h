#ifndef CHARACTER_H
#define CHARACTER_H

#include <array>
#include <SFML/Graphics.hpp>
#include "movableelement.h"
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

    int m_score;

    Clock jumpTime;
    bool m_jumping;

    Clock m_InvicibleTimer;

    Clock m_DoubleJumpTimer;

    Clock m_ScoreMultiplierTimer;

public:

    /* CONSTRUCTORS */
    Character(float x, float y, int w, int h, float dx, float dy,int maxLife=100);

    void addLife(int const& x);
    void subLife(int const& x);
    void damage(int const& damage);
    void move(int screen_w);
    void startInvicibility(int const& countdown);
    void startDoubleJump(int const& countdown);

    void isJumping();
    void jump();
    void setDX(float d);
    void addScore(int &x);

    bool isInvicible();
    int getScore() const;
    int getMaxLife() const;
    int getLife() const;

};

#endif // CHARACTER_H
