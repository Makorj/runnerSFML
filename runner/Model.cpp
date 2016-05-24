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
#include "Model.h"
#include "obstacle.h"
#include "movableelement.h"
#include "coin.h"
#include "heal.h"
#include "doublejump.h"
#include "invicibility.h"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
using namespace std;

string getData(string file);
void setNewData(string file, string& inData);


const string SAVE_FILE="pack1.rsvf";

const float BALL_INIT_X = 10.;
const float BALL_INIT_Y = 450.;
const int BALL_INIT_H = 125;
const int BALL_INIT_W = 80;
const float BALL_INIT_DX = 0.;
const float BALL_INIT_DY = 0.;

const float ELEM_X_INIT = 1210.;
const float OBS_Y_INIT = 525.;
const float BONUS_Y_INIT = 315.;

const float INIT_GLOBAL_SPEED = 2.;
const float GLOBAL_SPEED_MULTIPLIER = 0.01666666;

const int DEFAULT_MAXLIFE=100;
const int DEFAULT_HEAL_POWER=20;
const int DEFAULT_DOUBLE_JUMP_DURATION=5;
const int DEFAULT_INVICIBILITY_DURATION=5;

int timeTest=0;
int timeTestBonus=0;

//!
//! \brief Constructor
//! \param w Width of the game screen
//! \param h Height of the game screen
//!
Model::Model(int w, int h)
    : _w(w),
      _h(h),
      m_allSpeed(2.),
      m_leftdir(false),
      m_rightdir(false),
      m_collide(false)
{
    load();
	
    m_char = new Character((float)BALL_INIT_X,
                           (float)BALL_INIT_Y,
                           (int)BALL_INIT_W,
                           (int)BALL_INIT_H,
                           (float)BALL_INIT_DX,
                           (float)BALL_INIT_DY,
                           m_savedParam[SAVED_PARAM_ID_MAXLIFE]);
    m_timeElapsed.restart();
}

//!
//! \brief Destructor
//!
Model::~Model(){

    delete m_char;
    //Deleting all MovableElement still here
    for(auto x : m_elements)
        delete x;

    m_savedParam[SAVED_PARAM_MONEY]=m_char->getGold();
    save();
}

/*!
 * \brief Doing actions for the next step.
 * Unless m_paused is true, this stop the model from working/progressing.
*/
void Model::nextStep(){
	if(!m_paused)
	{
    MovableElement* tmp;
	//Move character
    m_char->move(_w);
    m_char->jump();

	//Update global speed
    m_allSpeed=-2-(1.5*m_timeElapsed.asSeconds()*GLOBAL_SPEED_MULTIPLIER);

	
	// Spawn bonus or obstacle
    if(m_timeElapsed.asMilliseconds()-timeTestBonus>2000)
    {

        switch(1+(rand()%4))
        {
        case 1:
            m_elements.push_back(new Coin{ELEM_X_INIT,BONUS_Y_INIT,50,50,-2,0});
            break;
        case 2:
            m_elements.push_back(new Heal{ELEM_X_INIT,BONUS_Y_INIT,50,50,-2,0,m_savedParam[SAVED_PARAM_ID_HEAL_POWER]});
            break;
        case 3:
            m_elements.push_back(new DoubleJump{ELEM_X_INIT,BONUS_Y_INIT,50,50,-2,0,m_savedParam[SAVED_PARAM_ID_DOUBLE_JUMP_DURATION]});
            break;
        case 4:
            m_elements.push_back(new Invicibility{ELEM_X_INIT,BONUS_Y_INIT,50,50,-2,0,m_savedParam[SAVED_PARAM_ID_INVICIBILITY_DURATION]});
        default:
            break;
        }
        timeTestBonus=m_timeElapsed.asMilliseconds();
        cerr << "ntm" << endl;
    }
    if(m_timeElapsed.asMilliseconds()-timeTest>5000)
    {
        m_elements.push_back(new Obstacle{ELEM_X_INIT,OBS_Y_INIT,50,50,-2,0,(1+(rand()%3))});
        timeTest=m_timeElapsed.asMilliseconds();
    }
    m_collide=false;

	// Tests on games elements
    for(auto elem=m_elements.begin();elem<m_elements.end();++elem)
    {
        tmp=*elem;
		
		//test if the element is to delete because it's out of the screen 
        if(tmp->outOfScreen())
        {
            cerr << "nts" << endl;
            m_elements.erase(elem);
            delete tmp;
            tmp=nullptr;
        }
		//test if it's collided with the ball
        else if(collide(m_char, tmp))
        {
            int x = tmp->getType();
			
			//If the collision is with an obstacle
            (x>=11 && x<20)?m_collide=true:false;
            //                    (x==22)?m_blingbling=true:
            //                    ;

			//Apply the effect of the collided effect on the character
            tmp->apply(m_char);
			
			//erase
            m_elements.erase(elem);
//            cerr << "ntf" << endl;
            delete tmp;
            tmp=nullptr;
        }
		//otherwise set his new speed and move it
        else
        {
            tmp->setDX(m_allSpeed);
            tmp->move();
        }
    }
	}
}

