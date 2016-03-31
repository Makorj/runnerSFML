#include "View.h"
#include "Model.h"

#include <math.h>


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace std;

const unsigned int SPEED = 2;
const unsigned int SPEED1 = 1;
//=======================================
// Constructeur
//=======================================
View::View(int w, int h)
    : _w(w), _h(h),
      m_transparent(0),
      m_reverse(false),
      m_splashtime(true),
      m_logo1(true)
{

    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner", sf::Style::Close);
    _window->setFramerateLimit(60);
    _window->setKeyRepeatEnabled(false);

    // IMAGE LOADER //
    if (!_SlidingBackground1.loadFromFile(SLIDING_BACKGROUND_IMAGE1))
        std::cerr << "ERROR when loading image file: " << SLIDING_BACKGROUND_IMAGE1 << std::endl;
    else {
        _SlidingBackground1.setSmooth(true);
        SlidingBackground tmp{_SlidingBackground1,_w,_h,SPEED};
        _SlidingBackgroundSprite1 = tmp;
    }

    if (!_SlidingBackground2.loadFromFile(SLIDING_BACKGROUND_IMAGE2))
        std::cerr << "ERROR when loading image file: " << SLIDING_BACKGROUND_IMAGE2 << std::endl;
    else {
        _SlidingBackground2.setSmooth(true);
        SlidingBackground tmp{_SlidingBackground2,_w,_h,SPEED1};
        _SlidingBackgroundSprite2 = tmp;
    }

    if (!_splashImg1.loadFromFile(SPLASH_IMG1))
        std::cerr << "ERROR when loading image file: " << SPLASH_IMG1 << std::endl;
    else {
        GraphicElement tmp{_splashImg1, 225,150,384,298};
        _splashImgSprite1 = tmp;
        _splashImgSprite1.setTransparency(m_transparent);
    }

    if (!_splashImg2.loadFromFile(SPLASH_IMG2))
        std::cerr << "ERROR when loading image file: " << SPLASH_IMG2 << std::endl;
    else {
        GraphicElement tmp{_splashImg2, 180,50,452,417};
        _splashImgSprite2 = tmp;
        _splashImgSprite2.setTransparency(m_transparent);
    }
    vector<sf::IntRect> clipRect_balle;
    for (int i=0;i<8;i++) {
        clipRect_balle.push_back(sf::IntRect(i*SIZE_BALL,0, SIZE_BALL, SIZE_BALL));
    }

    if (!_balle.loadFromFile(BALLE_IMAGE))
        std::cerr << "ERROR when loading image file: " << BALLE_IMAGE << std::endl;
    else {
        _balle.setSmooth(true);
        AnimatedGraphicElement tmp{clipRect_balle, _balle, 1,1,50,50};
        _balleSprite = tmp;
    }
    // END OF IMAGE LOADER //
}

//=======================================
// Destructeur
//=======================================
View::~View(){
    if(_window!= NULL)
        delete _window;
}

//=======================================
// Accesseurs en écriture
//=======================================
void View::setModel(Model * model){
    _model = model;
}

//=======================================
// Fonction de dessin
//=======================================
void View::draw(){
    _window->clear();

    // SPLASH SCREEN //
    if(m_splashtime)
    {
        if(m_logo1)
        {
            _window->draw(_splashImgSprite1);
        }
        else
        {
            _window->draw(_splashImgSprite2);
        }
    }
    // END OF SPLASH SCREEN //
    else
    {
        _SlidingBackgroundSprite2.draw(_window);
        _SlidingBackgroundSprite1.draw(_window);

        _balleSprite.draw(_window);
    }

    _window->display();
}

//=======================================
// Traitement des evenements
//=======================================
bool View::treatEvents(){
    bool result = false;
    bool left(false), right(false);
    _model->getCharDir(left,right);

    if(_window->isOpen()){
        result = true;

        sf::Event event;
        while (_window->pollEvent(event)) {
            //cout << "Event detected" << endl;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                left=true;
            else
                left=false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                right=true;
            else
                right=false;

            // JUMP KEY
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                _model->jumpBall();
            }

            // SPLASH SCREEN SKEEPER //
            if (m_splashtime && (event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Return))
            {
                if(m_logo1)
                {
                    m_logo1=false;
                    m_reverse=false;
                    m_transparent=0;
                }
                else
                    m_splashtime=false;
            }
            // END OF SPLASH SCREEN SKEEPER //

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();
                result = false;
            }
        }


    }
        _model->setCharDir(left,right);


       // std::cout << _model->getBallPosition().y << endl;


    return result;
}

void View::synchronize()
{
    //SplashScreen
    if(m_splashtime)
    {
        if(m_logo1)
        {
            if(m_reverse)
            {
                if(m_transparent<=1)
                {
                    m_transparent=0;
                    m_logo1=false;
                    m_reverse=false;
                }
                else
                    (m_transparent-=2);
            }
            else
            {
                if(m_transparent>=254)
                    (m_reverse=true);
                else
                    (m_transparent+=2);
            }
            _splashImgSprite1.setTransparency(m_transparent);

        }
        else
        {
            if(m_reverse)
            {
                if(m_transparent<=1)
                {
                    m_splashtime=false;
                    m_reverse=false;
                }
                else
                    (m_transparent-=2);
            }
            else
            {
                if(m_transparent>=254)
                    (m_reverse=true);
                else
                    (m_transparent+=2);
            }
            _splashImgSprite2.setTransparency(m_transparent);
        }
    }
    //EndSplashScreen


    //Ball's Position Updating
    _balleSprite.setPosition(_model->getBallPosition());


    //Move
    _model->moveBall();


}
