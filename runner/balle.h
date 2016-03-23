#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>

class Balle
{
private:
    float m_x;
    float m_y;
    int m_h;
    int m_w;
    int m_dx;
    float m_dy;


    sf::Clock jumpTime;
    bool m_jumping;

public:
    Balle(int x, float y, int w, int h, int dx, int dy);
    void move();

    void isJumping();
    void jump();

    float getX() const;
    float getY() const;
    int getH() const;
    int getW() const;
    void setDX(int &b);
    void setDY(float &b);
};

#endif // BALLE_H
