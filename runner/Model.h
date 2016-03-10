#ifndef _MODEL_
#define _MODEL_

#include <SFML/Graphics.hpp>
#include "balle.h"

class Model {
 private:
  int _w, _h;
  Balle* m_char;
  bool m_leftdir, m_rightdir;

 public:

  Model(int w, int h);
  ~Model();

  sf::Vector2f getBallPosition();
  void getBallDim(int&h, int &w);
  void moveBall();
  void getCharDir(bool &left, bool &right);
  void setCharDir(bool& left, bool& right);
  void nextStep();
};
#endif
