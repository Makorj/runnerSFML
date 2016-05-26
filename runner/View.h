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
#include "life.h"
#include "shop.h"
#include <thread>
#include "menumultiplayer.h"

using path = const std::string;

path BALLE_IMAGE = "../Images/iceclimber.png";
path SLIDING_BACKGROUND_IMAGE1 = "../Images/sapin_background.png";
path SLIDING_BACKGROUND_IMAGE2 = "../Images/moutain_background.png";
path BACKGROUND_IMAGE = "../Images/sun.png";
path GUI_IMAGE = "../Images/lifeSlider.png";
path HEAL_BONUS_IMAGE = "../Images/cube_heal.png";
path JUMP_BONUS_IMAGE = "../Images/cube_jump.png";
path INV_BONUS_IMAGE = "../Images/cube_inv.png";
path MULTIPLIER_BONUS_IMAGE = "../Images/cube_x2.png";
path SPINNING_COIN = "../Images/spinning_coin.png";
path COIN_STACK = "../Images/pile_coin.png";
path GAME_OVER_IMAGE = "../Images/gameover.png";
path MAXLIFE_IMAGE ="../Images/maxLife.png";

path SONG_GAME= "../Audio/Bonetrousle.ogg";
path SONG_MENUS= "../Audio/OneTrueLove.ogg";

path SOUND_IZI="../Audio/jump_sound.wav";
path SOUND_CARRE="../Audio/crash_sound.wav";

path ELEM_IMG = "../Images/iceblock.png";
path COIN_IMG = "../Images/flocon.png";

const std::vector<std::string> MAIN_MENU_ITEMS = {"Play","Multiplayer","Best Scores","Shop","Options","Quit"};
const std::vector<std::string> OPTIONS_MENU_ITEMS = {"Language","Volume","Back"};
const std::vector<std::string> LANGUAGE_MENU_ITEMS = {"English","French","German","Spanish","Portugese","Main Menu","Back"};
const std::vector<std::string> SHOP_MENU_ITEMS = {"Buy","Buy", "Buy", "Buy", "Buy", "Back"};
const std::vector<std::string> SHOP_ITEMS = {"Heal","Jump","Invincibility","Multiplier"};
const std::vector<std::string> GAMEOVER_ITEMS = {"Restart","Main Menu","Quit"};
const std::vector<std::string> MULTIPLAYER_ITEMS = {"Create a Game", "Join a Game", "Spectate", "Back"};
const std::vector<std::string> HOSTSELEC_ITEMS = {"Join","Refresh","Back"};

const sf::IntRect poposwag_run1_rect{0,0,100,134};
const sf::IntRect poposwag_run2_rect{134,0,100,134};
const sf::IntRect poposwag_run3_rect{269,0,100,134};

const sf::IntRect bonusRect1{0,0,47,54};
const sf::IntRect bonusRect2{59,0,55,54};
const sf::IntRect bonusRect3{128,0,57,54};
const sf::IntRect bonusRect4{207,0,50,54};
const sf::IntRect bonusRect5{273,0,58,54};
const sf::IntRect bonusRect6{345,0,55,54};


class Model;

class View {

private:

    int _w, _h;

    sf::Clock time;

    sf::RenderWindow * _window;
    Model * _model;

    sf::Texture _splashImg1;
    GraphicElement _splashImgSprite1;

    sf::Texture _splashImg2;
    GraphicElement _splashImgSprite2;

    sf::Texture _balle;
    AnimatedGraphicElement _balleSprite;

    sf::Texture _elem;
    GraphicElement _elemSprite;

    sf::Texture _Background;
    GraphicElement _BackgroundSprite;

    sf::Texture _SlidingBackground1;
    SlidingBackground _SlidingBackgroundSprite1;

    sf::Texture _SlidingBackground2;
    SlidingBackground _SlidingBackgroundSprite2;

    sf::Texture _HealBonus;
    AnimatedGraphicElement _HealBonusSprite;

    sf::Texture _InvBonus;
    AnimatedGraphicElement _InvBonusSprite;

    sf::Texture _JumpBonus;
    AnimatedGraphicElement _JumpBonusSprite;

    sf::Texture _2xBonus;
    AnimatedGraphicElement _2xBonusSprite;

    sf::Texture _coin;
    AnimatedGraphicElement _coinSprite;

    sf::Texture _coinStack;
    GraphicElement _coinStackSprite;

    sf::Texture _maxLife;
    AnimatedGraphicElement _maxLifeSprite;

    sf::Texture _gameOver;
    GraphicElement _gameOverSprite;

    sf::Font _fontDisplay;
    sf::Text _coinDisplayText;
    sf::Text _scoreDisplayText;

    sf::Texture _GUI;

    sf::SoundBuffer izi;
    sf::Sound Jump;

    sf::SoundBuffer carre;
    sf::Sound Collision;

    sf::Music _GameMusic;
    sf::Music _MenusMusic;

    std::vector<std::pair<int , std::pair<float, float> > > m_elemPos;

    sf::Vector2f m_mouse;
    SplashScreen m_splashscreen;
    Life m_lifeUI;

    State m_state;
    Menu m_mainmenu;
    Menu m_optionmenu;
    Menu m_languagemenu;
    Shop m_shopmenu;
    Menu m_gameovermenu;
    Menu m_multiplayermenu;
    MenuMultiPlayer m_hostselecmenu;

    Client* m_client;
    std::thread m_thread;

    void loadBackgrounds();
    std::vector<AnimatedGraphicElement> loadBonuses();

public:

    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    void drawObstacles();
    void changeLanguage(std::string lang);
    void synchronize();
    bool treatEvents();
    void setClient(Client* c);

};
#endif
