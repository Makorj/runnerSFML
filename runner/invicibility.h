#ifndef INVICIBILITY_H
#define INVICIBILITY_H

#include "character.h"
#include "bonus.h"

class Invicibility : public Bonus
{
private:
    int m_duration;
public:
    Invicibility(float x, float y, int w, int h, float dx, float dy, int duration);
    void apply(Character* player) override;
};

#endif // INVICIBILITY_H
