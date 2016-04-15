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
