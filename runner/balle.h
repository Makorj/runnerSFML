#ifndef BALLE_H
#define BALLE_H

class Balle
{
private:
    int m_x;
    int m_y;
    int m_h;
    int m_w;
    int m_dx;
    int m_dy;

public:
    Balle(int x, int y, int w, int h, int dx, int dy);
    void move();
    int getX() const;
    int getY() const;
    int getH() const;
    int getW() const;
    void setDX(int &b);
    void setDY(int &b);
};

#endif // BALLE_H
