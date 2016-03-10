#ifndef _MODEL_
#define _MODEL_

#include "balle.h"

class Model {
 private:
  int _w, _h;
  Balle* mr_rubi;

 public:

  Model(int w, int h);
  ~Model();

  void getBallPosition(int&x, int&y);
  void getBallDim(int&h, int &w);
  void moveBall(bool left, bool right);
  void nextStep();
};
#endif
