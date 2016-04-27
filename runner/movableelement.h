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
#ifndef MOOVABLEELEMENT_H
#define MOOVABLEELEMENT_H

#define MOVABLE_ELEMENT_TYPE_DEFAULT 0
#define MOVABLE_ELEMENT_TYPE_OBSTACLE 1
#define MOVABLE_ELEMENT_TYPE_BONUS 2
#define MOVABLE_ELEMENT_TYPE_PIECE 3
#define MOVABLE_ELEMENT_TYPE_CHAR 4

class Character;

class MovableElement
{
private:

    int m_type;

protected:

    float m_x;
    float m_y;

    int m_h;
    int m_w;

    float m_dx;
    float m_dy;

public:

    MovableElement(float x, float y, int w, int h, float dx, float dy, int type=MOVABLE_ELEMENT_TYPE_DEFAULT);

    //virtual ~MovableElement();

    void move();

    void setDX(float d);
    void setDY(float d);

    virtual int getType() const;
    float getX() const;
    float getY() const;
    int getH() const;
    int getW() const;
    virtual void apply(Character* charact);

    bool outOfScreen();
};

bool collide (MovableElement elem1,MovableElement elem2);

#endif // MOOVABLEELEMENT_H
