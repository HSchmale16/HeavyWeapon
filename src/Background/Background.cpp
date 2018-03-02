#include "Background/Background.h"
#include "Game.h"

Background::Background() {
    handleWindowSizeChange();
    ground.setFillColor(sf::Color::Green);
}

void Background::step(float ms) {

}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(ground);
}

void Background::handleWindowSizeChange() {
    sf::Vector2u win_size = game.getWindowSize();

    ground.setPosition(0, win_size.y * .9);
    win_size.y *= .1;
    ground.setSize((sf::Vector2f)win_size);
}