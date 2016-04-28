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
#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(float x, float y, int w, int h, float dx, float dy, int type)
    : MovableElement(x,(type<2?y:y-h),(type<=2?w:w*2),(type<2?h:h*2),dx,dy,MOVABLE_ELEMENT_TYPE_OBSTACLE),
      m_typeObs(type),
      m_damage((5*m_typeObs)+((5*(m_typeObs*m_typeObs))))
{
}

void Obstacle::apply(Character *player) {
    player->damage(m_damage);
}

int Obstacle::getType() const {
    return (MOVABLE_ELEMENT_TYPE_OBSTACLE*10)+m_typeObs;
}

int Obstacle::getDamage() const {
    return m_damage;
}
