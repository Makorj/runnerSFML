#ifndef LIFE_H
#define LIFE_H
#include "SFML/Graphics.hpp"
#include "graphicelement.h"

class Life
{
private:
    sf::Color m_startColor;
    sf::Color m_endColor;
    float m_maxLife;
    float m_currentLife;
    int m_height;
    int m_width;
    GraphicElement m_GUI;
    sf::RectangleShape m_life;



public:
    Life(sf::Texture &image, const sf::Color &begin, const sf::Color &end, float maxLife);
    Life() = default;
    Life(const Life &health);
    sf::Color interpolate();
    void draw(sf::RenderWindow *window);
    void synchronize(float currentLife, int x, int y);
    void setMaxLife(float maxLife);
};

#endif // LIFE_H
