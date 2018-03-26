#include "Enemy/WW2Plane.h"
#include "Game.h"
#include "Utils.h"


WW2Plane::WW2Plane() : EnemyBase() {
    shape.setPosition(game.getRightOffscreenSpawnX(), 350);
    shape.setTexture(*getOrLoadTexture(SPRITESHEET_PATH));
}

void WW2Plane::update(float step) {
    shape.move(SPEED_PER_SEC * step, 0);
}