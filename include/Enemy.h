#ifndef ENEMY_H_INC
#define ENEMY_H_INC

#include "HealthEntity.h"

/**
 * The enemy abstract base class
 */
class Enemy : public HealthEntity {
public:
    virtual void update(float seconds) = 0;
};

#endif // ENEMY_H_INC