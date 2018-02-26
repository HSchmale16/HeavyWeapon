#ifndef BACKGROUND_H_INC
#define BACKGROUND_H_INC

#include <SFML/Graphics.hpp>
#include <list>

class Background : public sf::Drawable {
private:
    // Base rate to move forward per second
    float rate_per_second;
    sf::RectangleShape ground;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Background();

    void step(float ms);
};

#endif // BACKGROUND_H_INC