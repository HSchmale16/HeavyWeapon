#ifndef GAME_H_INC
#define GAME_H_INC

/**\file Game.h
 * \author Henry J Schmale
 */

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"
#include "Background/Background.h"
#include "BulletPool.h"

class UIState {
public:
};

/** The game state management class. This mangages all 
 * game state, and makes appropite calls to other classes.
 */
class Game : public sf::Drawable {
private:
    float forward_speed;
    float enemySpawnX;
    Player player;
    Background background;
    BulletManager bulletPool;
    sf::Vector2u windowSize;
    sf::Vector2f playerBounds;
    bool paused = false;

    
    void updatePlayerBounds();

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

    /** Uses the window size to calculate how far the player can move on screen.
     */
    const sf::Vector2f& getPlayerXBounds() const {
        return playerBounds;
    }

    float getEnemySpawnX() const {
        return enemySpawnX;
    }
};

/** The global game state object. Probably not thread safe, but hey we 
 * aren't doing anything in threads
 */
extern Game game;

#endif // GAME_H_INC
