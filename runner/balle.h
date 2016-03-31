#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>
#include <movableelement.h>

class Balle : public MovableElement
{
private:

    sf::Clock jumpTime;
    bool m_jumping;

public:
    Balle(float x, float y, int w, int h, float dx, float dy);

    void move(int screen_w);

    void isJumping();
    void jump();
    void setDX(float d);
};

#endif // BALLE_H
