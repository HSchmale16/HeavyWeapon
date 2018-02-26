#include "Game.h"
#include <iostream>
using std::cout;
using std::endl;

Game::Game() {

}

void Game::step(float ms, const ControlState& cs) {
    if(paused)
        return;
    background.step(ms);
    if (cs.moveLeftPressed ^ cs.moveRightPressed) {
        if (cs.moveLeftPressed)
            player.move(ms, -1);
        else
            player.move(ms, 1);
    }
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    target.draw(player);
}

void Game::updatePlayerBounds() {
    playerBounds.x = windowSize.x * PLAYER_LOWER_X_BOUND;
    playerBounds.y = windowSize.x * PLAYER_UPPER_X_BOUND;
}

void Game::updateWindowSize(sf::Vector2u newSize) {
    windowSize = newSize;
    updatePlayerBounds();
    /// TODO: Notify children
    background.handleWindowSizeChange();
}