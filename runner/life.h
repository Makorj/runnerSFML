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
    sf::RectangleShape m_life;
    sf::Texture m_texture;
    GraphicElement m_GUI;


public:
    Life(sf::Color begin, sf::Color end, float maxLife);
    sf::Color interpolate();
    void draw(sf::RenderWindow *window);
    void synchronize(float currentLife, int x, int y);
    void setMaxLife(float maxLife);
};

#endif // LIFE_H
