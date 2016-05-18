#include "shop.h"

using namespace std;
Shop::Shop(int w, int h, const vector<string> MenuItems):
    Menu(w,h,MenuItems),
    m_mouse()
{
}

void Shop::draw(sf::RenderWindow *window) {

}

int Shop::BonusSelected() {
    for(unsigned int i = 0; i<m_bonuses.size();i++) {
        if(m_mouse.intersects(m_bonuses[0].getGlobalBounds())) {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                return i;
        }
        else
            return -1;
    }
}


void Shop::updateParam() {
    switch(BonusSelected()) {
    case 0:
        m_parametres[0]==100?m_parametres[0]==125?m_parametres[0]==150?175:150:125:100;
    }
}
