#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

Game::Game() 
: bulletPool(*this) {

}

void Game::step(float ms, const ControlState& cs) {
    if(paused)
        return;
    background.step(ms);
    player.step(ms, cs);
    bulletPool.step(ms,
        player.getBulletSpawnLocation(),
        player.getBulletNormal(),
        cs.shootPressed);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(player);
    target.draw(bulletPool);
}

void Game::updatePlayerBounds() {
    playerBounds.x = windowSize.x * PLAYER_LOWER_X_BOUND;
    playerBounds.y = windowSize.x * PLAYER_UPPER_X_BOUND;
}

void Game::updateWindowSize(sf::Vector2u newSize) {
    windowSize = newSize;
    updatePlayerBounds();
    background.handleWindowSizeChange();

    /// TODO: Notify children
}