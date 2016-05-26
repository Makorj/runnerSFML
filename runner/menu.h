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
#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
#include "graphicelement.h"
#include <vector>
#define MAX_NUMBER_BOUTONS 4

const std::string MENUITEM_PATH = "../Images/menuitems.png";
//const sf::IntRect READ_RECT = {sf::IntRect{0,0,300,50}, sf::IntRect{0,50,300,50}, sf::IntRect{0,100,300,}};

class Menu
{
protected:
    sf::Font m_font;
    std::vector<std::pair<sf::Text,sf::Sprite> >m_items;
    unsigned int m_selectedItem;
private :
    sf::Texture m_menu_sprite;


    std::vector<std::string> m_stringItems;
public:
    Menu(int w, int h, const std::vector<std::string> &MenuItems);
    void draw(sf::RenderWindow *window);
    void MoveUp();
    void MoveDown();
    void changeString(std::string changed, int pos);
    int getSelectedItem() const;

};

#endif // MENU_H
