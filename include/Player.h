#ifndef PLAYER_H_INC
#define PLAYER_H_INC

/**\file Player.h
 * \author Henry J Schmale
 * 
 * The player class
 * 
 */

#include "HealthEntity.h"


class Player : public HealthEntity {
private:
    float move_speed = 200;

    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Player();

    void move(float time, float multiplier);
};


#endif // PLAYER_H_INC