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
#include "slidingbackground.h"
#include "graphicelement.h"

SlidingBackground::SlidingBackground(sf::Texture &image, int w, int h,float speed):
    m_w(w),
    m_h(h),
    m_speed(speed)
{
    GraphicElement tmp{image, 0, 0, m_w, m_h};
    m_left = tmp;
    GraphicElement tmp1{image, m_w, 0 ,m_w ,m_h};
    m_right = tmp1;
}

SlidingBackground::SlidingBackground(const SlidingBackground& copy):
    m_left(copy.m_left),
    m_right(copy.m_right),
    m_speed(copy.m_speed)
{}


void SlidingBackground::draw(sf::RenderWindow *window) {

    m_left.draw(window);
    m_left.slideLeft(m_speed);
    m_right.draw(window);
    m_right.slideLeft(m_speed);
    if(m_right.getX()-1<0) {
        m_left.replace(0,0);
        m_right.replace(m_w,0);
    }
}

void SlidingBackground::setSpeed(float s) {
    m_speed = s;
}
