/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "life.h"
#include <iostream>

using namespace std;

Life::Life(sf::Texture &image, const sf::Color &begin, const sf::Color &end, float maxLife)
    :m_startColor(begin),
      m_endColor(end),
      m_maxLife(maxLife),
      m_currentLife(maxLife),
      m_height(115),
      m_width(10),
      m_life(sf::Vector2f(10,115))

{
    GraphicElement tmp(image,0,0,30,120,false);
    m_GUI = tmp;
    m_life.setFillColor(interpolate());
    m_life.setOrigin(m_life.getLocalBounds().left, m_life.getLocalBounds().height);
}

Life::Life(const Life &health)
    :m_startColor(health.m_startColor),
      m_endColor(health.m_endColor),
      m_maxLife(health.m_maxLife),
      m_currentLife(health.m_currentLife),
      m_height(health.m_height),
      m_width(health.m_width),
      m_GUI(health.m_GUI),
      m_life(sf::Vector2f(m_width,m_height))
{
    m_life.setFillColor(interpolate());
    m_life.setOrigin(m_life.getLocalBounds().left, m_life.getLocalBounds().height);
}

void Life::draw(sf::RenderWindow *window) {
    window->draw(m_life);
    m_GUI.draw(window);
}

sf::Color Life::interpolate() {

    int r = m_endColor.r + (m_startColor.r - m_endColor.r) *(m_currentLife/m_maxLife);
    int g = m_endColor.g + (m_startColor.g - m_endColor.g) *(m_currentLife/m_maxLife);
    int b = m_endColor.b + (m_startColor.b - m_endColor.b) *(m_currentLife/m_maxLife);
    int a = m_endColor.a + (m_startColor.a - m_endColor.a) *(m_currentLife/m_maxLife);
    return sf::Color(r,g,b,a);
}

void Life::synchronize(int currentLife, int x, int y) {
    m_currentLife = currentLife;
    m_GUI.setPosition(x-40,y-20);
    m_life.setPosition(x-30, y-10+2*m_height);
    m_life.setFillColor(interpolate());
    m_life.setSize(sf::Vector2f(10,-115*(m_currentLife/m_maxLife)));
}

void Life::setMaxLife(int maxlife)
{
    m_maxLife=maxlife;
    m_currentLife=maxlife;
}

