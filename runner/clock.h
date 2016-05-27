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
#ifndef CLOCK_H
#define CLOCK_H

/*!
 * \file clock.h
 * \brief Clock header file
 */

#include <SFML/Graphics.hpp>

/*!
 * \brief Time management class
*/
class Clock {
private:
    sf::Clock m_time; ///< Time clock
    int m_delayAsSec;	///< Delai for the timer
    int m_savedTime;
    bool m_pause;
public:
    Clock();
    int asMinutes();
    int asSeconds();
    int asMilliseconds();
    void restart();
    void startCounter(int delay);
    bool hasEnded();
    void pause();
};

#endif // CLOCK_H
