#include "View.h"
#include "Model.h"


#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
using namespace std;
//using namespace sf;

//=======================================
// Constructeur
//=======================================
View::View(int w, int h): _w(w), _h(h){
    _window = new sf::RenderWindow(sf::VideoMode(w, h, 32), "Runner", sf::Style::Close);

    if (!_background.loadFromFile(BACKGROUND_IMAGE))
        std::cerr << "ERROR when loading image file: " << BACKGROUND_IMAGE << std::endl;
    else {
        _backgroundSprite.setTexture(_background);
        _backgroundSprite.setPosition(sf::Vector2f(0.f,0.f));
    }

    if (!_balle.loadFromFile(BALLE_IMAGE))
        std::cerr << "ERROR when loading image file: " << BALLE_IMAGE << std::endl;
    else {
        ElementGraphique tmp{_balle, 1,1,1,1};
        _balleSprite = tmp;

    }
}

//=======================================
// Destructeur
//=======================================
View::~View(){
    if(_window!= NULL)
        delete _window;
}

//=======================================
// Accesseurs en écriture
//=======================================
void View::setModel(Model * model){
    _model = model;
}

//=======================================
// Fonction de dessin
//=======================================
void View::draw(){
    _window->clear();

    _window->draw(_backgroundSprite);


    int x,y;
    _model->getBallPosition(x,y);
//    _model->getBallDim(height, width);
//    sf::FloatRect bb = _balleSprite.getLocalBounds();      // retourne les positions et taille réelles de s
//    float width_factor = width / bb.width;     // facteur de mise à l'échelle pour la largeur
//    float height_factor = height / bb.height;  // facteur de mise à l'échelle pour la largeur
//    _balleSprite.setScale(width_factor, height_factor);
    _balleSprite.setPosition(sf::Vector2f(x,y));
    _window->draw(_balleSprite);

    _window->display();
}

//=======================================
// Traitement des evenements
//=======================================
bool View::treatEvents(){
    bool result = false;
    if(_window->isOpen()){
        result = true;

        sf::Event event;
        while (_window->pollEvent(event)) {
            cout << "Event detected" << endl;
            if (event.key.code == sf::Keyboard::Left)
                _model->moveBall(true);
            if (event.key.code == sf::Keyboard::Right)
                _model->moveBall(false);
            if ((event.type == sf::Event::Closed) ||
                    ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
                _window->close();
                result = false;
            }
        }
    }
    return result;
}

