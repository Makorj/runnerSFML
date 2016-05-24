#include "shop.h"

using namespace std;
Shop::Shop(int w, int h, const vector<string> MenuItems):
    Menu(w,h,MenuItems),
    m_bonuses(),
    m_w(w),
    m_h(h)
{
    for(unsigned int i = 0; i<m_items.size()-2;i++) {
        m_text.push_back(sf::Text());
    }
    for(unsigned int i = 0; i<m_text.size();i++) {
        m_text[i].setFont(m_font);
        m_text[i].setPosition(sf::Vector2f((m_w/2)-75,m_items[i].second.getGlobalBounds().top));
        m_text[i].setString(bonusString[i]);
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
    for (auto x : m_text)
        window->draw(x);

}

