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
      m_logo1(true),
      m_menu(true),
      m_mainmenu{w,h,MAIN_MENU_ITEMS,NB_MAINMENU_ITEMS}
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
    if (!_coin.loadFromFile(COIN_IMG))
        std::cerr << "ERROR when loading image file: " << COIN_IMG << std::endl;
    else {
        GraphicElement tmp{_coin, 0,0,50,50};
        _coinSprite = tmp;
    }

    if (!_elem.loadFromFile(ELEM_IMG))
        std::cerr << "ERROR when loading image file: " << ELEM_IMG << std::endl;
    else {
        GraphicElement tmp{_elem, 0,0,50,50};
        _elemSprite = tmp;
    }

    if (!_boobaSong.openFromFile(SONG_BOOBA))
        std::cerr << "ERROR when opening music stram with file: " << SONG_BOOBA << std::endl;
    else
    {
        _boobaSong.setLoop(false);
        _boobaSong.setVolume(30.);
    }

    if (!_boobaLoop.openFromFile(SONG_BOOBA))
        std::cerr << "ERROR when opening music stram with file: " << SONG_BOOBA_LOOP << std::endl;
    else
    {
        _boobaLoop.setLoop(true);
        _boobaLoop.setVolume(30.);
    }

    if (!izi.loadFromFile(SOUND_IZI))
        std::cerr << "ERROR when opening sound stream with file: " << SOUND_IZI << std::endl;
    else
        Jump.setBuffer(izi);

    if (!carre.loadFromFile(SOUND_CARRE))
        std::cerr << "ERROR when opening sound stream with file: " << SOUND_CARRE << std::endl;
    else
        Collision.setBuffer(carre);


    vector<sf::IntRect> clipRect_balle;
//    for (int i=0;i<8;i++) {
//        clipRect_balle.push_back(sf::IntRect(i*SIZE_BALL,0, SIZE_BALL, SIZE_BALL));
//    }

    clipRect_balle.push_back(ball_rect1);
    clipRect_balle.push_back(ball_rect2);
    clipRect_balle.push_back(ball_rect3);
    clipRect_balle.push_back(ball_rect4);
    clipRect_balle.push_back(ball_rect5);
    clipRect_balle.push_back(ball_rect6);
    clipRect_balle.push_back(ball_rect7);
    clipRect_balle.push_back(ball_rect8);

    if (!_balle.loadFromFile(BALLE_IMAGE))
        std::cerr << "ERROR when loading image file: " << BALLE_IMAGE << std::endl;
    else {
        _balle.setSmooth(true);
        AnimatedGraphicElement tmp{clipRect_balle, _balle, 1,1,40,40};
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
    if(m_splashscreen.getSplashTime())
        m_splashscreen.draw(_window);
    // END OF SPLASH SCREEN //
    else if(m_menu) {

        _SlidingBackgroundSprite2.draw(_window);
        _SlidingBackgroundSprite1.draw(_window);
         m_mainmenu.draw(_window);
    }
    else
    {
        if(_boobaSong.getStatus()==sf::SoundSource::Stopped && _boobaLoop.getStatus()!=sf::SoundSource::Playing)
            _boobaLoop.play();
        else if(_boobaSong.getStatus()!=sf::SoundSource::Playing && _boobaLoop.getStatus()!=sf::SoundSource::Playing)
            _boobaSong.play();

        _SlidingBackgroundSprite2.draw(_window);
        _SlidingBackgroundSprite1.draw(_window);

        if(_model->hasCollide())
            Collision.play();

        for(auto x : m_elemPos)
        {
            switch (x.first) {
            case 22:
                _coinSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
                _coinSprite.draw(_window);
                break;
            case 11:
                _elemSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
                _elemSprite.draw(_window);
                break;
            case 12:
                _elemSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
                _elemSprite.draw(_window);
                _elemSprite.setPosition(sf::Vector2f{x.second.first, x.second.second+50});
                _elemSprite.draw(_window);
                break;
            case 13:
                _elemSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
                _elemSprite.draw(_window);
                _elemSprite.setPosition(sf::Vector2f{x.second.first, x.second.second+50});
                _elemSprite.draw(_window);
                _elemSprite.setPosition(sf::Vector2f{x.second.first+50, x.second.second});
                _elemSprite.draw(_window);
                _elemSprite.setPosition(sf::Vector2f{x.second.first+50, x.second.second+50});
                _elemSprite.draw(_window);
                break;
            default:
                _coinSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
                _coinSprite.draw(_window);
                break;
            }
        }

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
            sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
            m_mainmenu.hoverMenu(mousePos);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                left=true;
            else
                left=false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                right=true;
            else
                right=false;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_menu) {
                m_mainmenu.MoveUp();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& m_menu) {
                m_mainmenu.MoveDown();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                if(m_menu) {
                    switch(m_mainmenu.getSelectedItem()) {
                    case 0:
                        m_menu = false;
                        break;
                    case 1:
                        //Traiter
                        break;
                    case 3:
                        _window->close();
                        break;
                    }
                }
            }

            // JUMP KEY
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                _model->jumpBall();
                Jump.play();
            }

            // SPLASH SCREEN SKEEPER //
            if (m_splashscreen.getSplashTime())
                m_splashscreen.event();
            // END OF SPLASH SCREEN SKEEPER //

            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();
                result = false;
            }
        }


    }
        _model->setCharDir(left,right);

    return result;
}

void View::synchronize()
{
    //m_splashscreen
    if(m_splashscreen.getSplashTime())
        m_splashscreen.synchronize();
    //End splashscreen

    _model->getElemsPos(m_elemPos);

    _SlidingBackgroundSprite1.setSpeed((float)-1*(_model->getAllSpeed()));
    _SlidingBackgroundSprite2.setSpeed((float)-1*_model->getAllSpeed()-1);

    //Ball's Position Updating
    std::pair<float,float> a = _model->getBallPosition();
    _balleSprite.setPosition(sf::Vector2f{a.first, a.second});


    //Move
    _model->moveBall();


}
