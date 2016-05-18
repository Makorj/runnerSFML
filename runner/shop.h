#ifndef SHOP_H
#define SHOP_H

#include "menu.h"
#include "mouse.h"
#include <array>

using namespace std;

class Shop : public Menu
{
private:
    MyMouse m_mouse;
    std::array<int,10> m_parametres;
    vector<GraphicElement> m_bonuses;
    GraphicElement m_plus;

public:
    Shop(int w, int h, std::vector<std::string> MenuItems);
    void draw(sf::RenderWindow *window) override;
    int BonusSelected();
    void updateParam();

};

#endif // SHOP_H
