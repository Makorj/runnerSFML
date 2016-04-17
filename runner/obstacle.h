#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <movableelement.h>
#include <character.h>

class Obstacle : public MovableElement
{
private:
    int m_typeObs;
    int m_damage;
public:
    Obstacle(float x, float y, int w, int h, float dx, float dy, int type);
    //~Obstacle() override;
    int getType() const;
    void apply(Character* charact) override;
};

#endif // OBSTACLE_H
