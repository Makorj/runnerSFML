#ifndef HEAL_H
#define HEAL_H
#include "character.h"
#include "bonus.h"


class Heal : public Bonus
{
private:
    int m_healingPower;
public:
    Heal(float x, float y, int w, int h, float dx, float dy, int healingPower);
    void apply(Character* player) override;
};

#endif // HEAL_H
