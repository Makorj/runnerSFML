#ifndef _MODEL_
#define _MODEL_

#include <SFML/Graphics.hpp>
#include "balle.h"
#include "clock.h"

class Model {
 private:
  int _w, _h;
  float m_allSpeed;
  unsigned int m_money;
  Character m_char;
  bool m_leftdir, m_rightdir, m_collide;
  std::vector<MovableElement * > m_elements;
  Clock m_timeElapsed;

 public:

  Model(int w, int h);
  ~Model();

  void restart();
  void afterShopUpdate();
  void pause();

  void moveBall();
  void jumpBall();

  bool hasCollide();

  void nextStep();

  std::pair<float, float> getBallPosition();
  void getElemsPos(std::vector<std::pair<int, std::pair<float, float> > > &elemPos);

  void getBallDim(int&h, int &w);
  void getCharDir(bool &left, bool &right);
  unsigned int getMoney();
  int getScore();
  int getAllSpeed() const;

  void setBallVerticalSpeed(float &x);
  void setCharDir(bool& left, bool& right);

};
#endif
