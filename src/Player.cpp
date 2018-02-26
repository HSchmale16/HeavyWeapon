#include "Player.h"

Player::Player() {
    shape.setFillColor(sf::Color::Cyan);
    shape.setSize(sf::Vector2f(30, 30));
    shape.setPosition(400, 550);
    
    handleWindowSizeChange();
}

void Player::move(float time, float multiplier) {
    sf::Vector2f pos = shape.getPosition();
    pos.x += time * move_speed * multiplier;
    shape.setPosition(pos);
}