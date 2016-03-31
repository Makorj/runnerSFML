#include "Model.h"
#include "obstacle.h"
#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

const float BALL_INIT_X = 10.;
const float BALL_INIT_Y = 450.;
const int BALL_INIT_H = 50;
const int BALL_INIT_W = 50;
const float BALL_INIT_DX = 0;
const float BALL_INIT_DY = 0;

//!
//! \brief Constructor
//! \param w
//! \param h
//!
Model::Model(int w, int h)
  :  _w(w), _h(h),
    m_leftdir(false), m_rightdir(false)
{
    m_char=new Balle{BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY};

    for(int i=0;i<5;i++)
        m_elements.push_back(new Obstacle{(float)700+(100*i),450,50,50,0,0,1});
}

//!
//! \brief Destructor
//!
Model::~Model(){

    //Deleting Balle
    delete m_char;

    //Deleting all MovableElement still here
    for(auto x : m_elements)
        delete x;
}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep(){
    m_char->move(_w);
    m_char->jump();

    for(auto elem : m_elements)
    {
        elem->setDX(-2.);
        elem->move();
    }
}

//!
//! \brief Get the ball's position
//! \return Position of the Ball in a sf::Vector2f
//!
sf::Vector2f Model::getBallPosition()
{
    sf::Vector2f a{m_char->getX(),m_char->getY()};
    return a;
}

//!
//! \brief Get the ball dimensions inside the given parameters
//! \param h Height of the ball
//! \param w Width of the ball
//!
void Model::getBallDim(int&h, int &w)
{
    h=m_char->getH();
    w=m_char->getW();
}

//!
//! \brief Set the ball vertical speed
//! \param x Desired vertical speed
//!
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
    float left = -3.;
    float right = 5.;
    float stop = 0.;
    if (m_leftdir)
        m_char->setDX(left);
    else if (m_rightdir)
        m_char->setDX(right);
    else
        m_char->setDX(stop);
}

//!
//! \brief Get all MovableElements' positions and type inside a vector
//!
//!  The vector contain pairs of the MovableElement's Type and Position
//!
//! \param elemPos std::vector used to store Elements positions passed by reference
//! \author TEAM Carambar de l'IUT
//!
void Model::getElemsPos( std::vector<std::pair<int ,sf::Vector2f> >& elemPos)
{

    unsigned int i=0;
    for(auto x : m_elements)
    {
        if(i<elemPos.size())
        {
            elemPos[i] = std::make_pair(x->getType(), sf::Vector2f{x->getX(), x->getY()});
            i++;
        }
        else
        {
            elemPos.push_back(std::make_pair(x->getType(), sf::Vector2f{x->getX(), x->getY()}));
        }
    }

    if(i<elemPos.size()-1)
        elemPos.resize(i);
}

void Model::jumpBall()
{
    m_char->isJumping();
}

//!
//! \brief Get the player's money
//! \return Player's money
//!
int Model::getMoney()
{
    return m_money;
}
