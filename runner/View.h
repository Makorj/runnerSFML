#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include "graphicelement.h"
#include "animatedgraphicelement.h"
#include "slidingbackground.h"

const std::string BALLE_IMAGE = "Images/balls.png";

const int SIZE_BALL = 50;

const std::string SLIDING_BACKGROUND_IMAGE1 = "../Images/city_1.png";
const std::string SLIDING_BACKGROUND_IMAGE2 = "../Images/city_2.png";

const std::string SPLASH_IMG2 = "Images/kaaris.png";
const std::string SPLASH_IMG1 = "Images/logo_iut.png";

const sf::IntRect ball_rect1{0,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect2{50,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect3{100,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect4{150,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect5{200,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect6{250,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect7{300,0,SIZE_BALL,SIZE_BALL};
const sf::IntRect ball_rect8{350,0,SIZE_BALL,SIZE_BALL};


class Model;

class View {

private:

    int _w, _h, m_transparent;
    bool m_reverse, m_splashtime, m_logo1;

    sf::Clock time;

    sf::RenderWindow * _window;
    Model * _model;

    sf::Texture _splashImg1;
    GraphicElement _splashImgSprite1;

    sf::Texture _splashImg2;
    GraphicElement _splashImgSprite2;

    sf::Texture _balle;
    AnimatedGraphicElement _balleSprite;

    sf::Texture _SlidingBackground1;
    SlidingBackground _SlidingBackgroundSprite1;

    sf::Texture _SlidingBackground2;
    SlidingBackground _SlidingBackgroundSprite2;


public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    void synchronize();
    bool treatEvents();

};
#endif

