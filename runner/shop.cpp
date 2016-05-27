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
#include "shop.h"
#include <iostream>

using namespace std;
Shop::Shop(int w, int h, const vector<string> MenuItems):
    Menu(w,h,MenuItems),
    m_w(w),
    m_h(h),
    m_gold(0),
    m_bonuses()
{
    for(unsigned int i = 0; i<m_items.size()-1;i++) {
        m_text.push_back(sf::Text());
    }
    for(unsigned int i = 0; i<m_text.size();i++) {
        m_text[i].setFont(m_font);
        m_text[i].setPosition(sf::Vector2f((m_w/2)-75,m_items[i].second.getGlobalBounds().top));
        m_text[i].setString(bonusString[i]);
    }
    for(unsigned int i = 0; i<m_prix.size();i++) {
        m_prix[i] = 100;
    }


}
void Shop::setBonuses(vector<AnimatedGraphicElement> bonuses) {
    m_bonuses = bonuses;
    for(unsigned int i = 0; i<m_bonuses.size(); i++) {
        m_bonuses[i].setPosition(sf::Vector2f((m_w/2)-125,m_items[i].second.getGlobalBounds().top));
    }
}

void Shop::draw(sf::RenderWindow *window) {
    Menu::draw(window);
    for(auto x : m_bonuses)
        x.draw(window);
    int i = 0;
    for (auto x : m_text) {
        if(m_prix[i]!=-1)
            x.setString(x.getString() + "  " + std::to_string(m_prix[i]) + "g");
        else
            x.setString(x.getString() + " Maximised");
        window->draw(x);
        i++;
    }
}

void Shop::setGold(int gold) {
    m_gold = gold;
}

array<int,10> Shop::getSavedParam() {
    return m_parametres;
}

void Shop::setSavedParam(array<int, 10> param) {
    m_parametres = param;
    //MaxLife prices changes, function of m_savedParam
    switch(m_parametres[0]) {
    case 100:
        m_prix[0] = 50;
        break;
    case 125:
        m_prix[0]=75;
        break;
    case 150:
        m_prix[0]=150;
        break;
    default:
        m_prix[0]=-1;
        break;
    }

    //Heal prices changes, function of m_savedParam
    switch(m_parametres[1]) {
    case 20:
        m_prix[1] = 50;
        break;
    case 30:
        m_prix[1]=75;
        break;
    case 40:
        m_prix[1]=150;
        break;
    default:
        m_prix[1]=-1;
        break;
    }

    //Jump prices changes, function of m_savedParam
    switch(m_parametres[2]) {
    case 2:
        m_prix[2]=100;
        break;
    case 3:
        m_prix[2]=150;
        break;
    default:
        m_prix[2]=-1;
        break;
    }

    //Invincibility prices changes, function of m_savedParam
    switch(m_parametres[3]) {
    case 2:
        m_prix[3]=100;
        break;
    case 3:
        m_prix[3]=150;
        break;
    default:
        m_prix[3]=-1;
        break;
    }

    //Multiplier prices changes, function of m_savedParam
    switch(m_parametres[4]) {
    case 2:
        m_prix[4] = 100;
        break;
    case 3:
        m_prix[4]=150;
        break;
    default:
        m_prix[4]=-1;
        break;
    }
}

void Shop::update(int i) {
    if(m_parametres[5] >= m_prix[i] && m_prix[i]!=-1){
        m_parametres[5]-=m_prix[i];
        switch(i) {
        case 0:
            switch(m_parametres[0]) {
            case 100:
                m_parametres[0] = 125;
                break;
            case 125:
                m_parametres[0] = 150;
                break;
            case 150:
                m_parametres[0] = 200;
                break;
            default:
                m_parametres[0] = 100;
                break;
            }
            break;
        case 1:
            switch(m_parametres[1]) {
            case 20:
                m_parametres[1] = 30;
                break;
            case 30:
                m_parametres[1] = 40;
                break;
            case 40:
                m_parametres[1] = 50;
                break;
            default:
                m_parametres[1] = 20;
                break;
            }
            break;
        case 2:
            switch(m_parametres[2]) {
            case 2:
                m_parametres[2] = 3;
                break;
            case 3:
                m_parametres[2] = 4;
                break;
            default:
                m_parametres[2] = 2;
                break;
            }
            break;
        case 3:
            switch(m_parametres[3]) {
            case 2:
                m_parametres[3] = 3;
                break;
            case 3:
                m_parametres[3] = 4;
                break;
            default:
                m_parametres[3] = 2;
                break;
            }
            break;
        case 4:
            switch(m_parametres[4]) {
            case 2:
                m_parametres[4] = 3;
                break;
            case 3:
                m_parametres[4] = 4;
                break;
            default:
                m_parametres[4] = 2;
                break;
            }
            break;
        }

    }
}
