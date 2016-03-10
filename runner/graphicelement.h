#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

class GraphicElement : public sf::Sprite
{
private:
    int m_w;
    int m_h;
    int m_x;
    int m_y;
public:
    GraphicElement() = default;
    GraphicElement(sf::Texture &image, int x, int y, int w, int h);
    GraphicElement(const GraphicElement& b);
    void draw(sf::RenderWindow* window) const;
    void resize(int w, int h);
    int getH() const;
    int getW() const;
};

#endif // GraphicElement_H
