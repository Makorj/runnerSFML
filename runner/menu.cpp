/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "menu.h"
#include <iostream>
#include <map>

Menu::Menu(int w, int h, const std::vector<std::string> &MenuItems):
    m_selectedItem(0),
    m_stringItems(MenuItems)
{
    if(!m_menu_sprite.loadFromFile("../Images/menuitems.png")){
        std::cerr << "menu image not load"<< std::endl;
    }
    if(!m_font.loadFromFile("../Font/givre.TTF")){
        std::cerr << "Font not load" << std::endl;
    }
    sf::Text tmp;
    sf::IntRect rect{0,0,300,50};
    sf::Sprite sprite_tmp{m_menu_sprite};
    sprite_tmp.setTextureRect(rect);
    sprite_tmp.setOrigin(sprite_tmp.getLocalBounds().width/2,sprite_tmp.getLocalBounds().height/2);

    for (unsigned int i = 0; i < m_stringItems.size(); i ++) {
        tmp.setFont(m_font);
        tmp.setColor(sf::Color::White);
        tmp.setString(MenuItems[i]);
        tmp.setOrigin(tmp.getLocalBounds().width/2, tmp.getLocalBounds().height/2);
        tmp.setPosition(sf::Vector2f(w/4, h/ (m_stringItems.size() + 1) * (i+1)));


        sprite_tmp.setPosition(tmp.getPosition().x,tmp.getPosition().y+7);

        m_items.push_back(std::pair<sf::Text,sf::Sprite>(tmp,sprite_tmp));
    }
    m_items[0].second.setTextureRect(sf::IntRect(0,50,300,50));
    m_selectedItem = 0;

}

void Menu::draw(sf::RenderWindow *window) {
    for (unsigned int i = 0; i < m_stringItems.size(); i++ ){
        window->draw(m_items[i].second);
        window->draw(m_items[i].first);

    }
}

void Menu::MoveUp() {
    if(m_selectedItem > 0) {
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
        m_selectedItem--;
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,50,300,50));
    }
}

void Menu::MoveDown() {
    if(m_selectedItem + 1 < m_stringItems.size()) {
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
        m_selectedItem++;
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,50,300,50));
    }
}

void Menu::changeString(std::string changed, int pos) {
    m_stringItems[pos] = changed;
    m_items[pos].first.setString(changed);
    m_items[pos].first.setOrigin(m_items[pos].first.getLocalBounds().width/2, m_items[pos].first.getLocalBounds().height/2);
}


int Menu::getSelectedItem() const {
    return m_selectedItem;
}
