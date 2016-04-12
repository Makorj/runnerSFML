#ifndef BONUS_H
#define BONUS_H
#include "movableelement.h"

class Bonus : public MovableElement
{
public:
    Bonus(float x, float y, int w, int h, float dx, float dy, int type);
};

#endif // BONUS_H
