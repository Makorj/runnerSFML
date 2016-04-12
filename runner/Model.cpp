#include "Model.h"
#include "obstacle.h"
#include "movableelement.h"
#include "coin.h"
#include "heal.h"
#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

const float BALL_INIT_X = 10.;
const float BALL_INIT_Y = 450.;
const int BALL_INIT_H = 40;
const int BALL_INIT_W = 40;
const float BALL_INIT_DX = 0;
const float BALL_INIT_DY = 0;

int timeTest=0;
int timeTestBonus=0;

//!
//! \brief Constructor
//! \param w
//! \param h
//!
Model::Model(int w, int h)
    : _w(w),
      _h(h),
      m_allSpeed(2.),
      m_char((float)BALL_INIT_X,(float)BALL_INIT_Y,(int)BALL_INIT_H,(int)BALL_INIT_W,(float)BALL_INIT_DX,(float)BALL_INIT_DY),
      m_leftdir(false),
      m_rightdir(false),
      m_collide(false)
{
    m_timeElapsed.restart();
}

//!
//! \brief Destructor
//!
Model::~Model(){

    //Deleting all MovableElement still here
    for(auto x : m_elements)
        delete x;
}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep(){
    MovableElement* tmp;
    m_char.move(_w);
    m_char.jump();

    m_allSpeed=-2-(2.*m_timeElapsed.asSeconds()*0.01666666);
    cout << m_char.getLife() << endl;

    if(m_timeElapsed.asMilliseconds()-timeTest>7000)
    {
        m_elements.push_back(new Obstacle{(float)1300,435,50,50,-2,0,(1+(rand()%3))});
                timeTest=m_timeElapsed.asMilliseconds();
    }
    else if(m_timeElapsed.asMilliseconds()-timeTestBonus>2000)
    {
         m_elements.push_back(new Heal{1300.,310,50,50,-2,0,100});
//        switch(1)//+(rand()%3))
//        {
//        case 1:
//            m_elements.push_back(new Coin{1300.,310,50,50,-2,0});
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        default:
//            break;
//        }
         timeTestBonus=m_timeElapsed.asMilliseconds();
    }

    m_collide=false;

    for(auto elem=m_elements.begin();elem<m_elements.end();++elem)
    {
        tmp=*elem;

        if(tmp->outOfScreen())
        {
            m_elements.erase(elem);
            delete tmp;
            tmp=nullptr;
        }
        else if(collide(m_char, *tmp))
        {
            int x = tmp->getType();
            (x>=11 && x<20)?m_collide=true:false;
//                    (x==22)?m_blingbling=true:
//                    ;


            tmp->apply(&m_char);
            m_elements.erase(elem);
            delete tmp;
            tmp=nullptr;
        }
        else
        {
            tmp->setDX(m_allSpeed);
            tmp->move();
        }
    }
}

bool Model::hasCollide()
{
    return m_collide;
}

//!
//! \brief Get the ball's position
//! \return Position of the Ball in a sf::Vector2f
//!
std::pair<float,float> Model::getBallPosition()
{
    return std::make_pair(m_char.getX(),m_char.getY());
}

//!
//! \brief Get the ball dimensions inside the given parameters
//! \param h Height of the ball
//! \param w Width of the ball
//!
void Model::getBallDim(int&h, int &w)
{
    h=m_char.getH();
    w=m_char.getW();
}

//!
//! \brief Set the ball vertical speed
//! \param x Desired vertical speed
//!
void Model::setBallVerticalSpeed(float &x)
{
    m_char.setDY(x);
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

int Model::getAllSpeed() const{
    return m_allSpeed;
}

void Model::moveBall()
{
    float left = -3.;
    float right = 5.;
    float stop = 0.;
    if (m_leftdir)
        m_char.setDX(left);
    else if (m_rightdir)
        m_char.setDX(right);
    else
        m_char.setDX(stop);
}

//!
//! \brief Get all MovableElements' positions and type inside a vector
//!
//!  The vector contain pairs of the MovableElement's Type and Position
//!
//! \param elemPos std::vector used to store Elements positions passed by reference
//! \author TEAM Carambar de l'IUT
//!
void Model::getElemsPos( std::vector<std::pair<int , std::pair<float, float> > >& elemPos)
{

        elemPos.clear();
        for(auto x : m_elements)
        {
            elemPos.push_back(std::make_pair(x->getType(), std::make_pair(x->getX(), x->getY())));
        }
}


void Model::jumpBall()
{
    m_char.isJumping();
}

//!
//! \brief Get the player's money
//! \return Player's money
//!
unsigned int Model::getMoney()
{
    return m_money;
}

int Model::getScore()
{
    return m_char.getScore()+(m_timeElapsed.asMilliseconds()*5);
}
