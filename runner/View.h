#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include "graphicelement.h"

const std::string BACKGROUND_IMAGE = "Images/city.png";
const std::string BALLE_IMAGE = "Images/ball.png";

const std::string SPLASH_IMG2 = "Images/kaaris.png";
const std::string SPLASH_IMG1 = "Images/logo_iut.png";

class Model;

class View {

private:

    int _w, _h, m_transparent;
    bool m_reverse, m_splashtime, m_logo1;

    sf::RenderWindow * _window;
    Model * _model;

    sf::Texture _background;
    GraphicElement _backgroundSprite;

    sf::Texture _splashImg1;
    GraphicElement _splashImgSprite1;

    sf::Texture _splashImg2;
    GraphicElement _splashImgSprite2;

    sf::Texture _balle;
    GraphicElement _balleSprite;

public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    bool treatEvents();

};
#endif

