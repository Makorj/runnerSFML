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
	\file movableement.h
	\brief MovableElement c++ header file
	\author VAIN Florent, BLANC Thomas
*/

#ifndef MOOVABLEELEMENT_H
#define MOOVABLEELEMENT_H

#define MOVABLE_ELEMENT_TYPE_DEFAULT 0
#define MOVABLE_ELEMENT_TYPE_OBSTACLE 1
#define MOVABLE_ELEMENT_TYPE_BONUS 2
#define MOVABLE_ELEMENT_TYPE_PIECE 3
#define MOVABLE_ELEMENT_TYPE_CHAR 4

class Character;

/*!
 * \brief Abstract base class for all element in the game that move.
 * 
*/
class MovableElement
{
private:



protected:

    int m_type;     ///< Type is used to avoid dynamic casting

    float m_x; 		///< X position
    float m_y; 		///< Y position

    int m_h;		///< Element's Height
    int m_w;		///< Element's Width

    float m_dx;		///< X speed
    float m_dy;		///< Y speed

public:

    MovableElement(float x, float y, int w, int h, float dx, float dy, int type=MOVABLE_ELEMENT_TYPE_DEFAULT);

    virtual ~MovableElement();

    void move();

    void setDX(float d);
    void setDY(float d);

    virtual int getType() const = 0 ;
    float getX() const;
    float getY() const;
    int getH() const;
    int getW() const;
    virtual void apply(Character* charact);

    bool outOfScreen();
};

bool collide (MovableElement * elem1,MovableElement * elem2);

#endif // MOOVABLEELEMENT_H
