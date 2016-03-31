#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <movableelement.h>
#include <balle.h>

class Obstacle : public MovableElement
{
private:
    int m_difficulty;
    int m_damage;
public:
    Obstacle(float x, float y, int w, int h, float dx, float dy, int difficulty);

    void damageChar(Balle& player);
};

#endif // OBSTACLE_H
