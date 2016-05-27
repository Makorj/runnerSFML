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
#include "menuhost.h"


MenuHost::MenuHost(int w, int h, const std::vector<std::string> &MenuItems)
    : Menu(w,h,MenuItems),
      m_h(h),
      m_w(w),
      m_rightSelected(false),
      m_selectedRight(1)
{
    m_backRec = sf::RectangleShape{sf::Vector2f{650,500}};
    m_backRec.setFillColor(sf::Color{0,0,0,128});
    m_backRec.setPosition(sf::Vector2f{500,30});
}

void MenuHost::draw(sf::RenderWindow *window)
{
    Menu::draw(window);
    window->draw(m_backRec);

    for(auto x : m_rightText)
    {
        window->draw(x);
    }
}

void MenuHost::moveDown()
{
    if(m_rightSelected)
    {
        if(m_selectedRight + 1 < m_rightText.size())
        {
            m_rightText[m_selectedRight].setColor(sf::Color::White);
            m_rightText[m_selectedRight].setPosition((m_rightText[m_selectedRight].getPosition().x)-10,m_rightText[m_selectedRight].getPosition().y);
            m_selectedRight++;
            m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
            m_rightText[m_selectedRight].setPosition((m_rightText[m_selectedRight].getPosition().x)+10,m_rightText[m_selectedRight].getPosition().y);
        }
    }
    else
    {
        if(m_selectedItem + 1 < m_stringItems.size()) {
            m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
            m_selectedItem++;
            m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,50,300,50));
        }
    }
}

void MenuHost::moveUp()
{
    if(m_rightSelected)
    {
        if(m_selectedRight > 1)
        {
        m_rightText[m_selectedRight].setColor(sf::Color::White);
        m_rightText[m_selectedRight].setPosition((m_rightText[m_selectedRight].getPosition().x)-10,m_rightText[m_selectedRight].getPosition().y);
        m_selectedRight--;
        m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
        m_rightText[m_selectedRight].setPosition((m_rightText[m_selectedRight].getPosition().x)+10,m_rightText[m_selectedRight].getPosition().y);
        }
    }
    else
    {
        if(m_selectedItem > 0) {
            m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
            m_selectedItem--;
            m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,50,300,50));
        }
    }
}

void MenuHost::moveLeft()
{
    if(m_rightSelected && m_rightText.size()>1)
    {
        m_rightSelected=false;
        m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
        m_rightText[m_selectedRight].setPosition((m_rightText[m_selectedRight].getPosition().x)-10,m_rightText[m_selectedRight].getPosition().y);
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,50,300,50));
    }
}

void MenuHost::moveRight()
{
    if(!m_rightSelected && m_rightText.size()>1)
    {
        m_rightSelected=true;
        m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
        m_rightText[m_selectedRight].setPosition((m_rightText[m_selectedRight].getPosition().x)+10,m_rightText[m_selectedRight].getPosition().y);
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
    }
}

void MenuHost::setClientList(std::map<int, clientInfo> *clients)
{
    m_rightList.clear();
    for(auto x : *clients)
        m_rightList.push_back(x.second);
    m_rightText.clear();
    if(m_rightList.size()!=0)
    {
        int i=1;
        m_rightText.push_back(sf::Text{"Nb\t\t\t\t\t\tName\t\t\t\t\t\tIP:PORT",m_font,30});
        m_rightText[0].setPosition(sf::Vector2f{520.f, ((1.f)*((((m_h/2)/2)/2)/2))});
        for(clientInfo x : m_rightList)
        {
            std::string data = std::to_string(i) +"\t\t\t"+ x.name;
            data += "\t\t\t" + x.adresse + ":" + std::to_string(x.port);
            m_rightText.push_back(sf::Text{data, m_font, 30});
            m_rightText[i].setColor(sf::Color::White);
            m_rightText[i].setPosition(sf::Vector2f{520.f, ((i+1.f)*((((m_h/2)/2)/2)/2))});
            i++;
        }
    }
    else
    {
        m_rightText.push_back(sf::Text{"Nb\t\t\t\tName\t\t\t\tIP:PORT\t\t\t\t\tPlayers",m_font,30});
        m_rightText[0].setPosition(sf::Vector2f{520.f, ((1.f)*((((m_h/2)/2)/2)/2))});
    }
}
