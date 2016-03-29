#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <movableelement.h>

class Obstacle : public MovableElement
{
public:
    Obstacle(int x, int y, int w, int h, int dx, int dy);
};

#endif // OBSTACLE_H
