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
 * \file doublejump.cpp
 * \brief DoubleJump c++ source file
 */

#include "doublejump.h"

/*!
 * \brief Constructor
 * \param x float : X position
 * \param y float : Y position
 * \param w int : Width of the doublejump
 * \param h int : height of the doublejump
 * \param dx float : X speed
 * \param dy float : Y speed
 * \param duration int : Duration of the buff on the character
 */
DoubleJump::DoubleJump(float x, float y, int w, int h, float dx, float dy, int duration)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_DOUBLE_JUMP),
      m_duration(duration)
{}

/*!
 * \brief Apply the doublejump effect on a Character.
 * \param charact Character on wich the effect of the doublejump is applied.
 */
void DoubleJump::apply(Character *player)
{
    player->startDoubleJump(m_duration);
}
