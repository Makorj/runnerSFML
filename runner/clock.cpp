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

/*!
 * \file clock.cpp
 * \brief Clock c++ source file
 */

#include "clock.h"

/*!
 * \brief Constructor
 */
Clock::Clock()
{}

/*!
 * \brief Get the the time elapsed as minutes since the last start of the clock.
 * \return int Minutes elapsed since the last start of the clock.
 */
int Clock::asMinutes(){
    return (m_time.getElapsedTime().asSeconds()/60);
}

/*!
 * \brief Get the the time elapsed as seconds since the last start of the clock.
 * \return int Secondes elapsed since the last start of the clock.
 */
int Clock::asSeconds(){
    return m_time.getElapsedTime().asSeconds();
}

/*!
 * \brief Get the the time elapsed as milliseconds since the last start of the clock.
 * \return int Milliseconds elapsed since the last start of the clock.
 */
int Clock::asMilliseconds(){
    return m_time.getElapsedTime().asMilliseconds();
}

/*!
 * \brief Restart the clock.
 */
void Clock::restart(){
    m_time.restart();
}

/*!
 * \brief Start a counter from the given time in seconds.
 * \param delay int delay of the counter in seconds
 */
void Clock::startCounter(int delay)
{
    m_delayAsSec=delay;
    restart();
}

/*!
 * \brief Give the state of the counter.
 * \return boolean True if the counter as ended, false otherwise
 */
bool Clock::hasEnded(){
    return ((asSeconds() - m_delayAsSec)>=0)?true:false;
}
