#ifndef GAME_H_INC
#define GAME_H_INC

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"
#include "Background/Background.h"

class Game : public sf::Drawable {
private:
    float forward_speed;
    Player player;
    Background background;
    bool paused = false;
    sf::Vector2i windowSize;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Game();

    void step(float ms, const ControlState& cs);

    bool getPaused() const {
        return paused;
    }

    void pause() { 
        paused = true;
    }

    void resume() {
        paused = false;
    }

    sf::Vector2i getWindowSize() const {
        return windowSize;
    }

    /**
     * Updates the window size, and notifys all game objects of the 
     * change.
     */
    void updateWindowSize(sf::Vector2i newSize);
};

extern Game game;

#endif // GAME_H_INC
