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
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include "graphicelement.h"

const std::string SPLASH_IMG2 = "../Images/logo_carambar.png";
const std::string SPLASH_IMG1 = "../Images/logo_iut.png";

class SplashScreen
{
private :
    sf::Texture m_splashTexture1;
    sf::Texture m_splashTexture2;
    GraphicElement m_splashImg1;
    GraphicElement m_splashImg2;
    bool m_reverse;
    bool m_splashtime;
    bool m_logo1;
    int m_transparent;
public:
    SplashScreen();
    void draw(sf::RenderWindow *window);
    void synchronize();
    void event();
    bool getSplashTime() const;
};

#endif // SPLASHSCREEN_H
