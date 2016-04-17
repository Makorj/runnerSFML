#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include "graphicelement.h"

const std::string SPLASH_IMG2 = "../Images/logo_carambar.png";
const std::string SPLASH_IMG1 = "../Images/logo_iut.png";

class SplashScreen
{
private :
    sf::Texture m_splashTexture1;
    sf::Texture m_splashTexture2;
    GraphicElement m_splashImg1;
    GraphicElement m_splashImg2;
    bool m_reverse;
    bool m_splashtime;
    bool m_logo1;
    int m_transparent;
public:
    SplashScreen();
    void draw(sf::RenderWindow *window);
    void synchronize();
    void event();
    bool getSplashTime() const;
};

#endif // SPLASHSCREEN_H
