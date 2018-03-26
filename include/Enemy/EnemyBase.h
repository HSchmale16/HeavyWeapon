#ifndef ENEMY_BASE_H_INC
#define ENEMY_BASE_H_INC

#include "HealthEntity.h"

/**
 * The enemy abstract base class.
 * Pretty much is pure virtual.
 */
class EnemyBase : public HealthEntity {
protected:
    sf::Sprite shape;

    virtual void draw(sf::RenderTarget& t, sf::RenderStates s) const;
public:
    virtual void update(float seconds) = 0;

    virtual sf::FloatRect getBounds() const;

    virtual bool hittestPoint(const sf::Vector2f& position) const;
};

#endif // ENEMY_BASE_H_INC