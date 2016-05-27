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
    void synchronize(int currentLife, int x, int y);
    void setMaxLife(int maxlife);
};

#endif // LIFE_H
