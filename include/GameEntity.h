#ifndef GAME_ENTITY_H_INC
#define GAME_ENTITY_H_INC

#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

class GameEntity : public sf::Drawable {
protected:
    sf::RectangleShape shape;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    void step(float ms);

    virtual void handleWindowSizeChange();
};

#endif // GAME_ENTITY_H_INC