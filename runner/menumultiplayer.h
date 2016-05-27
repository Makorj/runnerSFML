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

#ifndef MENUMULTIPLAYER_H
#define MENUMULTIPLAYER_H

#include <menu.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include <client.h>

class MenuMultiPlayer : public Menu
{
private:
    sf::RectangleShape m_backRec;
    int m_h, m_w;
    std::vector<hostInfo> m_rightList;
    std::vector<sf::Text> m_rightText;
    bool m_rightSelected;
    unsigned int m_selectedRight;
public:
    MenuMultiPlayer(int w, int h, const std::vector<std::string> &MenuItems);
    ~MenuMultiPlayer() = default;
    void draw(sf::RenderWindow *window);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getSelectedHost() const;
    void setHostsList(std::vector<hostInfo> hosts);

};

#endif // MENUMULTIPLAYER_H
