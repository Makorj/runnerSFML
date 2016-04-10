#ifndef BALLE_H
#define BALLE_H

#include <SFML/Graphics.hpp>
#include <movableelement.h>
#include "clock.h"
#include "character.h"

class Balle : public MovableElement
{
private:

    Clock jumpTime;
    bool m_jumping;

public:
    Balle(float x, float y, int w, int h, float dx, float dy);


};

#endif // BALLE_H
