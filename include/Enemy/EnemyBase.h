#ifndef ENEMY_BASE_H_INC
#define ENEMY_BASE_H_INC

#include "HealthEntity.h"

/**
 * The enemy abstract base class
 */
class EnemyBase : public HealthEntity {
public:
    virtual void update(float seconds) = 0;
};

#endif // ENEMY_BASE_H_INC