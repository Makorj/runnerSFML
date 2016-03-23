#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H
#include <vector>
#include "SFML/Graphics.hpp"

const int SIZE_BALL = 50;
const sf::IntRect ball_rect1{0,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect2{0,50,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect3{0,100,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect4{0,150,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect5{0,200,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect6{0,250,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect7{0,300,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect7{0,350,SIZE_BALL,SIZE_BALL};

class AnimatedGraphicElement
{
    std::vector<sf::IntRect>m_clipRects;
    int m_currentClipRect;
public:
    AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h);
    void draw(sf::RenderWindow *window);
};

#endif // ANIMATEDGRAPHICELEMENT_H
