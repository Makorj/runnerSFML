#ifndef MOOVABLEELEMENT_H
#define MOOVABLEELEMENT_H

class MoovableElement
{
    int m_x;
    int m_y;
    int m_h;
    int m_w;
    int m_dx;
    int m_dy;
public:
    MoovableElement(int x, int y, int w, int h, int dx, int dy);
    void moove();
    void setDX(int d);
    void setDY(int d);
    int getX();
    int getY();
};

#endif // MOOVABLEELEMENT_H
