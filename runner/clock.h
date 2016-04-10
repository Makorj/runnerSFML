#ifndef CLOCK_H
#define CLOCK_H

#include <SFML/Graphics.hpp>

class Clock {
private:
    sf::Clock m_time;
    int m_delayAsSec;
public:
    Clock();
    int asMinutes();
    int asSeconds();
    int asMilliseconds();
    void restart();
    void startCounter(int delay);
    bool hasEnded();
};

#endif // CLOCK_H
