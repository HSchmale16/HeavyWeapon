#ifndef HEALTH_ENTITY_H_INC
#define HEALTH_ENTITY_H_INC

#include "GameEntity.h"

class HealthEntity : public GameEntity {
private:
    float current_health;
    float max_health;
public:

    float getHealthPercent() {
        return (float) current_health / max_health;
    }

    int getMaxHealth() {
        return max_health;
    }

    int getCurrentHealth() {
        return current_health;
    }

    float reset() {
        current_health = max_health;
    }

};

#endif // HEALTH_ENTITY_H_INC