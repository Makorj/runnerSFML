/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
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
      m_mainmenu{w,h,MAIN_MENU_ITEMS},
      m_optionmenu{w,h,OPTIONS_MENU_ITEMS},
      m_langagemenu{w,h,LANGAGE_MENU_ITEMS},
      m_state{MAIN_MENU}
{

    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner", sf::Style::Close);
    _window->setFramerateLimit(60);
    _window->setKeyRepeatEnabled(false);

    // IMAGE LOADER //
    if(!_Background.loadFromFile(BACKGROUND_IMAGE))
        std::cerr << "ERROR when loading image file: " << BACKGROUND_IMAGE << std::endl;
    else {
        _Background.setSmooth(true);
        GraphicElement tmp1{_Background,0,0,_w,_h};
        _BackgroundSprite = tmp1;
    }
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

    std::vector<sf::IntRect> clipRect_balle;
    clipRect_balle.push_back(poposwag_run1_rect);
    clipRect_balle.push_back(poposwag_run2_rect);
    clipRect_balle.push_back(poposwag_run3_rect);

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
    _model->pause();
}

//=======================================
// Fonction de dessin
//=======================================
void View::draw(){
    _window->clear();

    if(m_state !=SPLASHSCREEN) {
        _BackgroundSprite.draw(_window);
        _SlidingBackgroundSprite2.draw(_window);
        _SlidingBackgroundSprite1.draw(_window);
    }

    switch(m_state) {
    case SPLASHSCREEN:
        m_splashscreen.draw(_window);
        break;
    case MAIN_MENU:
        m_mainmenu.draw(_window);
        break;
    case OPTIONS:
        m_optionmenu.draw(_window);
        break;
    case BEST_SCORES:
        break;
    case SHOP:
        break;
    case LANGAGE:
        m_langagemenu.draw(_window);
        break;
    case GAME:
        _balleSprite.draw(_window);
        drawObstacles();
        break;
    }
    _window->display();
}

void View::drawObstacles() {
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
            switch(m_state) {
            case SPLASHSCREEN:
                m_splashscreen.event(m_state);
                break;
            case MAIN_MENU:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_mainmenu.MoveUp();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_mainmenu.MoveDown();
                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::Return) {
                        switch(m_mainmenu.getSelectedItem()) {
                        case 0:
                            m_state = GAME;
                            _model->restart();
                            break;
                        case 1:
                            m_state = MULTIPLAYER;
                            break;
                        case 2:
                            m_state = BEST_SCORES;
                            break;
                        case 3:
                            m_state = SHOP;
                            break;
                        case 4:
                            m_state = OPTIONS;
                            break;
                        case 5:
                            break;
                            _window->close();
                            result = false;
                        }
                    }
                }
                break;
            case OPTIONS:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_optionmenu.MoveUp();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_optionmenu.MoveDown();
                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::Return) {
                        switch(m_optionmenu.getSelectedItem()) {
                        case 0:
                            m_state = LANGAGE;
                            break;
                        case 1:
                            break;
                        case 2:
                            m_state = MAIN_MENU;
                            break;
                        }
                    }
                }
                break;
            case BEST_SCORES:
                break;
            case SHOP:
                break;
            case LANGAGE:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_langagemenu.MoveUp();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_langagemenu.MoveDown();
                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::Return) {
                        switch(m_langagemenu.getSelectedItem()) {
                        case 0:
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            m_state = MAIN_MENU;
                            break;
                        case 6:
                            m_state = OPTIONS;
                            break;
                        }
                    }
                }
                break;
            case GAME:
                sf::Keyboard::isKeyPressed(sf::Keyboard::Left)?left=true:left=false;
                sf::Keyboard::isKeyPressed(sf::Keyboard::Right)?right=true:right=false;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    _model->jumpBall();
                    Jump.play();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::R)
                {
                    _model->restart();
                    m_elemPos.clear();
                }

                break;
            }

            if(_boobaSong.getStatus()==sf::SoundSource::Stopped && _boobaLoop.getStatus()!=sf::SoundSource::Playing)
                _boobaLoop.play();
            else if(_boobaSong.getStatus()!=sf::SoundSource::Playing && _boobaLoop.getStatus()!=sf::SoundSource::Playing)
                _boobaSong.play();

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
    if(m_state == GAME){
        _model->getElemsPos(m_elemPos);

        std::pair<float,float> a = _model->getBallPosition();
        _balleSprite.setPosition(sf::Vector2f{a.first, a.second});

        _SlidingBackgroundSprite1.setSpeed((float)-1*(_model->getAllSpeed()));
        _SlidingBackgroundSprite2.setSpeed((float)-1*_model->getAllSpeed()-1);

        if(_model->hasCollide())
            Collision.play();

        _model->moveBall();

    }
}
