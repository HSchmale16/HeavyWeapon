#include "Game.h"

Game::Game() {

}

void Game::step(float ms, const ControlState& cs) {
    if(paused)
        return;
    background.step(ms);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
}

void Game::updateWindowSize(sf::Vector2i newSize) {
    windowSize = newSize;
    /// TODO: Notify children
}