#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle : public MoovableElement
{
public:
    Obstacle(int x, int y, int w, int h, int dx, int dy);
};

#endif // OBSTACLE_H
