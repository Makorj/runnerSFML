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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Balle

#include <boost/test/unit_test.hpp>

#include "Model.h"
#include "character.h"
#include "Model.h"
#include "doublejump.h"
#include "invicibility.h"
#include "time.h"
#include "obstacle.h"
#include "heal.h"


const float BALL_INIT_X = 10.;
const float BALL_INIT_Y = 450.;
const int BALL_INIT_H = 50;
const int BALL_INIT_W = 50;
const float BALL_INIT_DX = 0;
const float BALL_INIT_DY = 0;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
BOOST_AUTO_TEST_CASE(test_Balle)
{
    Character test_ball {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY};
    test_ball.move(SCREEN_WIDTH);
    BOOST_CHECK(test_ball.getX() == 10 && test_ball.getY() == 450);
}


BOOST_AUTO_TEST_CASE(test_Char)
{
    Character test_char {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY};
    test_char.move(800);
    BOOST_CHECK(test_char.getX() == 10 && test_char.getY() == 450);
}

BOOST_AUTO_TEST_CASE(test_Char_Jump)
{
    std::cout << "Test du saut en cours cela va prendre quelques secondes..." << std::endl;

    /*Character test_char {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY};
    float y_or=test_char.getY();
    test_char.isJumping();
    long long int timer=time(NULL);
    bool hasJumped=false;

    //On execute plus d'un saut complet (1 saut dure 1,388 secondes)
    while(time(NULL)-timer<2)
    {
        test_char.jump();
        test_char.move(SCREEN_WIDTH);
        if(y_or != test_char.getY())
            hasJumped=true;
    }
    BOOST_CHECK(hasJumped);
    BOOST_CHECK(y_or == test_char.getY() && y_or == BALL_INIT_Y);


    //TEST DOUBLE JUMP
    const int DOUBLE_JUMP_DURATION=5;
    DoubleJump test_DJ {10.,10.,10,10,0.,0.,DOUBLE_JUMP_DURATION};


    timer=time(NULL);
    test_DJ.apply(&test_char);
    y_or=test_char.getY();
    while(time(NULL)-timer<2)
    {
        test_char.isJumping();
        test_char.jump();
        test_char.move(SCREEN_WIDTH);
    }
    BOOST_CHECK(y_or != test_char.getY());
    while(time(NULL)-timer<5)
    {
        test_char.jump();
        test_char.move(SCREEN_WIDTH);
    }
    BOOST_CHECK(y_or == test_char.getY() && y_or == BALL_INIT_Y);*/


    std::cout << "Fin du test du saut" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_Char_heal)
{
    Character test_char2 {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY, 100};

    Heal health{10.,10.,10,10,-2.,0.,50};

    test_char2.subLife(80);
    BOOST_CHECK(test_char2.getLife() == 20);
    health.apply(&test_char2);
    BOOST_CHECK(test_char2.getLife() == 70);
}

BOOST_AUTO_TEST_CASE(test_Char_damage)
{
    Character test_char3 {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY, 100};

    Obstacle small{30.,450.,50,50,-2.,0.,1};
    small.apply(&test_char3);
    BOOST_CHECK(test_char3.getLife() != test_char3.getMaxLife());
    BOOST_CHECK(test_char3.getLife() == (test_char3.getMaxLife()-small.getDamage()));
    test_char3.addLife(100);
    BOOST_CHECK(test_char3.getLife()== test_char3.getMaxLife());

    Obstacle medium{30.,450.,50,50,-2.,0.,2};
    medium.apply(&test_char3);
    BOOST_CHECK(test_char3.getLife() != test_char3.getMaxLife());
    BOOST_CHECK(test_char3.getLife() == (test_char3.getMaxLife()-medium.getDamage()));
    test_char3.addLife(100);
    BOOST_CHECK(test_char3.getLife() == test_char3.getMaxLife());

    Obstacle big{30.,450.,50,50,-2.,0.,3};
    big.apply(&test_char3);
    BOOST_CHECK(test_char3.getLife() != test_char3.getMaxLife());
    BOOST_CHECK(test_char3.getLife() == (test_char3.getMaxLife()-big.getDamage()));
    test_char3.addLife(100);
    BOOST_CHECK(test_char3.getLife() == test_char3.getMaxLife());

}

