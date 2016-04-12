#ifndef SLIDINGBACKGROUND_H
#define SLIDINGBACKGROUND_H

#include <SFML/Graphics.hpp>
#include "graphicelement.h"

class SlidingBackground
{
private :
    GraphicElement m_left;
    GraphicElement m_right;
    int m_w;
    int m_h;
    float m_speed;
public :
    SlidingBackground() = default;
    SlidingBackground(sf::Texture &image, int w, int h, float speed);
    SlidingBackground(const SlidingBackground& copy);
    void draw(sf::RenderWindow *window);
    void setSpeed(float s);
};

#endif // SLIDINGBACKGROUND_H
