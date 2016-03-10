#include "View.h"
#include "Model.h"


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
using namespace std;

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
    if (!_background.loadFromFile(BACKGROUND_IMAGE))
        std::cerr << "ERROR when loading image file: " << BACKGROUND_IMAGE << std::endl;
    else {
        _background.setSmooth(true);
        GraphicElement tmp{_background, 0,0,_w,_h};
        _backgroundSprite = tmp;
    }

    if (!_splashImg1.loadFromFile(SPLASH_IMG1))
        std::cerr << "ERROR when loading image file: " << SPLASH_IMG1 << std::endl;
    else {
        GraphicElement tmp{_splashImg1, 225,150,384,298};
        _splashImgSprite1 = tmp;
    }

    if (!_splashImg2.loadFromFile(SPLASH_IMG2))
        std::cerr << "ERROR when loading image file: " << SPLASH_IMG2 << std::endl;
    else {
        GraphicElement tmp{_splashImg2, 180,50,452,417};
        _splashImgSprite2 = tmp;
    }

    if (!_balle.loadFromFile(BALLE_IMAGE))
        std::cerr << "ERROR when loading image file: " << BALLE_IMAGE << std::endl;
    else {
        _balle.setSmooth(true);
        GraphicElement tmp{_balle, 1,1,100,100};
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
            if(m_reverse)
            {
                if(m_transparent<=1)
                {
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
            _window->draw(_splashImgSprite1);

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
            _window->draw(_splashImgSprite2);
        }
    }
// END OF SPLASH SCREEN //
    else
    {

    _backgroundSprite.draw(_window);

    _balleSprite.setPosition(_model->getBallPosition());
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
            cout << "Event detected" << endl;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                left=true;
            else
                left=false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                right=true;
            else
                right=false;

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

        _model->setCharDir(left,right);
        _model->moveBall();
    }



    return result;
}