BOOST_AUTO_TEST_CASE(collisions_MovableElement)
{
    MovableElement Element1 {20.,20.,50,50,0.,0.};
    MovableElement Element2 {25.,25,50,50,0.,0.};
    MovableElement Element3 {150.,150.,50,50,0.,0.};
    BOOST_CHECK(true == collide(Element1, Element2));
    BOOST_CHECK(true == collide(Element2, Element1));
    BOOST_CHECK(false == collide(Element1, Element3));
}


BOOST_AUTO_TEST_CASE(test_Model) {
    Model test_model {SCREEN_WIDTH, SCREEN_HEIGHT};
    int h;
    int w;
    test_model.getBallDim(h, w);
    BOOST_CHECK(h == 40);
    BOOST_CHECK(w == 40);
}

BOOST_AUTO_TEST_CASE(test_Model_Pause) {
    bool left = false;
    bool right = true;
    Model test_model_pause {SCREEN_WIDTH, SCREEN_HEIGHT};
    float x_or=test_model_pause.getBallPosition().first;
    BOOST_CHECK(x_or == 10.);
    test_model_pause.setCharDir(left,right);
    test_model_pause.moveBall();
    for(int i=0;i<5;i++)
        test_model_pause.nextStep();
    BOOST_CHECK(x_or != test_model_pause.getBallPosition().first);
    test_model_pause.pause();
    x_or=test_model_pause.getBallPosition().first;
    for(int i=0;i<5;i++)
        test_model_pause.nextStep();
    BOOST_CHECK(x_or == test_model_pause.getBallPosition().first);
    test_model_pause.pause();
    for(int i=0;i<5;i++)
        test_model_pause.nextStep();
    BOOST_CHECK(x_or != test_model_pause.getBallPosition().first);
}

BOOST_AUTO_TEST_CASE(test_model_restart_Restart) {
    bool left = false;
    bool right = true;
    Model test_model_restart {SCREEN_WIDTH, SCREEN_HEIGHT};
    float x_or=test_model_restart.getBallPosition().first;
    BOOST_CHECK(x_or == BALL_INIT_X);
    test_model_restart.setCharDir(left,right);
    test_model_restart.moveBall();
    for(int i=0;i<100;i++)
        test_model_restart.nextStep();
    BOOST_CHECK(x_or != test_model_restart.getBallPosition().first);
    test_model_restart.restart();
    test_model_restart.pause();
    BOOST_CHECK(test_model_restart.getBallPosition().first == x_or && x_or == BALL_INIT_X);
}

BOOST_AUTO_TEST_CASE(test_Encryption)
{
    std::string TestString = "Roses are red, Violets are blue";
    std::string ProofString = TestString;
    std::string EncryptedString = crypting(TestString);
    BOOST_CHECK(EncryptedString!=ProofString);
    BOOST_CHECK(TestString == ProofString);
}

BOOST_AUTO_TEST_CASE(test_Decryption)
{
    std::string TestString = "Roses are red, Violets are blue";
    std::string ProofString = TestString;
    std::string EncryptedString = crypting(TestString);
    BOOST_CHECK(EncryptedString!=ProofString);
    std::string DecryptedString = crypting(EncryptedString);
    BOOST_CHECK(DecryptedString == ProofString);
}

BOOST_AUTO_TEST_CASE(test_bonuses) {
    DoubleJump test_jump{10.,10.,10,10,-2.,0.,50};
    Invicibility test_inv{10.,10.,10,10,-2.,0.,50};
    Character test_char4 {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY, 100};

    test_jump.apply(&test_char4);
}
