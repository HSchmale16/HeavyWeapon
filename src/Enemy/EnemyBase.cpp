#include "Enemy/EnemyBase.h"
#include "Utils.h"

sf::FloatRect EnemyBase::getBounds() const {
    return shape.getGlobalBounds();
}

void EnemyBase::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape);
}