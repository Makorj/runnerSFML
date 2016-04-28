/*
Copyright (c) 2016 Florent VAIN, Thomas BLANC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*!
 * \file graphicelement.harderr
 * \brief GraphicElement header file
 */

#ifndef GRAPHICELEMENT_H
#define GRAPHICELEMENT_H

#include <SFML/Graphics.hpp>

//!
//! \brief Element drawable on the screen class.
//! Inherit from the sf::Sprite class from the SFML library.
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
