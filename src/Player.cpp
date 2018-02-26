/**\file Player.cpp
 * \author Henry J Schmale
 * 
 * The Player implementation
 */

#include "Player.h"
#include "Game.h"

Player::Player() {
    shape.setFillColor(sf::Color::Cyan);
    shape.setSize(sf::Vector2f(30, 30));
    shape.setPosition(400, 550);
    
    handleWindowSizeChange();
}

void Player::move(float time, float multiplier) {
    sf::Vector2f pos = shape.getPosition();
    const sf::Vector2f& bounds = game.getPlayerXBounds();
    float delta = time * move_speed * multiplier;
    if ((delta < 0 && pos.x > bounds.x) || (delta > 0 && pos.x < bounds.y)) {
        pos.x += delta;
    }
    shape.setPosition(pos);
}