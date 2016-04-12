#include "graphicelement.h"

#include <SFML/Graphics.hpp>


//!
//! \brief Default Constructor
//! \param image Texture used by the GraphicalElement
//! \param x X coordinate of the GraphicalElement
//! \param y Y coordinate of the GraphicalElement
//! \param w Width of the GraphicalElement
//! \param h Height of the GraphicalElement
//!
GraphicElement::GraphicElement(sf::Texture &image, int x, int y, int w, int h, bool resiz)
    :
      Sprite(image),
      m_w(w),
      m_h(h),
      m_x(x),
      m_y(y)
{
    if(resiz)
        resize(m_w,m_h);
    setPosition(sf::Vector2f(m_x,m_y));

}

//!
//! \brief Copy Constructor
//! \param copy Instance to copy
//!
GraphicElement::GraphicElement(const GraphicElement& copy)
    : Sprite(*copy.getTexture()),
    m_w(copy.getW()),
    m_h(copy.getH())
{
    setScale(copy.getScale());
    setPosition(copy.getPosition());
}

//!
//! \brief Draw the GraphicElement on the associated RenderWindow
//! \param window RenderWindow where the GraphicElement will be drawn
//! \author TEAM Carambar de l'IUT
//! \date 10/03/2016
//! \version 1
//!
void GraphicElement::draw(sf::RenderWindow* window) const
{
    window->draw(*this);
}

void GraphicElement::setTransparency(int& transparencyLevel)
{
    setColor(sf::Color(255,255,255,transparencyLevel));
}

//!
//! \brief Resize the GraphicElement with the associated values
//! \param w GraphicElement's width wanted
//! \param h GraphicElement's height wanted
//! \author TEAM Carambar de l'IUT
//! \date 10/03/2016
//! \version 1
//!
void GraphicElement::resize(int w, int h)
{
    sf::FloatRect bb = getLocalBounds();
    float width_factor = w / bb.width;
    float height_factor = h / bb.height;
    setScale(width_factor, height_factor);
}

//!
//! \brief Get the GraphicalElement's height
//! \return GraphicalElement's height
//!
int GraphicElement::getH() const
{
    return m_h;
}

//!
//! \brief Get the GraphicElement's width
//! \return GraphicElement's width
//!
int GraphicElement::getW() const
{
    return m_w;
}

//!
//! \brief Get the GrahicElement's X position
//! \return GraphicElement's X position
//!
int GraphicElement::getX() const
{
    return m_x;
}

//!
//! \brief Get the GrahicElement's Y position
//! \return GraphicElement's Y position
//!
int GraphicElement::getY() const
{
    return m_y;
}

void GraphicElement::slideLeft(float s) {
    m_x -= s;
    setPosition(m_x,m_y);
}

//!
//! \brief Set GraphicElement's X and Y coordinates
//! \param x New X position of the GraphicElement
//! \param y New Y position of the GraphicElement
//!
void GraphicElement::replace(int x, int y) {
    m_x = x;
    m_y = y;
}
