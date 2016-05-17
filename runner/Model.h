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

#ifndef _MODEL_
#define _MODEL_

#include <SFML/Graphics.hpp>
#include "character.h"
#include "clock.h"

const int SAVED_PARAM_ID_MAXLIFE=0;
const int SAVED_PARAM_ID_HEAL_POWER=1;
const int SAVED_PARAM_ID_DOUBLE_JUMP_DURATION=2;
const int SAVED_PARAM_ID_INVICIBILITY_DURATION=3;

const int SAVED_PARAM_MONEY=5;

std::string pomme(std::string Data);
/*!
 * \brief Main class of the game containing all the data
 *	
*/

class Model {
 private:
  int 	_w,					///< Width of the game screen
		_h;					///< Height of the game screen
  float m_allSpeed;			///< Global speed of all the objects in the game except Character objects
  unsigned int m_money;		///< Money of the player in the game
  Character* m_char;		///< Player's Character
  bool 	m_leftdir,			///< True if the player is moving left
		m_rightdir,			///< True if the player is moving right
		m_paused,			///< Trus if the game is paused
		m_collide;			///< True if there is a collision between objects in the game 
  std::vector<MovableElement * > m_elements; 	///< Collection of all elements in the game except Character objects
  Clock m_timeElapsed;	///< Game's clock
  std::array<int, 10> m_savedParam;	///< Player's saved data, attributs, etc... 

 public:

  Model(int w, int h);
  ~Model();

  void restart();
  void shopUpdate(std::array<int, 10>& newParam);
  void pause();
  void load();
  void save();

  void moveBall();
  void jumpBall();

  bool hasCollide();
  bool hasEnded();

  void nextStep();

  std::pair<float, float> getBallPosition();
  void getElemsPos(std::vector<std::pair<int, std::pair<float, float> > > &elemPos);

  void getBallDim(int&h, int &w);
  void getCharDir(bool &left, bool &right);
  unsigned int getMoney();
  int getScore();
  int getAllSpeed() const;
  int getLife() const;

  void setBallVerticalSpeed(float &x);
  void setCharDir(bool& left, bool& right);


};
#endif
