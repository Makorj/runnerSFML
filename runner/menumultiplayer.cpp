#include "menumultiplayer.h"
#include "iostream"

MenuMultiPlayer::MenuMultiPlayer(int w, int h, const std::vector<std::string> &MenuItems)
    : Menu(w,h,MenuItems),
      m_h(h),
      m_w(w),
      m_rightSelected(false),
      m_selectedRight(1)
{

    m_rightText.push_back(sf::Text{"Nb\tName\t\t\tIP:PORT\t\tPlayers",m_font,30});
    m_rightText[0].setPosition(sf::Vector2f{520, 50+((i+1)*((((m_h/2)/2)/2)/2))});
    hostInfo x {"192.168.15.548", 2512, "Lol", 5};
    int b=0;
    for(int i = 1; i< 6 ; i++)
    {
        int pos(0);
        std::string data = std::to_string(i+1) +"\t"+ x.name;
        data += "\t\t\t" + x.adresse + ":" + std::to_string(x.port);
        data += "\t\t" + std::to_string(x.playerNumber) + "/25";
        b = (data.size()>b?data.size():b);
        m_rightText.push_back(sf::Text{data, m_font, 30});
        m_rightText[i].setColor(sf::Color::White);
        m_rightText[i].setPosition(sf::Vector2f{520, 50+((i+1)*((((m_h/2)/2)/2)/2))});
    }

    m_backRec = sf::RectangleShape{sf::Vector2f{650,500}};
    m_backRec.setFillColor(sf::Color{0,0,0,128});
    m_backRec.setPosition(sf::Vector2f{500,30});
}

void MenuMultiPlayer::draw(sf::RenderWindow *window)
{
    Menu::draw(window);
    window->draw(m_backRec);

    for(auto x : m_rightText)
    {
        window->draw(x);
    }
}

void MenuMultiPlayer::moveDown()
{
    if(m_rightSelected)
    {
        if(m_selectedRight + 1 < m_rightText.size())
        {
            m_rightText[m_selectedRight].setColor(sf::Color::White);
            m_selectedRight++;
            m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
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

void MenuMultiPlayer::moveUp()
{
    if(m_rightSelected)
    {
        if(m_selectedRight > 1)
        {
        m_rightText[m_selectedRight].setColor(sf::Color::White);
        m_selectedRight--;
        m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
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

void MenuMultiPlayer::moveLeft()
{
    if(m_rightSelected)
    {
        m_rightSelected=false;
        m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,50,300,50));
    }
}

void MenuMultiPlayer::moveRight()
{
    if(!m_rightSelected)
    {
        m_rightSelected=true;
        m_rightText[m_selectedRight].setColor(sf::Color::Cyan);
        m_items[m_selectedItem].second.setTextureRect(sf::IntRect(0,0,300,50));
    }
}

void MenuMultiPlayer::setHostsList(std::vector<hostInfo> hosts)
{
    m_rightList = hosts;
    m_rightText.clear();
    if(m_rightList.size()!=0)
    {
        int csaeH = m_h/m_rightList.size();
        int cpt=1;
        for(hostInfo x : m_rightList)
        {
            m_rightText.push_back(sf::Text{x.to_string(), m_font, 30});
            m_rightText.end()->setPosition(sf::Vector2f{800, csaeH*cpt});
            cpt++;
        }
    }
    else
    {
        std::cout << "pooo" << std::endl;
        m_rightText.push_back(sf::Text{" - - ", m_font, 30});
        m_rightText[0].setPosition(sf::Vector2f{800, m_h/2});
    }
}
