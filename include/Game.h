#ifndef GAME_H_INC
#define GAME_H_INC

/**\file Game.h
 * \author Henry J Schmale
 */

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"
#include "Background/Background.h"

/** The game state management class. This mangages all 
 * game state, and makes appropite calls to other classes.
 */
class Game : public sf::Drawable {
private:
    float forward_speed;
    Player player;
    Background background;
    bool paused = false;
    sf::Vector2u windowSize;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Game();
    
    /** Steps the game forward ms seconds. If the game is paused this has no effect.
     * \param cs Required to get the state to the player object.
     */
    void step(float ms, const ControlState& cs);

    bool getPaused() const {
        return paused;
    }

    /** Pause the game
     */
    void pause() { 
        paused = true;
    }

    /** Resume the game
     */
    void resume() {
        paused = false;
    }

    sf::Vector2u getWindowSize() const {
        return windowSize;
    }

    /**
     * Updates the window size, and notifys all game objects of the 
     * change. Should be called when ever the window is resized and
     * or the view changes.
     */
    void updateWindowSize(sf::Vector2u newSize);
};

extern Game game;

#endif // GAME_H_INC
