#ifndef _VIEW_
#define _VIEW_

#include <SFML/Graphics.hpp>
#include "elementgraphique.h"

const std::string BACKGROUND_IMAGE = "Images/city.png";
const std::string BALLE_IMAGE = "Images/ball.png";

class Model;

class View {
private:
    int _w, _h;

    sf::RenderWindow * _window;
    Model * _model;

    sf::Texture _background;
    sf::Sprite _backgroundSprite;

    sf::Texture _balle;
    ElementGraphique _balleSprite;

public:
    View(int w, int h);
    ~View();

    void setModel(Model * model);
    void draw();
    bool treatEvents();

};
#endif

