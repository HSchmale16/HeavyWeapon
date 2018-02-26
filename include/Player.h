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

    sf::Vector2f getBulletSpawnLocation();

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
};

const float PLAYER_LOWER_X_BOUND = 0.1f;
const float PLAYER_UPPER_X_BOUND = 0.9f;

#endif // PLAYER_H_INC