#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

//!
//! \brief The GraphicElement class.
//! Herited from the sf::Sprite class from the SFML library.
//!
class GraphicElement
        : public sf::Sprite
{

protected:

    int m_w; ///< GraphicElement's width
    int m_h; ///< GraphicElement's height
    int m_x; ///< GraphicElement X coordinate
    int m_y; ///< GraphicElement Y coordinate

public:

    GraphicElement() = default;
    GraphicElement(sf::Texture &image, int x, int y, int w, int h, bool resiz = true);
    GraphicElement(const GraphicElement& copy);
    void draw(sf::RenderWindow* window) const;
    void resize(int w, int h);
    void setTransparency(int& transparencyLevel);
    int getH() const;
    int getW() const;
    int getX() const;
    int getY() const;
    void slideLeft(float s);
    void replace(int x, int y);

};

#endif // GraphicElement_H
