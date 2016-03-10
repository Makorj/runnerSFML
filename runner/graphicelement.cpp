#include "graphicelement.h"

#include <SFML/Graphics.hpp>

GraphicElement::GraphicElement(sf::Texture &image, int x, int y, int w, int h)
    : m_w(w),
      m_h(h)
{
    setTexture(image);
    setPosition(*new sf::Vector2f(x,y));

}

GraphicElement::GraphicElement(const GraphicElement& b)
{
    setTexture(*b.getTexture());
    m_w=b.getW();
    m_h=b.getH();
    setPosition(b.getPosition());
}

void GraphicElement::draw(sf::RenderWindow* window) const
{
    window->draw(*this);
}

void GraphicElement::resize(int w, int h)
{
    sf::FloatRect bb = getLocalBounds();      // retourne les positions et taille réelles de s
    float width_factor = w / bb.width;     // facteur de mise à l'échelle pour la largeur
    float height_factor = h / bb.height;  // facteur de mise à l'échelle pour la largeur
    setScale(width_factor, height_factor);
}

int GraphicElement::getH() const
{
    return m_h;
}

int GraphicElement::getW() const
{
    return m_w;
}
