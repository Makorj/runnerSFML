#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H
#include <vector>
#include "SFML/Graphics.hpp"
class AnimatedGraphicElement
{
    std::vector<sf::IntRect>m_clipRects;
    int m_currentClipRect;
public:
    AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h);
    void draw(sf::RenderWindow *window);
};

#endif // ANIMATEDGRAPHICELEMENT_H
