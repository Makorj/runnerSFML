#include "menu.h"
#include <iostream>
#include <map>

Menu::Menu(float w, float h, const std::string MenuItems[], int size):
    m_nb_items(size)
{
    if(!m_menu_sprite.loadFromFile("../Images/menuitems.png")){
        std::cout << "menu image not load"<< std::endl;
    }
    if(!m_font.loadFromFile("../Font/givre.TTF")){
        std::cout << "Font not load" << std::endl;
    }
    sf::Text tmp;
    sf::IntRect rect{0,0,300,50};
    sf::Sprite sprite_tmp{m_menu_sprite};
    sprite_tmp.setTextureRect(rect);
    sprite_tmp.setOrigin(sprite_tmp.getLocalBounds().width/2,sprite_tmp.getLocalBounds().height/2);


    std::cout << sprite_tmp.getLocalBounds().width << "    " << sprite_tmp.getLocalBounds().height << std::endl;

        for (int i = 0; i < m_nb_items; i ++) {
            tmp.setFont(m_font);
            tmp.setColor(sf::Color::Black);
            tmp.setString(MenuItems[i]);
            tmp.setOrigin(tmp.getLocalBounds().width/2, tmp.getLocalBounds().height/2);
            tmp.setPosition(sf::Vector2f(w/4, h/ (m_nb_items + 1) * (i+1)));


            sprite_tmp.setPosition(tmp.getPosition().x,tmp.getPosition().y+7);

            m_items.push_back(std::pair<sf::Text,sf::Sprite>(tmp,sprite_tmp));
        }
    m_selectedItem = 0;

}

void Menu::draw(sf::RenderWindow *window) {
    for (int i = 0; i < m_nb_items; i++ ){
        if(m_selectedItem == i) {
            m_items[i].second.setTextureRect(sf::IntRect(0,50,300,50));
        }
        window->draw(m_items[i].second);
        window->draw(m_items[i].first);

    }
}

void Menu::eventMenu(sf::Mouse mouse, sf::RenderWindow *window) {
//    for( int i = 0; i <m_nb_items; i++) {
//        if(m_items[i].second.getGlobalBounds().contains(mouse.getPosition(*window)))
//            m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
//            m_selectedItem = i;
//    }



}
