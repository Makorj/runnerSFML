#include "life.h"
#include <iostream>

using namespace std;

Life::Life(sf::Color begin, sf::Color end, float maxLife)
    :m_startColor(begin),
      m_endColor(end),
      m_maxLife(maxLife),
      m_currentLife(maxLife),
      m_life(sf::Vector2f(10,115))
{
    if(!m_texture.loadFromFile("../Images/lifeSlider.png")) {
        //cerr << "ERROR when loading image file: ../Images/lifeSlider.png" << endl;
    }
    GraphicElement tmp(m_texture,0,0,30,120,false);
    m_GUI = tmp;
    m_life.setFillColor(interpolate());
    m_life.setOrigin(m_life.getLocalBounds().left, m_life.getLocalBounds().height);
}

void Life::draw(sf::RenderWindow *window) {
    window->draw(m_life);
    m_GUI.draw(window);
}

sf::Color Life::interpolate() {
    cout << "ratio vie :" << (m_currentLife/m_maxLife) << endl;
    int r = m_endColor.r + (m_startColor.r - m_endColor.r) *(m_currentLife/m_maxLife);
    int g = m_endColor.g + (m_startColor.g - m_endColor.g) *(m_currentLife/m_maxLife);
    int b = m_endColor.b + (m_startColor.b - m_endColor.b) *(m_currentLife/m_maxLife);
    int a = m_endColor.a + (m_startColor.a - m_endColor.a) *(m_currentLife/m_maxLife);
    return sf::Color(r,g,b,a);
}

void Life::synchronize(float currentLife, int x, int y) {
    m_currentLife = currentLife;
    m_GUI.setPosition(x-40,y-20);
    m_life.setPosition(x-30, y-10+m_life.getLocalBounds().height);
    m_life.setFillColor(interpolate());
    //m_life.setSize(sf::Vector2f(m_life.getLocalBounds().width,m_life.getLocalBounds().height-(m_life.getLocalBounds().height*(m_currentLife/m_maxLife))));
}

