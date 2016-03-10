#include "elementgraphique.h"

#include <SFML/Graphics.hpp>

ElementGraphique::ElementGraphique(sf::Texture &image, int x, int y, int w, int h)
    : m_w(w),
      m_h(h),
      m_x(x),
      m_y(y)
{
    setTexture(image);

}

ElementGraphique::ElementGraphique(const ElementGraphique& b)
    : ElementGraphique{b.getTexture(), b.getPosition().x, b.getPosition().y, b.getW(), b.getH()}
{}

void draw(sf::RenderWindow* fenetre) const
{

}

void ElementGraphique::resize(int w, int h)
{
    sf::FloatRect bb = getLocalBounds();      // retourne les positions et taille réelles de s
    float width_factor = w / bb.width;     // facteur de mise à l'échelle pour la largeur
    float height_factor = h / bb.height;  // facteur de mise à l'échelle pour la largeur
    setScale(width_factor, height_factor);
}

int ElementGraphique::getH() const
{
    return m_h;
}

int ElementGraphique::getW() const
{
    return m_w;
}