/*!
 * \brief Return if there is a collision in the game
 * \return boolean True if there is a collision, false otherwise
*/
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
    return std::make_pair(m_char->getX(),m_char->getY());
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

/*!
 * \brief Getter of the character direction
 * \param left INOUT Player moving left if true otherwise he is not
 * \param right INOUT Player moving right if true otherwise he is not
*/
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

int Model::getLife() const {
    return m_char->getLife();
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
    m_char->isJumping();
}

//!
//! \brief Get the player's money
//! \return Player's money
//!
unsigned int Model::getMoney()
{
    return m_char->getGold();
}

//!
//! \brief Get the player's score
//! \return Player's score
//!
int Model::getScore()
{
    return m_char->getScore()+(m_timeElapsed.asMilliseconds()*0.5);
}

void Model::restart() {
    delete m_char;
    for(auto elem=m_elements.begin();elem<m_elements.end();++elem)
    {
        MovableElement* tmp=*elem;
        delete tmp;
        tmp=nullptr;
    }
    m_elements.clear();

    m_timeElapsed.restart();
    timeTest=0;
    timeTestBonus=0;
    m_allSpeed=2.;
    m_char = new Character((float)BALL_INIT_X,
                           (float)BALL_INIT_Y,
                           (int)BALL_INIT_H,
                           (int)BALL_INIT_W,
                           (float)BALL_INIT_DX,
                           (float)BALL_INIT_DY,
						   m_savedParam[SAVED_PARAM_ID_MAXLIFE]);
}

bool Model::hasEnded() {
    return (m_char->getLife()>0)?false:true;
}

void Model::pause() {
    m_paused?m_paused=false:m_paused=true;
}

void Model::shopUpdate(std::array<int, 10>& newParam) {
    for(unsigned long i=0;i<newParam.size() && i<m_savedParam.size();i++)
    {
        m_savedParam[i]=newParam[i];
    }
}

void Model::load() {

    string dataString;
    dataString=getData(SAVE_FILE);

    if(dataString!="LOADING_FAILURE")
    {
        string tmp;
        unsigned long pos=dataString.find(';'),i=0, lastPos=0;
        while(pos!=string::npos && i<m_savedParam.size())
        {
            m_savedParam[i]=stoi(dataString.substr(lastPos,pos-lastPos));
            lastPos=pos+1;
            cout << m_savedParam[i] << endl;
            pos=dataString.find(';', lastPos);
            i++;
        }
    }
    else
    {
        cerr << "Ouverture impossible. Chargement des donnees par defaut en cours" << endl;
        m_savedParam[SAVED_PARAM_ID_MAXLIFE]=DEFAULT_MAXLIFE;
        m_savedParam[SAVED_PARAM_ID_HEAL_POWER]=DEFAULT_HEAL_POWER;
        m_savedParam[SAVED_PARAM_ID_DOUBLE_JUMP_DURATION]=DEFAULT_DOUBLE_JUMP_DURATION;
        m_savedParam[SAVED_PARAM_ID_INVICIBILITY_DURATION]=DEFAULT_INVICIBILITY_DURATION;
        m_savedParam[4]=0;
        m_savedParam[SAVED_PARAM_MONEY]=0;
        for(int i=6;i<10;i++)
            m_savedParam[i]=0;
    }

}

void Model::save(){

    string savedData;
    savedData+=to_string(m_savedParam[0]);
    for(int i=1; i<m_savedParam.size();i++)
        savedData+= ";"+
                to_string(m_savedParam[i]);

    setNewData(SAVE_FILE, savedData);
}


/*********************************************************************/
/*                         UTILITY FUNCTIONS                         */
/*********************************************************************/

const char KEY='d';		///< Fake Encryption key
const string LRU="POMME"; ///< Encryption key

/*!
 * \brief Read save file to get the game data
 * \param file A string containing the path to the file
 * \return A string containing the file's data
*/
string getData(string file){
    fstream f;
    string data, outData;
    f.open(file.c_str(),ios::in);
    if(f.is_open())
    {
        while(getline(f,data))
        {
            outData+=data;
        }
        f.close();

        outData=pomme(outData); //decrypting data
        return outData;
    }
    else
    {
        return "LOADING_FAILURE";
    }

}

/*!
 * \brief Write the game data in save file
 * \param file A string containing the path to the file
 * \param inData A string containing the data to insert in the save file
*/
void setNewData(string file, string& inData)
{
    fstream f;
    f.open(file.c_str(), ios::out);
    if(f.is_open())
    {
        f << pomme(inData); //crypting data
        f.close();
    }
    else
    {
        abort();
    }
}

/*!
 * \brief XOR Encrytpion/Decrytion Algorithm
 * \param Data Data string to encrypt/decrypt
 * \return An encrypted/decrypted string 
*/
string pomme(string Data)
{
    string outData;
    int i=0;
    for(auto x : Data)
    {
        outData+=x^(i+LRU[i%5])%256;
        i++;
    }
    return outData;
}
