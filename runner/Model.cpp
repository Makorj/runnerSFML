#include "Model.h"
#include <iostream>
#include <fstream>
using namespace std;

//=======================================
// Constructeurs
//=======================================
Model::Model(int w, int h)
  :  _w(w), _h(h),
    m_leftdir(false), m_rightdir(false)
{
    m_char=new Balle{10,450,300,300,0,0};
}

//=======================================
// Destructeurs
//=======================================
Model::~Model(){

    delete m_char;
}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep(){
    m_char->move();
    m_char->jump();
}

sf::Vector2f Model::getBallPosition()
{
    sf::Vector2f a{m_char->getX(),m_char->getY()};
    return a;
}

void Model::getBallDim(int&h, int &w)
{
    h=m_char->getH();
    w=m_char->getW();
}

void Model::setBallVerticalSpeed(float &x)
{
    m_char->setDY(x);
}

void Model::getCharDir(bool &left, bool &right)
{
    left=m_leftdir;
    right=m_rightdir;
}

void Model::setCharDir(bool &left, bool &right)
{
    m_leftdir=left;
    m_rightdir=right;
}

void Model::moveBall()
{
    float a = -5.;
    float b = 5.;
    float c = 0.;
    if (m_leftdir)
        m_char->setDX(a);
    else if (m_rightdir)
        m_char->setDX(b);
    else
        m_char->setDX(c);
}

void Model::jumpBall()
{
    m_char->isJumping();
}
