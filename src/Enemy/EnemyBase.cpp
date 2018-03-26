#include "Enemy/EnemyBase.h"

sf::FloatRect EnemyBase::getBounds() const {
    return shape.getGlobalBounds();
}

void EnemyBase::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape);
}

///TODO: Implement me
bool EnemyBase::hittestPoint(const sf::Vector2f& pos) const {
    const sf::FloatRect& bounds = this->getBounds();
    return false;
}