#ifndef BALLE_H
#define BALLE_H

class Balle
{
private:
    float m_x;
    float m_y;
    int m_h;
    int m_w;
    int m_dx;
    int m_dy;

public:
    Balle(int x, int y, int w, int h, int dx, int dy);
    void move();
    float getX() const;
    float getY() const;
    int getH() const;
    int getW() const;
    void setDX(int &b);
    void setDY(int &b);
};

#endif // BALLE_H
