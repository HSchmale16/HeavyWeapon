#ifndef HEALTH_ENTITY_H_INC
#define HEALTH_ENTITY_H_INC

#include <SFML/Graphics.hpp>

typedef float DamageValue;

struct DamageCalculation {
    bool hit = false;
    DamageValue amount;
};

/** When a player is killed. This is one because important reasons
 * relating to comparisons.
 */
const float KILLED_HEALTH_THRESHOLD = 1.f;

/** Defines an entity which has health
 */
class HealthEntity : public sf::Drawable {
private:
    float current_health;
    float max_health;
public:

    float getHealthPercent() const {
        return (float) current_health / max_health;
    }

    int getMaxHealth() const {
        return max_health;
    }

    int getCurrentHealth() const {
        return current_health;
    }

    float reset() {
        current_health = max_health;
    }

    bool getKilledState() const {
        return current_health < KILLED_HEALTH_THRESHOLD;
    }

    virtual sf::FloatRect getBounds() const = 0;
};

#endif // HEALTH_ENTITY_H_INC