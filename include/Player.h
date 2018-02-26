#ifndef PLAYER_H_INC
#define PLAYER_H_INC

/**\file Player.h
 * \author Henry J Schmale
 * 
 * The player class
 * 
 */

#include "HealthEntity.h"

/**
 * The controllable player entity. It's a tank.
 */
class Player : public HealthEntity {
private:
    float move_speed = 200;

    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Player();

    void move(float time, float multiplier);
};

const float PLAYER_LOWER_X_BOUND = 0.05;
const float PLAYER_UPPER_X_BOUND = 0.9;

#endif // PLAYER_H_INC