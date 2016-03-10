#include "Model.h"
#include <iostream>
#include <fstream>
using namespace std;

//=======================================
// Constructeurs
//=======================================
Model::Model(int w, int h)
  :  _w(w), _h(h) {
    mr_rubi=new Balle{10,450,300,300,0,0};
}

//=======================================
// Destructeurs
//=======================================
Model::~Model(){

    delete mr_rubi;
}

//=======================================
// Calcul la prochaine étape
//=======================================
void Model::nextStep(){
    mr_rubi->move();
}

void Model::getBallPosition(int&x, int&y)
{
    x=mr_rubi->getX();
    y=mr_rubi->getY();
}

void Model::getBallDim(int&h, int &w)
{
    h=mr_rubi->getH();
    w=mr_rubi->getW();
}


void Model::moveBall(bool left, bool right)
{
    int a = -5;
    int b = 5;
    int c = 0;
    if (left)
        mr_rubi->setDX(a);
    else if (right)
        mr_rubi->setDX(b);
    else
        mr_rubi->setDX(c);
}
