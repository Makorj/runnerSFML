#ifndef ANIMATEDGRAPHICELEMENT_H
#define ANIMATEDGRAPHICELEMENT_H
#include <vector>
#include <graphicelement.h>
#include "SFML/Graphics.hpp"


class AnimatedGraphicElement
        : public GraphicElement
{
private:
    std::vector<sf::IntRect>m_clipRects;
    int m_currentClipRect;
    int m_nb_steps;
    int m_current_step;
public:
    AnimatedGraphicElement(const std::vector<sf::IntRect>& clipRects, sf::Texture &image, int x, int y, int w, int h);
    AnimatedGraphicElement(const AnimatedGraphicElement& copy);
    AnimatedGraphicElement() = default;
    void resize(int w, int h);
    void draw(sf::RenderWindow *window);
};

#endif // ANIMATEDGRAPHICELEMENT_H
