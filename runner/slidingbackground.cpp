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
{
}


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
