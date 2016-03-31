#ifndef _MODEL_
#define _MODEL_

#include <SFML/Graphics.hpp>
#include "balle.h"

class Model {
 private:
  int _w, _h;
  int m_money;
  Balle* m_char;
  bool m_leftdir, m_rightdir;
  std::vector<MovableElement * > m_elements;

 public:

  Model(int w, int h);
  ~Model();

  void moveBall();
  void jumpBall();

  void nextStep();

  sf::Vector2f getBallPosition();
  void getElemsPos(std::vector<std::pair<int, sf::Vector2f> > &elemPos);

  void getBallDim(int&h, int &w);
  void getCharDir(bool &left, bool &right);
  int getMoney();

  void setBallVerticalSpeed(float &x);
  void setCharDir(bool& left, bool& right);

};
#endif
