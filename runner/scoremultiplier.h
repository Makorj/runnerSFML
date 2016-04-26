#ifndef SCOREMULTIPLIER_H
#define SCOREMULTIPLIER_H

#include "character.h"
#include "bonus.h"

class ScoreMultiplier : public Bonus
{
private :
    int m_duration;
public:
    ScoreMultiplier(float x, float y, int w, int h, float dx, float dy, int duration);
    void apply(Character* player) override;
};

#endif // SCOREMULTIPLIER_H
