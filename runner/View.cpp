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
#include <fstream>

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
      m_languagemenu{w,h,LANGUAGE_MENU_ITEMS},
      m_shopmenu{w,h,SHOP_MENU_ITEMS},
      m_state{MAIN_MENU}
{

    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner", sf::Style::Close);
    _window->setFramerateLimit(60);
    _window->setKeyRepeatEnabled(false);

    changeLanguage("en");
    // IMAGE LOADER //
    if(_Background.loadFromFile(BACKGROUND_IMAGE)){
        _Background.setSmooth(true);
        GraphicElement tmp1{_Background,0,0,_w,_h};
        _BackgroundSprite = tmp1;
    }

    if (_SlidingBackground1.loadFromFile(SLIDING_BACKGROUND_IMAGE1)) {
        _SlidingBackground1.setSmooth(true);
        SlidingBackground tmp{_SlidingBackground1,_w,_h,SPEED};
        _SlidingBackgroundSprite1 = tmp;
    }

    if (_SlidingBackground2.loadFromFile(SLIDING_BACKGROUND_IMAGE2)){
        _SlidingBackground2.setSmooth(true);
        SlidingBackground tmp{_SlidingBackground2,_w,_h,SPEED1};
        _SlidingBackgroundSprite2 = tmp;
    }

    if (_elem.loadFromFile(ELEM_IMG)) {
        GraphicElement tmp{_elem, 0,0,50,50};
        _elemSprite = tmp;
    }

    if(_GUI.loadFromFile(GUI_IMAGE)) {
        Life tmp{_GUI,sf::Color::Green, sf::Color::Red, 100.0f};
        m_lifeUI = tmp;
    }

    vector<sf::IntRect> readBonus;
    readBonus.push_back(bonusRect1);
    readBonus.push_back(bonusRect2);
    readBonus.push_back(bonusRect3);
    readBonus.push_back(bonusRect4);
    readBonus.push_back(bonusRect5);
    readBonus.push_back(bonusRect6);


    if(_HealBonus.loadFromFile(HEAL_BONUS_IMAGE)) {
        AnimatedGraphicElement tmp{readBonus, _HealBonus,0,0,50,50};
        _HealBonusSprite = tmp;
    }


    if(_JumpBonus.loadFromFile(JUMP_BONUS_IMAGE)) {
        AnimatedGraphicElement tmp{readBonus, _JumpBonus, 0,0,50,50};
        _JumpBonusSprite = tmp;
    }


    if(_InvBonus.loadFromFile(INV_BONUS_IMAGE)) {
        AnimatedGraphicElement tmp{readBonus, _InvBonus, 0,0,50,50};
        _InvBonusSprite = tmp;
    }


    if(_2xBonus.loadFromFile(MULTIPLIER_BONUS_IMAGE)) {
        AnimatedGraphicElement tmp{readBonus, _2xBonus, 0,0,50,50};
        _2xBonusSprite = tmp;
    }

    if (_coin.loadFromFile(SPINNING_COIN)){
        AnimatedGraphicElement tmp{readBonus, _coin, 0,0,50,50};
        _coinSprite = tmp;
    }

    if(_coinStack.loadFromFile(COIN_STACK)) {
        GraphicElement tmp{_coinStack, 0,0,50,50};
        _coinStackSprite = tmp;
    }
    if(_coinDisplay.loadFromFile("../Font/givre.TTF")) {
        _coinDisplayText.setFont(_coinDisplay);
        _coinDisplayText.setCharacterSize(30);
        _coinDisplayText.setPosition(_coinStackSprite.getGlobalBounds().width + 10, 5);
    }

    vector<AnimatedGraphicElement> Bonuses;
    Bonuses.push_back(_HealBonusSprite);
    Bonuses.push_back(_JumpBonusSprite);
    Bonuses.push_back(_InvBonusSprite);
    Bonuses.push_back(_2xBonusSprite);
    m_shopmenu.setBonuses(Bonuses);

    if (_boobaSong.openFromFile(SONG_BOOBA)) {
        _boobaSong.setLoop(false);
        _boobaSong.setVolume(30.);
    }

    if (_boobaLoop.openFromFile(SONG_BOOBA)) {
        _boobaLoop.setLoop(true);
        _boobaLoop.setVolume(30.);
    }

    if (izi.loadFromFile(SOUND_IZI))
        Jump.setBuffer(izi);

    if (carre.loadFromFile(SOUND_CARRE))
        Collision.setBuffer(carre);

    std::vector<sf::IntRect> clipRect_balle;
    clipRect_balle.push_back(poposwag_run1_rect);
    clipRect_balle.push_back(poposwag_run2_rect);
    clipRect_balle.push_back(poposwag_run3_rect);

    if (_balle.loadFromFile(BALLE_IMAGE)) {
        _balle.setSmooth(true);
        AnimatedGraphicElement tmp{clipRect_balle, _balle, 1,1,40,40};
        _balleSprite = tmp;
    }
}
// END OF IMAGE LOADER //


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
    //_model->pause();
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
    case MULTIPLAYER:
        break;
    case OPTIONS:
        m_optionmenu.draw(_window);
        break;
    case BEST_SCORES:
        break;
    case SHOP:
        m_shopmenu.draw(_window);
        _coinStackSprite.draw(_window);
        _window->draw(_coinDisplayText);
        break;
    case LANGUAGE:
        m_languagemenu.draw(_window);
        break;
    case GAME:
        _balleSprite.draw(_window);
        m_lifeUI.draw(_window);
        _coinStackSprite.draw(_window);
        _window->draw(_coinDisplayText);

        drawObstacles();
        break;
    case GAMEOVER:
        break;
    }
    _window->display();
}

