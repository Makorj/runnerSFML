#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_BOUTONS 4
class Menu
{
private :
    int m_selectedItem;
    sf::Font m_font;
    std::vector<sf::Text> m_items;
public:
    Menu(float w, float h/*,std::string MenuItems[], int size*/);
    void draw(sf::RenderWindow *window);
    void MoveUp();
    void MoveDown();

};

#endif // MENU_H
