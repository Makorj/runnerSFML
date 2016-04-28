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
#ifndef BONUS_H
#define BONUS_H

#include "movableelement.h"

#define BONUS_TYPE_DEFAULT 0
#define BONUS_TYPE_HEALTH 1
#define BONUS_TYPE_COIN 2
#define BONUS_TYPE_INVICIBILITY 3
#define BONUS_TYPE_DOUBLE_JUMP 4
#define BONUS_TYPE_SCORE 5


class Bonus : public MovableElement
{
private:
    int m_typeBon;
public:
    Bonus(float x, float y, int w, int h, float dx, float dy, int typeBon=BONUS_TYPE_DEFAULT);
    //~Bonus() override;
    int getType() const override;

};
#endif // BONUS_H
