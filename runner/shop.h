#ifndef SHOP_H
#define SHOP_H

#include "menu.h"
#include "animatedgraphicelement.h"
#include "mouse.h"
#include <array>

using namespace std;
const vector<string> bonusString = {"Heal","Jump","Invincibility","Multiplier"};

class Shop : public Menu
{
private:
    int m_w,m_h;
    Mouse m_mouse;
    array<int,10> m_parametres;
    vector<AnimatedGraphicElement> m_bonuses;
    vector<string>m_string;
    vector<sf::Text> m_text;
    GraphicElement m_plus;

public:
    Shop(int w, int h, std::vector<std::string> MenuItems);
    void setBonuses(vector<AnimatedGraphicElement> bonuses);
    void draw(sf::RenderWindow *window);
    int BonusSelected(sf::Mouse mouse);
    array<int,10> getParam();
};

#endif // SHOP_H
