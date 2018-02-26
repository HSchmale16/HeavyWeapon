#ifndef GAME_ENTITY_H_INC
#define GAME_ENTITY_H_INC

#include <SFML/Graphics.hpp>

class GameEntity : public sf::Drawable {
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    void step(float ms);
};

#endif // GAME_ENTITY_H_INC