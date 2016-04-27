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
  
#include "movableelement.h"

/*!
   \file movableelement.cpp
   \brief MovableElement c++ source file
   \author VAIN Florent, BLANC Thomas
   \date 27/04/2016
*/

MovableElement::MovableElement(float x, float y, int w, int h, float dx, float dy, int type)
    : m_type(type),
      m_x(x),
      m_y(y),
      m_w(w),
      m_h(h),
      m_dx(dx),
      m_dy(dy)
{}

void MovableElement::move() {
    m_x+=m_dx;
}

//!
//! /brief DX setter
//! /param d Float new value
//!
void MovableElement::setDX(float d) {
    m_dx = d;
}


void MovableElement::setDY(float d) {
    m_dy = d;
}

int MovableElement::getType() const {
    return m_type;
}

float MovableElement::getX() const {
    return m_x;
}

float MovableElement::getY() const {
    return m_y;
}

int MovableElement::getH() const {
    return m_h;
}

int MovableElement::getW() const {
    return m_w;
}

bool MovableElement::outOfScreen(){
    if(m_x+m_w<-100)
        return true;
    return false;
}

void MovableElement::apply(Character *charact)
{

}

//!
//! /brief  MovableElement collisions function
//! /param elem1 First MovableElement
//! /param elem2 Second MovableElement
//! /return true if they are collided, false otherwise
//!
bool collide (MovableElement elem1,MovableElement elem2) {
    return (elem1.getX() < elem2.getX() + elem2.getW() &&
            elem1.getX() + elem1.getW() > elem2.getX() &&
            elem1.getY() < elem2.getY() + elem2.getH() &&
            elem1.getY() + elem1.getH() > elem2.getY());
}
