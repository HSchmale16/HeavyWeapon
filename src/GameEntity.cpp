#include "GameEntity.h"
#include <iostream>

void GameEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape);
}

void GameEntity::handleWindowSizeChange() {

}