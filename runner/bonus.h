#ifndef BONUS_H
#define BONUS_H

#include "movableelement.h"

#define BONUS_TYPE_DEFAULT 0
#define BONUS_TYPE_HEALTH 1
#define BONUS_TYPE_COIN 2
#define BONUS_TYPE_INVICIBILITY 3
#define BONUS_TYPE_DOUBLE_JUMP 4

class Bonus : public MovableElement
{
private:
    int m_typeBon;
public:
    Bonus(float x, float y, int w, int h, float dx, float dy, int typeBon=BONUS_TYPE_DEFAULT);
    int getType() const override;
};

#endif // BONUS_H
