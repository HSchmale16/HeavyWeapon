#ifndef GAME_H_INC
#define GAME_H_INC

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"

class Game : sf::Drawable {
private:
    float forward_speed;
    Player player;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Game();

    void step(float ms, const ControlState& cs);
};


#endif // GAME_H_INC
