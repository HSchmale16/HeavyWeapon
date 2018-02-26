/**\file Player.cpp
 * \author Henry J Schmale
 * 
 * The Player implementation
 */

#include "Player.h"
#include "Game.h"
#include "Utils.h"
#include <cmath>

Player::Player() {
    shape.setFillColor(sf::Color::Cyan);
    shape.setSize(sf::Vector2f(40, 40));
    shape.setPosition(400, 400);
    //shape.setTexture(getOrLoadTexture("resources/textures/TurretTest.png"));
    shape.setOrigin(sf::Vector2f(shape.getSize()) / 2);
    turret.setPosition(shape.getPosition());

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
    turret.setPosition(pos);
}

void Player::updateTurret(const ControlState& state) {
    turret.updateTarget(state.targetPosition);
}

void Player::step(float time, const ControlState& cs) {
    if (cs.moveLeftPressed ^ cs.moveRightPressed) {
        if (cs.moveLeftPressed)
            move(time, -1);
        else
            move(time, 1);
    }
    updateTurret(cs);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape);
    target.draw(turret);
}

//
// Player Turret Impl
//

PlayerTurret::PlayerTurret() {
    shape.setTexture(getOrLoadTexture("resources/textures/TurretTest.png"));
    shape.setSize(sf::Vector2f(30, 30));
    shape.setOrigin(shape.getSize() / 2);
}

void PlayerTurret::setPosition(const sf::Vector2f& pos) {
    shape.setPosition(pos);
}

void PlayerTurret::updateTarget(const sf::Vector2f& pos) {
    sf::Vector2f delta = pos - shape.getPosition();
    cout << delta.x << " " << delta.y << " " << pos.x << " " << pos.y << endl;
    shape.setRotation(180 / M_PI * atan2(delta.y, delta.x) + 90);
}
