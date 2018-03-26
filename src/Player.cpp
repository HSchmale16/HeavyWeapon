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
    float targetX = cs.targetPosition.x;
    float currentX = shape.getPosition().x;
    float delta = abs(targetX - currentX);
    if (delta > PLAYER_MOVE_THRESHOLD) {
        if(targetX > currentX) {
            move(time, 1);
        } else {
            move(time, -1);
        }
    }
    updateTurret(cs);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape);
    target.draw(turret);
}

sf::Vector2f Player::getBulletNormal() const {
    return turret.getNormal();
}

sf::Vector2f Player::getBulletSpawnLocation() const {
    return turret.getBulletSpawnLocation();
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
    float rotation = 180 / M_PI * atan2(delta.y, delta.x);
    if(rotation < PT_ROT_BOUND_LOWER || rotation > PT_ROT_BOUND_UPPER)
        shape.setRotation(rotation + PT_ROT_CORRECTION_FACTOR);
}

sf::Vector2f PlayerTurret::getNormal() const {
    float rot = M_PI / 180.f * (shape.getRotation() - PT_ROT_CORRECTION_FACTOR);
    float x = cos(rot), y = sin(rot);
    return sf::Vector2f(x, y);
}

sf::Vector2f PlayerTurret::getBulletSpawnLocation() const {
    sf::Vector2f push = (shape.getSize() / 2) * getNormal();
    return shape.getPosition() + push;
}