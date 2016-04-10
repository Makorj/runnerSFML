#include "clock.h"

Clock::Clock()
{}

int Clock::asMinutes(){
    return (m_time.getElapsedTime().asSeconds()/60);
}

int Clock::asSeconds(){
    return m_time.getElapsedTime().asSeconds();
}

int Clock::asMilliseconds(){
    return m_time.getElapsedTime().asMilliseconds();
}

void Clock::restart(){
    m_time.restart();
}

void Clock::startCounter(int delay)
{
    m_delayAsSec=delay;
    restart();
}

bool Clock::hasEnded(){
    return ((asSeconds() - m_delayAsSec)>=0)?true:false;
}
