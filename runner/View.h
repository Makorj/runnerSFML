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
#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <utility>
#include "graphicelement.h"
#include "animatedgraphicelement.h"
#include "slidingbackground.h"
#include "menu.h"
#include "splashscreen.h"
#include "State.h"


const std::string BALLE_IMAGE = "../Images/iceclimber.png";
const std::string SLIDING_BACKGROUND_IMAGE1 = "../Images/sapin_background.png";
const std::string SLIDING_BACKGROUND_IMAGE2 = "../Images/moutain_background.png";
const std::string BACKGROUND_IMAGE = "../Images/sun.png";

const std::string SONG_BOOBA= "../Audio/sonBooba.ogg";
const std::string SONG_BOOBA_LOOP= "../Audio/sonBoobaLoop.ogg";

const std::string SOUND_IZI="../Audio/izi.ogg";
const std::string SOUND_CARRE="../Audio/carre.ogg";

const std::string ELEM_IMG = "../Images/iceblock.png";
const std::string COIN_IMG = "../Images/flocon.png";

const std::vector<std::string> MAIN_MENU_ITEMS = {"Play","Multiplayer","Best Scores","Shop","Options","Quit"};
const std::vector<std::string> OPTIONS_MENU_ITEMS = {"Language","Volume","Back"};
const std::vector<std::string> LANGUAGE_MENU_ITEMS = {"English","French","German","Spanish","Portugese","Main Menu","Back"};

const sf::IntRect poposwag_run1_rect{0,0,100,134};
const sf::IntRect poposwag_run2_rect{134,0,100,134};
const sf::IntRect poposwag_run3_rect{269,0,100,134};

class Model;

class View {

private:

    int _w, _h, m_transparent;
    bool m_reverse, m_splashtime, m_logo1, m_menu;

    sf::Clock time;

    sf::RenderWindow * _window;
    Model * _model;

    sf::Texture _splashImg1;
    GraphicElement _splashImgSprite1;

    sf::Texture _splashImg2;
    GraphicElement _splashImgSprite2;

    sf::Texture _balle;
    AnimatedGraphicElement _balleSprite;

    sf::Texture _coin;
    GraphicElement _coinSprite;

    sf::Texture _elem;
    GraphicElement _elemSprite;

    sf::Texture _Background;
    GraphicElement _BackgroundSprite;

    sf::Texture _SlidingBackground1;
    SlidingBackground _SlidingBackgroundSprite1;

    sf::Texture _SlidingBackground2;
    SlidingBackground _SlidingBackgroundSprite2;

    sf::SoundBuffer izi;
    sf::Sound Jump;

    sf::SoundBuffer carre;
    sf::Sound Collision;

    sf::Music _boobaSong;
    sf::Music _boobaLoop;

    std::vector<std::pair<int , std::pair<float, float> > > m_elemPos;

    sf::Vector2f m_mouse;
    SplashScreen m_splashscreen;

    State m_state;
    Menu m_mainmenu;
    Menu m_optionmenu;
    Menu m_languagemenu;

public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    void drawObstacles();
    void changeLanguage(std::string lang);
    void synchronize();
    bool treatEvents();

};
#endif
