#ifndef MOOVABLEELEMENT_H
#define MOOVABLEELEMENT_H

class MovableElement
{
protected:

    float m_x;
    float m_y;

    int m_h;
    int m_w;

    float m_dx;
    float m_dy;

public:

    MovableElement(float x, float y, int w, int h, float dx, float dy);

    void move();

    void setDX(float d);
    void setDY(float d);

    float getX() const;
    float getY() const;
    int getH() const;
    int getW() const;
};

#endif // MOOVABLEELEMENT_H