void View::drawObstacles() {
    for(auto x : m_elemPos)
    {
        cout << x.first << endl;
        switch (x.first) {
        case 21:
            _HealBonusSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
            _HealBonusSprite.draw(_window);
            break;
        case 22:
            _coinSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
            _coinSprite.draw(_window);
            break;
        case 23:
            _InvBonusSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
            _InvBonusSprite.draw(_window);
            break;
        case 24:
            _JumpBonusSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
            _JumpBonusSprite.draw(_window);
            break;
        case 25:
            _2xBonusSprite.setPosition(sf::Vector2f{x.second.first, x.second.second});
            _2xBonusSprite.draw(_window);
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
                            result = false;
                            _window->close();
                            break;
                        }
                    }
                }
                break;
            case MULTIPLAYER:
                break;
            case OPTIONS:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_optionmenu.MoveUp();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_optionmenu.MoveDown();
                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::Return) {
                        switch(m_optionmenu.getSelectedItem()) {
                        case 0:
                            m_state = LANGUAGE;
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
            case LANGUAGE:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_languagemenu.MoveUp();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_languagemenu.MoveDown();
                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::Return) {
                        switch(m_languagemenu.getSelectedItem()) {
                        case 0:
                            changeLanguage("en");
                            m_state = OPTIONS;
                            break;
                        case 1:
                            changeLanguage("fr");
                            m_state = OPTIONS;
                            break;
                        case 2:
                            changeLanguage("gr");
                            m_state = OPTIONS;
                            break;
                        case 3:
                            changeLanguage("es");
                            m_state = OPTIONS;
                            break;
                        case 4:
                            changeLanguage("po");
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
            case GAMEOVER:
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

void View::changeLanguage(string lang) {
    fstream f;
    int cpt = 0;
    int cpt2 = -1;
    string test;
    f.open("../Languages/" + lang + ".ini", ios::in);
    if(f.is_open()) {
        while(!f.eof()) {
            getline(f, test);
            cpt2++;
            if(test != "___") {
                switch(cpt) {
                case 0:
                    m_mainmenu.changeString(test,cpt2);
                    break;
                case 1:
                    m_optionmenu.changeString(test,cpt2);
                    break;
                case 2:
                    m_languagemenu.changeString(test,cpt2);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                }
            }
            else {
                cpt++;
                cpt2=-1;
            }


        }
    }
}

void View::synchronize()
{
    if(m_state == GAME){
        _model->getElemsPos(m_elemPos);

        std::pair<float,float> a = _model->getBallPosition();
        _balleSprite.setPosition(sf::Vector2f{a.first, a.second});
        m_lifeUI.synchronize(_model->getLife(),a.first, a.second);
        cout << _model->getLife() << endl;

        _SlidingBackgroundSprite1.setSpeed((float)-1*(_model->getAllSpeed()));
        _SlidingBackgroundSprite2.setSpeed((float)-1*_model->getAllSpeed()-1);

        if(_model->hasCollide())
            Collision.play();

        _model->moveBall();
        _coinDisplayText.setString(std::to_string(_model->getMoney()));

    }
}
