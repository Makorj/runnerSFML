#ifndef BONUS_H
#define BONUS_H
//<<<<<<< HEAD

#include "movableelement.h"

#define BONUS_TYPE_DEFAULT 0
#define BONUS_TYPE_HEALTH 1
#define BONUS_TYPE_COIN 2
#define BONUS_TYPE_INVICIBILITY 3
#define BONUS_TYPE_DOUBLE_JUMP 4
#define BONUS_TYPE_SCORE 5

class Bonus : public MovableElement
{
private:
    int m_typeBon;
public:
    Bonus(float x, float y, int w, int h, float dx, float dy, int typeBon=BONUS_TYPE_DEFAULT);
    //~Bonus() override;
    int getType() const override;

};
#endif // BONUS_H
