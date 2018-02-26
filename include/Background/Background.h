#ifndef BACKGROUND_H_INC
#define BACKGROUND_H_INC

/**\file Background.h
 * \author Henry J Schmale
 * 
 */

#include <SFML/Graphics.hpp>
#include <list>

/** The game background. This class manages adding entities to the background
 * and rendering the backgroud as appropite.
 */
class Background : public sf::Drawable {
private:
    // Base rate to move forward per second
    float rate_per_second;
    sf::RectangleShape ground;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Background();

    void step(float ms);

    void handleWindowSizeChange();
};

#endif // BACKGROUND_H_INC