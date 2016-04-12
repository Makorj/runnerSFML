#include "menu.h"
#include <iostream>

Menu::Menu(float w, float h/*, std::string MenuItems[], int size*/)
{
    if(!m_font.loadFromFile("../Font/snow.ttf")){
        std::cout << "Font not load" << std::endl;
    }
//    for (int i = 0; i < size; i ++) {
//        m_items[i].setFont(m_font);
//        m_items[i].setColor(sf::Color::White);
//        m_items[i].setString(MenuItems[i]);
//        m_items[i].setPosition(sf::Vector2f(w/2, h/ (size + 1) * (i+1)));
//    }

        m_items[0].setFont(m_font);
        m_items[0].setColor(sf::Color::White);
        m_items[0].setString("Play");
        m_items[0].setPosition(sf::Vector2f(w/2, h/ (MAX_NUMBER_BOUTONS + 1) * 1));

        m_items[1].setFont(m_font);
        m_items[1].setColor(sf::Color::White);
        m_items[1].setString("Best Scores");
        m_items[1].setPosition(sf::Vector2f(w/2, h/ (MAX_NUMBER_BOUTONS + 1) * 2));

        m_items[2].setFont(m_font);
        m_items[2].setColor(sf::Color::White);
        m_items[2].setString("Shop");
        m_items[2].setPosition(sf::Vector2f(w/2, h/ (MAX_NUMBER_BOUTONS + 1) * 3));

        m_items[3].setFont(m_font);
        m_items[3].setColor(sf::Color::White);
        m_items[3].setString("Quit");
        m_items[3].setPosition(sf::Vector2f(w/2, h/ (MAX_NUMBER_BOUTONS + 1) * 4));

    m_selectedItem = 0;

}

void Menu::draw(sf::RenderWindow *window) {
    for(int i = 0; i < MAX_NUMBER_BOUTONS;i++) {
        window->draw(m_items[i]);
    }
}
