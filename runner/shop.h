#ifndef SHOP_H
#define SHOP_H

#include "menu.h"
#include "animatedgraphicelement.h"
#include <array>

const std::vector<std::string> bonusString = {"Max Life","Heal","Jump","Invincibility","Multiplier"};

class Shop : public Menu
{
private:
    int m_w,m_h, m_gold;
    std::array<int,10> m_parametres;
    std::vector<AnimatedGraphicElement> m_bonuses;
    std::array<int,5>m_prix;
    std::vector<std::string>m_string;
    std::vector<sf::Text> m_text;
    GraphicElement m_plus;

public:
    Shop(int w, int h, std::vector<std::string> MenuItems);
    void setBonuses(std::vector<AnimatedGraphicElement> bonuses);
    void draw(sf::RenderWindow *window);
    void setGold(int gold);
    std::array<int,10> getSavedParam();
    void setSavedParam(std::array<int,10> param);
    void update(int i);
};

#endif // SHOP_H
