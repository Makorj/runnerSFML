#ifndef ELEMENTGRAPHIQUE_H
#define ELEMENTGRAPHIQUE_H

#include <SFML/Graphics.hpp>

class ElementGraphique : public sf::Sprite
{
private:
    int m_w;
    int m_h;
    int m_x;
    int m_y;
public:
    ElementGraphique() = default;
    ElementGraphique(sf::Texture &image, int x, int y, int w, int h);
    ElementGraphique(const ElementGraphique& b);
    void draw(sf::RenderWindow* fenetre) const;
    void resize(int w, int h);
    int getH() const;
    int getW() const;
};

#endif // ELEMENTGRAPHIQUE_H
