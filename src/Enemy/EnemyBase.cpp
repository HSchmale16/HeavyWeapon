#include "Enemy/EnemyBase.h"

sf::FloatRect EnemyBase::getBounds() const {
    return shape.getGlobalBounds();
}

bool EnemyBase::hittestPoint(const sf::Vector2f& position) const {

}