#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Balle

#include <boost/test/unit_test.hpp>

#include "balle.h"
#include "Model.h"

const float BALL_INIT_X = 10.;
const float BALL_INIT_Y = 450.;
const int BALL_INIT_H = 50;
const int BALL_INIT_W = 50;
const float BALL_INIT_DX = 0;
const float BALL_INIT_DY = 0;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

BOOST_AUTO_TEST_CASE(test_Balle)
{
    Balle test_ball {BALL_INIT_X,BALL_INIT_Y,BALL_INIT_H,BALL_INIT_W,BALL_INIT_DX,BALL_INIT_DY};
    test_ball.move(SCREEN_WIDTH);
    BOOST_CHECK(test_ball.getX() == 10 && test_ball.getY() == 450);
}

BOOST_AUTO_TEST_CASE(test_Model) {
    Model test_model {SCREEN_WIDTH, SCREEN_HEIGHT};
    int h;
    int w;
    test_model.getBallDim(h, w);
    BOOST_CHECK(h == 50);
    BOOST_CHECK(w == 50);

}
