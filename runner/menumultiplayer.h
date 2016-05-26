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
    int m_selectedRight;
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
