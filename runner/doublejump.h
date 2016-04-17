#ifndef DOUBLEJUMP_H
#define DOUBLEJUMP_H
#include "bonus.h"
#include "character.h"


class DoubleJump : public Bonus
{
private:
    int m_duration;
public:
    DoubleJump(float x, float y, int w, int h, float dx, float dy, int duration);
    //~DoubleJump() override;
    void apply(Character* player) override;
};

#endif // DOUBLEJUMP_H
