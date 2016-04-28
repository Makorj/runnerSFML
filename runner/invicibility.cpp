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
 * \file invicibility.h
 * \brief Invincibility header file
 */
#include "invicibility.h"
#include "character.h"

/*!
 * \brief Constructor
 */
Invicibility::Invicibility(float x, float y, int w, int h, float dx, float dy, int duration)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_INVICIBILITY),
      m_duration(duration)
{
}


/*!
 * \brief Apply the invicibility effect on a Character.
 * \param charact Character on wich the effect of the invicibility is applied.
 */
void Invicibility::apply(Character* player)
{
    player->startInvicibility(m_duration);
}
