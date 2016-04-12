#ifndef BONUS_H
#define BONUS_H
<<<<<<< HEAD

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
=======
#include "movableelement.h"

class Bonus : public MovableElement
{
public:
    Bonus(float x, float y, int w, int h, float dx, float dy, int type);
>>>>>>> 6c12cccc539de40edd1d5fea0ba216b51f39701c
};

#endif // BONUS_H
