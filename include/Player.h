#ifndef PLAYER_H_INC
#define PLAYER_H_INC

/**\file Player.h
 * \author Henry J Schmale
 * 
 * The player class
 * 
 */

#include "HealthEntity.h"
#include "Utils.h"

class PlayerTurret : public sf::Drawable {
private:
    sf::RectangleShape shape;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(shape, states);
    }
public:
    PlayerTurret();

    sf::Vector2f getBulletSpawnLocation() const;
    sf::Vector2f getNormal() const;

    void updateTarget(const sf::Vector2f& target);

    void setPosition(const sf::Vector2f&);
};


/**
 * The controllable player entity. It's a tank.
 */
class Player : public HealthEntity {
private:
    const float move_speed = 200;
    PlayerTurret turret;


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Player();

    void step(float time, const ControlState& state);
    void move(float time, float multiplier);
    void updateTurret(const ControlState& state);

    sf::Vector2f getBulletSpawnLocation() const;
    sf::Vector2f getBulletNormal() const;
};

const float PLAYER_LOWER_X_BOUND = 0.1f;
const float PLAYER_UPPER_X_BOUND = 0.9f;
/// How far from the mouse pointer the player must be before attempting to fix.
const float PLAYER_MOVE_THRESHOLD = 5.f;

/// Player Turret Rotation Correction Factor because the sprite is 
/// off by 90 degrees
const float PT_ROT_CORRECTION_FACTOR = 90;

/// How far the player turret can rotate to the right
const float PT_ROT_BOUND_LOWER = 0;
/// How far the player turret can rotate to the left
const float PT_ROT_BOUND_UPPER = 180;

#endif // PLAYER_H_INC