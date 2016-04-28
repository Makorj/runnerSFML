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
 * \file coin.cpp
 * \brief Coin c++ source file
 */

#include "coin.h"

int Coin::COIN_MONEY_VALUE=1;

/*!
 * \brief Constructor
 * \param x float : X position
 * \param y float : Y position
 * \param w int : Width of the coin
 * \param h int : height of the coin
 * \param dx float : X speed
 * \param dy float : Y speed
 * \param scoreValue int : Value of a coin in score
 */
Coin::Coin(float x, float y, int w, int h, float dx, float dy, int scoreValue)
    : Bonus(x,y,w,h,dx,dy,BONUS_TYPE_COIN),
      m_scoreValue(scoreValue)
{
}

/*!
 * \brief Apply the coin effect on a Character.
 * \param charact Character on wich the effect of the coin is applied.
 */
void Coin::apply(Character* charact) {
    charact->addScore(m_scoreValue);
    charact->addCoin(COIN_MONEY_VALUE);
}
