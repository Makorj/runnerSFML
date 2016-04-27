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
#include "splashscreen.h"
#include <iostream>

SplashScreen::SplashScreen():
    m_reverse(false),
    m_splashtime(true),
    m_logo1(true),
    m_transparent(0)
{
    if (!m_splashTexture1.loadFromFile(SPLASH_IMG1))
        std::cout << "ERROR when loading image file: " << SPLASH_IMG1 << std::endl;
    else {
        m_splashTexture1.setSmooth(true);
        GraphicElement tmp{m_splashTexture1, 115,150,1000,298};
        m_splashImg1 = tmp;
        m_splashImg1.setTransparency(m_transparent);
    }

    if (!m_splashTexture2.loadFromFile(SPLASH_IMG2))
        std::cout << "ERROR when loading image file: " << SPLASH_IMG2 << std::endl;
    else {
        m_splashTexture2.setSmooth(true);
        GraphicElement tmp{m_splashTexture2, 0,65,1200,500};
        m_splashImg2 = tmp;
        m_splashImg2.setTransparency(m_transparent);
    }
}

void SplashScreen::draw(sf::RenderWindow *window) {
    if(m_logo1)
    {
        window->draw(m_splashImg1);
    }
    else
    {
        window->draw(m_splashImg2);
    }
}

void SplashScreen::synchronize() {

    if(m_logo1)
    {
        if(m_reverse)
        {
            if(m_transparent<=1)
            {
                m_transparent=0;
                m_logo1=false;
                m_reverse=false;
            }
            else
                (m_transparent-=2);
        }
        else
        {
            if(m_transparent>=254)
                (m_reverse=true);
            else
                (m_transparent+=2);
        }
        m_splashImg1.setTransparency(m_transparent);
    }
    else
    {
        if(m_reverse)
        {
            if(m_transparent<=1)
            {
                m_splashtime=false;
                m_reverse=false;
            }
            else
                (m_transparent-=2);
        }
        else
        {
            if(m_transparent>=254)
                (m_reverse=true);
            else
                (m_transparent+=2);
        }
        m_splashImg2.setTransparency(m_transparent);
    }
}

void SplashScreen::event() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        if(m_logo1)
        {
            m_logo1=false;
            m_reverse=false;
            m_transparent=0;
        }
        else {
            m_splashtime=false;
        }
    }
}


bool SplashScreen::getSplashTime() const {
    return m_splashtime;
}
