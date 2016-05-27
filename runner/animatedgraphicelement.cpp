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
#include "animatedgraphicelement.h"
#include <SFML/Graphics.hpp>

AnimatedGraphicElement::AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h)
    :GraphicElement(image, x, y, w, h, false),
      m_pause(false)
{
    m_clipRects = clipRects;
    m_currentClipRect = 0;
    m_nb_steps = 5;
    m_current_step = 0;
    setTextureRect(m_clipRects[m_currentClipRect]);
}
AnimatedGraphicElement::AnimatedGraphicElement(const AnimatedGraphicElement& copy):
    GraphicElement(copy)
{
    m_clipRects = copy.m_clipRects;
    m_currentClipRect = copy.m_currentClipRect;
    m_nb_steps = copy.m_nb_steps;
    m_current_step = copy.m_current_step;
    setTextureRect(m_clipRects[m_currentClipRect]);
}

void AnimatedGraphicElement::draw(sf::RenderWindow *window) {

    if(!m_pause){
        m_current_step++;
        if(m_current_step>=m_nb_steps)
        {
            m_current_step=0;
            m_currentClipRect = m_currentClipRect % m_clipRects.size()+1;
            setTextureRect(m_clipRects[m_currentClipRect-1]);
        }
    }
    window->draw(*this);
}

void AnimatedGraphicElement::pause()
{
    m_pause = m_pause?false:true;
}


