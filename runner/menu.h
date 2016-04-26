#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "graphicelement.h"
#include <map>
#define MAX_NUMBER_BOUTONS 4

const std::string MENUITEM_PATH = "../Images/menuitems.png";
//const sf::IntRect READ_RECT = {sf::IntRect{0,0,300,50}, sf::IntRect{0,50,300,50}, sf::IntRect{0,100,300,}};

class Menu
{
private :
    sf::Texture m_menu_sprite;
    int m_nb_items;
    int m_selectedItem;
    sf::Font m_font;
    std::vector<std::pair<sf::Text,sf::Sprite> >m_items;
public:
    Menu(float w, float h, const std::string MenuItems[], int size);
    void draw(sf::RenderWindow *window);
    void hoverMenu(sf::Vector2f mouse);
    void MoveUp();
    void MoveDown();
    int getSelectedItem() const;

};

#endif // MENU_H
